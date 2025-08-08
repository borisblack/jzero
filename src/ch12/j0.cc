#include <string>
#include <vector>
#include <list>
#include <map>
#include <memory>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#include "j0gram.tab.h"
#include "j0.h"
#include "serial.h"
#include "byc.h"
#include "util.h"

using namespace std;

static int yycolno;
static int count;
static char *yyfilename;
static map<string, int> labelTable;
static bool methodAddrPushed = false;

static void fillBcode(list<Byc*> &bcode, vector<shared_ptr<Tac>> &icode);
static Byc *bgen(int op, shared_ptr<Address> address);
static void genBytecode(list<Byc*> &bcode);
static int calculateFio();
static char *rawString(char *dest, int i, int len);
static uint writeStringArea(char *dest);
static uint writeGlobalArea(char *dest);
static uint writeInstructions(char *dest, list<Byc*> &bcode);

SymTab *global_st = NULL, *string_st = NULL;

int main(int argc, char* argv[]) {
  print_pid();

  if (argc == 1) {
    printf("usage: j0 [filename]\n");
  }

  yyfilename = argv[1];
  if(!(yyin = fopen(yyfilename, "r"))) {
    printf("cannot open file: %s\n", yyfilename);
    exit(1);
  }

  yylval.t = NULL;
  yylineno = yycolno = 1;
  count = 0;
  int i = yyparse();

  delete yylval.t;
  delete string_st;
  fclose(yyin);

  if (i == 0)
    printf("no errors, %d tokens parsed\n", count);
}

void yyerror(const char *s) {
  fprintf(stderr, "line %d, column %d, lexeme \"%s\": %s\n", yylineno, yycolno, yytext, s);
  exit(1);
}

void lexErr(const char *s) {
  printf("%s: line %d: %s\n", s, yylineno, yytext);
  exit(1);
}

int scan(int cat) {
  Token *tok = new Token(cat, yytext, yylineno, yycolno);
  Tree *tree = new Tree("token", cat, tok);

  yylval.t = tree;
  yycolno += strlen(yytext);
  count++;

  return cat;
}

void newline() {
  yylineno++;
  yycolno = 1;
}

void whitespace() {
  yycolno += strlen(yytext);
}

void comment() {
  int len = strlen(yytext);
  for (int i = 0; i < len; i++) {
    if (yytext[i] == '\n') {
        yylineno++;
        yycolno = 1;
    } else {
        yycolno++;
    }
  }
}

short ord(const char* s) {
  return (short)s[0];
}

Tree *node(const char *sym, int rule, int nkids, ...) {
  va_list ap;
  va_start(ap, nkids);

  Tree **kids = (Tree**)calloc(nkids, sizeof(Tree*));
  for (int i = 0; i<nkids; i++) {
    kids[i] = va_arg(ap, Tree*);
  }
  
  Tree *tree = new Tree(sym, rule, nkids, kids);

  va_end(ap);

  return tree;
}

void calcType(Tree *tree) {
  tree->kids[0]->calcType();
  tree->kids[1]->assignType(tree->kids[0]->typ);
}

void printRoot(Tree *root) {
  // tree_Print(root, 0);

  char graphFilename[strlen(yyfilename) + 5];
  sprintf(graphFilename, "%s.dot", yyfilename);

  FILE *f;
  if(!(f = fopen(graphFilename, "w"))) {
    printf("cannot open graph file: %s\n", graphFilename);
    exit(1);
  }
  fprintf(f, "digraph {\n");
  root->printGraph(f);
  fprintf(f, "}\n");
  fclose(f);
}

void semantic(Tree *root) {
  SymTab *System_st, *out_st;

  string_st = new SymTab(STRINGS_SCOPE);
  global_st = new SymTab(GLOBAL_SCOPE);
  System_st = new SymTab(CLASS_SCOPE);
  out_st = new SymTab(CLASS_SCOPE);

  vector<shared_ptr<TypeInfo>> printlnParams = { make_shared<StringType>() };
  out_st->insertEntry("println", false, NULL, make_shared<MethodType>(make_shared<VoidType>(), &printlnParams));
  System_st->insertEntry("out", false, out_st, make_shared<ClassType>("PrintStream", out_st));
  global_st->insertEntry("System", false, System_st, make_shared<ClassType>("System", System_st));

  root->mkSymTables(global_st);
  root->populateSymTables();
  root->checkSymTables();
  // global_st->print(0);
  root->mkCls();
  root->checkType(false);
}

void gencode(Tree *root) {
  root->genFirst();
  root->genFollow();
  root->genTargets();
  root->genCode();
  // root->printIcode();
  list<Byc*> bcode;
  fillBcode(bcode, root->icode);
  genBytecode(bcode);
}

static void fillBcode(list<Byc*> &bcode, vector<shared_ptr<Tac>> &icode) {
  shared_ptr<Tac> instr, callinstr;
  char tmpStr[25];
  for(size_t i=0; i<icode.size(); i++) {
    instr = icode[i];
    if (!strcmp("ADD", instr->op)) {
      bcode.push_back(bgen(PUSH, instr->op2));
      bcode.push_back(bgen(PUSH, instr->op3));
      bcode.push_back(bgen(ADD, NULL));
      bcode.push_back(bgen(POP, instr->op1));
    }
    else if (!strcmp("SUB", instr->op) || !strcmp("NEG", instr->op)) {
      bcode.push_back(bgen(PUSH, instr->op2));
      bcode.push_back(bgen(NEG, NULL));
      bcode.push_back(bgen(POP, instr->op1));
    }
    else if (!strcmp("ASN", instr->op)) {
      bcode.push_back(bgen(PUSH, instr->op2));
      bcode.push_back(bgen(POP, instr->op1));
    }
    else if (!strcmp("ADDR", instr->op)) {
      bcode.push_back(bgen(LOAD, instr->op1));
    }
    else if (!strcmp("LCON", instr->op)) {
      bcode.push_back(bgen(LOAD, instr->op2));
      bcode.push_back(bgen(POP, instr->op1));
    }
    else if (!strcmp("SCON", instr->op)) {
      bcode.push_back(bgen(STORE, instr->op2));
      bcode.push_back(bgen(POP, instr->op1));
    }
    else if (!strcmp("GOTO", instr->op)) {
      bcode.push_back(bgen(GOTO, instr->op1));
    }
    else if (!strcmp("BLT", instr->op)) {
      bcode.push_back(bgen(PUSH, instr->op2));
      bcode.push_back(bgen(PUSH, instr->op3));
      bcode.push_back(bgen(LT, NULL));
      bcode.push_back(bgen(BIF, instr->op1));
    }
    else if (!strcmp("PARM", instr->op)) {
      if (!methodAddrPushed) {
        for (size_t j=i+1; j<icode.size(); j++) {
          callinstr = icode[j];
          if (!strcmp("CALL", callinstr->op)) {
            if (!strcmp("PrintStream__println:0", callinstr->op1->str(tmpStr))) {
              bcode.push_back(bgen(PUSH, make_shared<Address>("imm", -1)));
            } else {
              bcode.push_back(bgen(PUSH, callinstr->op1));
            }
            break;
          }
          methodAddrPushed = true;
        }
      }
      bcode.push_back(bgen(PUSH, instr->op1));
    } else if (!strcmp("CALL", instr->op)) {
      bcode.push_back(bgen(CALL, instr->op2));
      methodAddrPushed = false;
    } else if (!strcmp("RET", instr->op) || !strcmp("RETURN", instr->op)) {
      bcode.push_back(bgen(RET, instr->op1));
    } else if (!strcmp("proc", instr->op)) {
      // record address
      labelTable[instr->op1->region] = bcode.size() * 8;
    } else if (!strcmp("end", instr->op) || !strcmp(".code", instr->op) || !strcmp(".global", instr->op) || !strcmp(".string", instr->op)) {
      //
    } else if (!strcmp("LAB", instr->op)) {
      sprintf(tmpStr, "L%u", instr->op1->offset);
      labelTable[tmpStr] = bcode.size() * 8;
    } else if (!strcmp("string", instr->op) || !strcmp("global", instr->op)) {
      //
    } else if (!strcmp("FIELD", instr->op)) {
      bcode.push_back(bgen(PUSH, instr->op2));
      bcode.push_back(bgen(POP, instr->op1));
    } else {
      fprintf(stderr, "What is %s\n", instr->op);
      exit(1);
    }
  }
}

static Byc *bgen(int op, shared_ptr<Address> address) {
  Byc *b = new Byc(op, address ? address.get() : nullptr);
  return b;
}

static void genBytecode(list<Byc*> &bcode) {
  char code[800000];
  char *pCode = code;
  map<string, int>::iterator it;
  int fio;
  int entrypt;
  FILE *f;
  char tmpStr[25];
  int len = strlen(yyfilename);
  char outfilename[len-1]; // minus .java plus .j0 plus 1
  strncpy(outfilename, yyfilename, len-5);  // minus .java
  outfilename[len-5] = '\0';
  strcat(outfilename, ".j0");

  memcpy(pCode,"Jzero!!\0", 8);               // word 0, magic word
  pCode += 8;

  memcpy(pCode,"1.0\0\0\0\0\0", 8);           // word 1, version #
  pCode += 8;

  // write first instruction offset
  fio = calculateFio();
  memcpy(pCode, "\0\0", 2);
  pCode += 2;

  memcpy(pCode, rawString(tmpStr, fio, 6), 6);
  pCode += 6;

  pCode += writeStringArea(pCode);
  pCode += writeGlobalArea(pCode);

  // bootstrap instructions: push addr of main, push dummy self, call 0, and halt
  entrypt = fio*8+32;
  it = labelTable.find("main");
  if (it == labelTable.end()) {
    fprintf(stderr, "main() not found\n");
    exit(1);
  }
  entrypt += labelTable["main"];
  memcpy(pCode, "\11\2", 2); // PUSH IMM (func entry pt) fio*8+24
  pCode += 2;

  memcpy(pCode, rawString(tmpStr, entrypt, 6), 6); // PUSH IMM (func entry pt) fio*8+24
  pCode += 6;

  memcpy(pCode, "\11\2\0\0\0\0\0\0", 8);            // PUSH 0 (null self)
  pCode += 8;

  memcpy(pCode, "\13\2\0\0\0\0\0\0", 8);            // call 0
  pCode += 8;

  memcpy(pCode, "\1\0\0\0\0\0\0\0", 8);             // halt
  pCode += 8;

  pCode += writeInstructions(pCode, bcode);

  f = fopen(outfilename, "wb");
  if (!f) {
    fprintf(stderr, "cannot open file %s\n", outfilename);
    exit(1);
  }
  fwrite(code, pCode-code, 1, f);
  fclose(f);
}

static int calculateFio() {
  return 3 + string_st->count/8 + global_st->count/8;
}

static char *rawString(char *dest, int i, int len) {
  for(int j=0; j<len; j++) {
    dest[j] = (char)(i & 0xFF);
    i = i >> 8;
  }
  dest[len] = '\0';

  return dest;
}

static uint writeStringArea(char *dest) {
  char *pCode = dest;
  map<string, SymTabEntry*>::iterator it;
  string s;
  for (it = string_st->t.begin(); it != string_st->t.end(); it++) {
    s = it->first;
    // should fully-binarize (de-escape) string here
    // for now, just strip double quotes, replace with NULs
    s = s.substr(1, s.length()-2) + "\0\0";
    int len = s.length();
    while (len > 0) {
      if (len < 9) {
        memcpy(pCode, s.data(), len);
        pCode += len;
        if (len < 8) {
          for(int j = 0; j<8-len; j++)
            memcpy(pCode++, "\0", 1);
        }
      } else {
        memcpy(pCode, s.substr(0, 8).data(), 8);
        pCode += 8;
        s = s.substr(8);
      }
      len -= 8;
    }
  }

  return pCode - dest;
}

static uint writeGlobalArea(char *dest) {
  char *pCode = dest;
  for(uint i=0; i<global_st->count; i++)
    memcpy(pCode++, "\0", 1);

  return pCode - dest;
}

static uint writeInstructions(char *dest, list<Byc*> &bcode) {
  char *pCode = dest;
  list<Byc*>::iterator it;
  Byc* b;
  for(it = bcode.begin(); it != bcode.end(); it++) {
    b = *it;
    switch(b->op) {
      case CODE:
      case GLOBAL:
      case LABEL:
      case PROC:
      case STR:
      case END:
        break;
      default: {
        pCode += b->printb(pCode);
      }
    }
  }

  return pCode - dest;
}
