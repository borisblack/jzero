#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "j0gram.tab.h"
#include "tree.h"
#include "serial.h"

const char *token_Name(int t);

static char *escape(char *dest, const char *src);

extern SymTab *global_st;
extern SymTab *string_st;

Token::Token(int cat, const char *text, int lineno, int colno) {
  id = serial_GetId();
  this->cat = cat;
  this->text = strdup(text);
  this->lineno = lineno;
  this->colno = colno;
  typ = catType();
}

Token::~Token() {
  free(text);
  text = NULL;
}

const char *Token::name() {
  return token_Name(cat);
}

shared_ptr<TypeInfo> Token::catType() {
  switch (cat) {
    case VOID:
      return make_shared<VoidType>();
    case INT:
    case INTLIT:
      return make_shared<IntType>();
    case DOUBLE:
    case DOUBLELIT:
      return make_shared<DoubleType>();
    case STRING:
    case STRINGLIT:
      return make_shared<StringType>();
    case BOOLEAN:
    case BOOLLIT:
      return make_shared<BoolType>();
    case NULLVAL:
      return make_shared<NullType>();
    case '=':
    case '+':
    case '-':
      return make_shared<NaType>();
    default:
      return NULL;
  }
}

Tree::Tree(const char *sym, int rule, Token *tok) {
  id = serial_GetId();
  this->sym = sym;
  this->rule = rule;
  this->tok = tok;
  
  if (tok)
    typ = tok->typ;
}

Tree::Tree(const char *sym, int rule, int nkids, Tree **kids) {
  id = serial_GetId();
  this->sym = sym;
  this->rule = rule;
  this->nkids = nkids;
  this->kids = kids;
}

Tree::~Tree() {
  for (int i=0; i<nkids; i++) {
    delete kids[i];
  }
  free(kids);
  kids = NULL;
  nkids = 0;

  delete tok;
  tok = NULL;

  if (symTab) {
    delete symTab;
    symTab = NULL;
  }

  icode.clear();
  ncode = 0;
}

shared_ptr<TypeInfo> Tree::tokenType() {
  SymTabEntry *rv;

  if (tok->typ)
    return tok->typ;

  if (tok->cat == IDENTIFIER && (rv = symTab->lookupEntry(tok->text)))
    return tok->typ = rv->typ;
  
  printf("semantic error: cannot check the type of %s\n", tok->text);
  exit(1);

  return NULL;
}

void Tree::print(int level) {
  int i;
  for(i=0; i<level; i++)
    printf(" ");

  if (tok) {
    printf("%d   %s (%d): %d\n", id, tok->text, tok->cat, tok->lineno);
  } else {
    printf("%d   %s (%d): %d\n", id, sym, rule, nkids);
  }

  for(i=0; i<nkids; i++)
    kids[i]->print(level+1);
}

void Tree::printGraph(FILE *f) {
  int i;
  if (tok) {
    printLeaf(f);
    return;
  }

  // from here on out, we know we are not a leaf
  printBranch(f);

  for(i=0; i<nkids; i++) {
    Tree *child = kids[i];
    fprintf(f, "N%d -> N%d;\n", id, child->id);
    child->printGraph(f);
  }
}

void Tree::calcIsConst() {
  for(int i=0; i<nkids; i++)
    kids[i]->calcIsConst();

  if (!strcmp(sym, "INTLIT") || !strcmp(sym, "DOUBLELIT") || !strcmp(sym, "STRINGLIT") || !strcmp(sym, "BOOLFALSE") || !strcmp(sym, "BOOLTRUE")) {
    isConst = true;
  } else if (!strcmp(sym, "UnaryExpr")) {
    isConst = kids[1]->isConst;
  } else if (!strcmp(sym, "RelExpr")) {
    isConst = kids[0]->isConst && kids[2]->isConst;
  } else if (!strcmp(sym, "CondOrExpr") || !strcmp(sym, "CondAndExpr") || !strcmp(sym, "EqExpr") || !strcmp(sym, "MULEXPR") || !strcmp(sym, "ADDEXPR")) {
    isConst = kids[0]->isConst && kids[1]->isConst;
  } else {
    isConst = false;
  }
}

void Tree::mkSymTables(SymTab *stab) {
  symTab = stab;
  if (strcmp("ClassDecl", sym) == 0) {
    stab = new SymTab(CLASS_SCOPE, stab);
  } else if (strcmp("MethodDecl", sym) == 0) {
    stab = new SymTab(METHOD_SCOPE, stab);
  }

  for (int i=0; i<nkids; i++)
    kids[i]->mkSymTables(stab);
}

void Tree::populateSymTables() {
  if (strcmp("ClassDecl", sym) == 0) {
    symTab->insertEntry(
      kids[0]->tok->text,
      false,
      kids[0]->symTab,
      NULL
    );
  } else if (strcmp("FieldDecl", sym) == 0 || strcmp("LocalVarDecl", sym) == 0) {
    Tree *k = kids[1];
    while (strcmp("VarDecls", k->sym) == 0) {
        insertVardeclarator(k->kids[1]);
        k = k->kids[0];
    }
    insertVardeclarator(k);
    return;
  } else if (strcmp("MethodDecl", sym) == 0) {
    char *s = kids[0]->kids[1]->kids[0]->tok->text;
    symTab->insertEntry(
      s,
      false,
      kids[0]->symTab,
      kids[0]->kids[1]->typ
    );

    kids[0]->symTab->insertEntry(
      "return",
      false,
      NULL,
      kids[0]->kids[0]->typ
    );
  } else if (strcmp("FormalParm", sym) == 0) {
    insertVardeclarator(kids[1]);
    return;
  }

  for(int i=0; i<nkids; i++) {
      Tree *k = kids[i];
      k->populateSymTables();
  }
}

void Tree::checkSymTables() {
  checkCodeblocks();
}

void Tree::calcType() {
  for(int i=0; i<nkids; i++)
    kids[i]->calcType();

  if (!strcmp("FieldDecl", sym)) {
    typ = kids[0]->typ;
    return;
  } else if (!strcmp("token", sym)) {
    if ( (typ = tok->typ) )
      return;

    switch (tok->cat) {
      case IDENTIFIER:
        if (symTab) {
          SymTabEntry *rv = symTab->lookupEntry(tok->text);
          if (rv && (typ = rv->typ))
            return;
        }
        typ = make_shared<ClassType>(tok->text);
        return;
      default:
        printf("semantic error: can't grok the type of %s cat %d\n", tok->text, tok->cat);
        exit(1);
    }
  } else {
    printf("semantic error: don't know how to calctype %s\n", sym);
    exit(1);
  }
}

void Tree::assignType(shared_ptr<TypeInfo> typeInfo) {
  typ = typeInfo;

  if (!strcmp("VarDeclarator", sym)) {
    kids[0]->assignType(make_shared<ArrayType>(typeInfo));
    return;
  } else if (!strcmp("MethodDeclarator", sym)) {
    vector<shared_ptr<TypeInfo>> *params;
    if (kids[1]) {
      params = kids[1]->mksig();
    } else {
      params = new vector<shared_ptr<TypeInfo>>();
      params->push_back(make_shared<NaType>());
    }
    
    kids[0]->typ = typ = make_shared<MethodType>(typeInfo, params);
    return;
  } else if (!strcmp("token", sym)) {
    if (tok->cat == IDENTIFIER) {
      return;
    } else {
      printf("semantic error: eh? %d", tok->cat);
      exit(1);
    }
  } else {
    printf("semantic error: don't know how to assign type %s\n", sym);
    exit(1);
  }

  for(int i=0; i<nkids; i++)
    kids[i]->assignType(typeInfo);
}

void Tree::mkCls() {
  SymTabEntry *rv;
  if (!strcmp("ClassDecl", sym)) {
    rv = symTab->lookupEntry(kids[0]->tok->text);
    rv->typ = rv->st->mkCls(kids[0]->tok->text);
  } else {
    for(int i = 0; i<nkids; i++) {
      if (kids[i]->nkids > 0)
        kids[i]->mkCls();
    }
  }
}

void Tree::checkType(bool inCodeBlock) {
  if (checkKids(inCodeBlock))
    return;

  if (!inCodeBlock)
    return;

  if (!strcmp("Assignment", sym)) {
    typ = checkTypes(kids[0]->typ, kids[2]->typ);
  } else if (!strcmp("AddExpr", sym)) {
    typ = checkTypes(kids[0]->typ, kids[1]->typ);
  } else if (!strcmp("RelExpr", sym)) {
    typ = checkTypes(kids[0]->typ, kids[2]->typ);
  } else if (!strcmp("ArgList", sym) || !strcmp("Block", sym) || !strcmp("BlockStmts", sym)) {
    typ = NULL;
  } else if (!strcmp("MethodCall", sym)) {
    if (rule == 1290) {
      SymTabEntry *rve;
      MethodType *rv;
      if (!strcmp("QualifiedName", kids[0]->sym)){
        rv = (MethodType*)kids[0]->dequalify().get();
        cksig(rv);
      } else {
        if (strcmp("token", kids[0]->sym)) { // if not a token
          printf("semantic error: can't check type of %s\n", kids[0]->sym);
          exit(1);
        }

        if (kids[0]->tok->cat == IDENTIFIER) {
          printf("checking the type of a call to %s\n", kids[0]->tok->text);
          if ( (rve = symTab->lookupEntry(kids[0]->tok->text)) ) {
            if (rve->typ->basetype != METHOD_TYPE) {
              printf("semantic error: method expected, got %s\n", rve->typ->str());
              exit(1);
            }
            rv = (MethodType*)rve->typ.get();
            cksig(rv);
          }
        } else {
          printf("semantic error: can't typecheck token %d\n", kids[0]->tok->cat);
          exit(1);
        }
      }
    } else {
      printf("semantic error: Jzero does not handle complex calls\n");
      exit(1);
    }
  } else if (!strcmp("QualifiedName", sym)) {
    if (kids[0]->typ->basetype == CLASS_TYPE) {
      ClassType *ct = (ClassType*)kids[0]->typ.get();
      typ = ct->st->lookupEntry(kids[1]->tok->text)->typ;
    } else if (kids[0]->typ->basetype == ARRAY_TYPE) {
      typ = make_shared<IntType>();
    } else {
      printf("semantic error: illegal . on %s\n", kids[0]->typ->str());
      exit(1);
    }
  } else if (!strcmp("InstanceCreation", sym)) {
    SymTabEntry *rv;
    if (!(rv = symTab->lookupEntry(kids[0]->tok->text))) {
      printf("semantic error: unknown type %s\n", kids[0]->tok->text);
      exit(1);
    }

    if (rv->typ) {
      typ = rv->typ;
    } else {
      printf("semantic error: %s has unknown type\n", kids[0]->tok->text);
      exit(1);
    }
  } else if (!strcmp("ArrayCreation", sym)) {
    typ = make_shared<ArrayType>(kids[0]->typ);
  } else if (!strcmp("ArrayAccess", sym)) {
    if (kids[0]->typ->basetype == ARRAY_TYPE) {
      if (kids[1]->typ->basetype == INT_TYPE) {
        typ = ((ArrayType*)kids[0]->typ.get())->elementType;
      } else {
        printf("semantic error: subscripting array with %s\n", kids[1]->typ->str());
        exit(1);
      }
    } else {
      printf("semantic error: illegal subscript on type %s\n", kids[0]->typ->str());
      exit(1);
    }
  } else if (!strcmp("ReturnStmt", sym)) {
    SymTabEntry *ste;
    if (!(ste = symTab->lookupEntry("return"))) {
      printf("semantic error: stab did not find a returntype\n");
      exit(1);
    }

    shared_ptr<TypeInfo> rt = ste->typ;
    if (kids[0]->typ) {
      typ = checkTypes(rt, kids[0]->typ);
    } else { // return; check that return type is void
      if (rt->basetype != VOID_TYPE) {
        printf("semantic error: void return from non-void method\n");
        exit(1);
      }
      typ = rt;
    }
  } else if (!strcmp("token", sym)) {
    typ = tokenType();
  } else if (!strcmp("IfThenStmt", sym) || !strcmp("WhileStmt", sym)) {
    return; // no checks for j0 statements
  } else {
    printf("semantic error: cannot check type of %s\n", sym);
    exit(1);
  }
}

void Tree::genFirst() {
  for(int i=0; i<nkids; i++)
    kids[i]->genFirst();

  if (!strcmp("UnaryExpr", sym)) {
    if (kids[1]->first)
      first = kids[1]->first;
    else
      first = genLabel();
  } else if (!strcmp("AddExpr", sym) || !strcmp("MulExpr", sym) || !strcmp("RelExpr", sym)) {
    if (kids[0]->first)
      first = kids[0]->first;
    else if (kids[1]->first)
      first = kids[1]->first;
    else
      first = genLabel();
  } else if (!strcmp("Block", sym) || !strcmp("WhileStmt", sym)) {
    if (kids[0]->first)
      first = kids[0]->first;
    else
      first = genLabel();
  } else if (!strcmp("BlockStmts", sym)) {
    if (!kids[1]->first)
      kids[1]->first = genLabel();

    if (kids[0]->first)
      first = kids[0]->first;
    else
      first = kids[1]->first;
  }
  // ...
  else {
    for(int i=0; i<nkids; i++) {
      Tree *kid = kids[i];
      if (kid->first) {
        first = kid->first;
        break;
      }
    }
  }
}

void Tree::genFollow() {
  if (!strcmp("MethodDecl", sym)) {
    kids[1]->follow = follow = genLabel();
  } else if (!strcmp("BlockStmts", sym)) {
    kids[0]->follow = kids[1]->first;
    kids[1]->follow = follow;
  } else if (!strcmp("Block", sym)) {
    kids[0]->follow = follow;
  }
  // ...

  for(int i=0; i<nkids; i++) {
    kids[i]->genFollow();
  }
}

void Tree::genTargets() {
  if (!strcmp("IfThenStmt", sym) || !strcmp("WhileStmt", sym)) {
    kids[0]->onTrue = kids[1]->first;
    kids[0]->onFalse = follow;
  } else if (!strcmp("CondAndExpr", sym)) {
    kids[0]->onTrue = kids[1]->first;
    kids[0]->onFalse = onFalse;
    kids[1]->onTrue = onTrue;
    kids[1]->onFalse = onFalse;
  }
  // ...

  for(int i=0; i<nkids; i++) {
    kids[i]->genTargets();
  }
}

void Tree::genCode() {
  for(int i=0; i<nkids; i++) {
    kids[i]->genCode();
  }

  if (!strcmp("ClassDecl", sym)) {
    genClassDecl();
  } else if (!strcmp("AddExpr", sym)) {
    genAddExpr();
  } else if (!strcmp("MulExpr", sym)) {
    genMulExpr();
  } else if (!strcmp("RelExpr", sym)) {
    genRelExpr();
  } else if (!strcmp("WhileStmt", sym)) {
    genWhileStmt();
  } else if (!strcmp("IfThenStmt", sym)) {
    genIfThenStmt();
  } else if (!strcmp("Assignment", sym)) {
    genAssignment();
  } else if (!strcmp("MethodCall", sym)) {
    genMethodCall();
  } else if (!strcmp("MethodDecl", sym)) {
    genMethodDecl();
  } else if (!strcmp("QualifiedName", sym)) {
    genQualifiedName();
  }
  // ...
  else if (!strcmp("token", sym)) {
    genToken();
  } else {
    for (int i=0; i<nkids; i++) {
      copyIcodeFrom(kids[i]);
    }
  }
}

void Tree::printIcode() {
  vector<shared_ptr<Tac>>::iterator it = icode.begin();
  shared_ptr<Tac> tac;
  while (it != icode.end()) {
    tac = *it;
    tac->print();
    it++;
  }
}

void Tree::printLeaf(FILE *f) {
  const char *s = tok->name();
  printBranch(f);
  fprintf(f, "N%d [shape=box style=dotted label=\" %s \\n ", id, s);

  char escapedText[strlen(tok->text)+3];
  fprintf(f, "text = %s \\l lineno = %d \\l\"];\n", escape(escapedText, tok->text), tok->lineno);
}

void Tree::printBranch(FILE *f) {
  fprintf(f, "N%d ", id);

  int prettyNameLen = tok ? (strlen(tok->text)+10) : (strlen(sym)+3);
  char prettyName[prettyNameLen];
  fprintf(f, "[shape=box label=\"%s", prettyPrintName(prettyName));

  if (tok)
    fprintf(f, "struct token* leaf %d", tok->id);

  fprintf(f, "\"];\n");
}

char *Tree::prettyPrintName(char *dest) {
  if (tok) {
    char escapedText[strlen(tok->text)+3];
    sprintf(dest, "%s:%d", escape(escapedText, tok->text), tok->cat);
  } else {
    sprintf(dest, "%s#%d", sym, rule%10);
  }

  return dest;
}

void Tree::insertVardeclarator(Tree *vd) {
  if (vd->tok)
    symTab->insertEntry(vd->tok->text, false, NULL, vd->typ);
  else
    insertVardeclarator(vd->kids[0]);
}

void Tree::checkCodeblocks() {
  Tree *k;
  if (strcmp("MethodDecl", sym) == 0) {
    kids[1]->checkBlock();
  } else {
    for(int i=0; i<nkids; i++){
      k = kids[i];
      if (k->nkids>0)
        k->checkCodeblocks();
    }
  }
}

void Tree::checkBlock() {
  if (strcmp("IDENTIFIER", sym) == 0) {
    if (!symTab->lookupEntry(sym)) {
      printf("semantic error: undeclared variable %s\n", tok->text);
      exit(1);
    }
  } else if (strcmp("FieldAccess", sym) == 0 || strcmp("QualifiedName", sym) == 0) {
    kids[0]->checkBlock();
  } else if (strcmp("MethodCall", sym) == 0) {
    kids[0]->checkBlock();
    if (rule == 1290)
      kids[1]->checkBlock();
    else
      kids[2]->checkBlock();
  } else if (strcmp("LocalVarDecl", sym) == 0) {
    return;
  } else {
    for(int i=0; i<nkids; i++)
      kids[i]->checkBlock();
  }
}

bool Tree::checkKids(bool inCodeBlock) {
  if (!strcmp("MethodDecl", sym)) {
    kids[1]->checkType(true);
    return true;
  } else if (!strcmp("LocalVarDecl", sym)) {
    kids[1]->checkType(false);
    return true;
  } else if (!strcmp("FieldAccess", sym)) {
    kids[0]->checkType(inCodeBlock);
    return true;
  } else if (!strcmp("QualifiedName", sym)) {
    kids[0]->checkType(inCodeBlock);
  } else if (!strcmp("RelExpr", sym)) {
    kids[0]->checkType(inCodeBlock);
    kids[2]->checkType(inCodeBlock);
  } else {
    for (int i=0; i<nkids; i++) {
      kids[i]->checkType(inCodeBlock);
    }
  }

  return false;
}

shared_ptr<TypeInfo> Tree::checkTypes(shared_ptr<TypeInfo> op1, shared_ptr<TypeInfo> op2) {
  const char *op = getOp();
  if (!strcmp("param", op) || !strcmp("return", op) || !strcmp("=", op) || !strcmp("+", op) || !strcmp("-", op)) {
    Tree *tk;
    if ( (tk = findToken()) ) {
      // printf("line %d: ", tk->tok->lineno);
    }

    if (op1->basetype == op2->basetype && (op1->basetype == INT_TYPE || op1->basetype == DOUBLE_TYPE || op1->basetype == STRING_TYPE)) {
      // printf("typecheck %s on a %s and a %s -> OK\n", op, op2->str(), op1->str());
      return op1;
    }
    else if (
      op1->basetype == ARRAY_TYPE && op2->basetype == ARRAY_TYPE && !strcmp("=", op) &&
      this->checkTypes(((ArrayType*)op1.get())->elementType, ((ArrayType*)op2.get())->elementType)
    ) {
      return op1;
    }
    else if (op1->basetype == op2->basetype && !strcmp("=", op)) {
      // printf("typecheck %s on a %s and a %s -> OK\n", op, op1->str(), op2->str());
      return op1;
    }
    else {
      if (tk)
        printf("line %d: ", tk->tok->lineno);

      printf("semantic error: typecheck %s on a %s and a %s -> FAIL\n", op, op2->str(), op1->str());
      exit(1);
    }
  }
  else if (!strcmp("<", op) || !strcmp(">", op)) {
    if (op1->basetype == op2->basetype && (op1->basetype == INT_TYPE || op1->basetype == DOUBLE_TYPE)) {
      return shared_ptr<BoolType>();
    }
  }
  else {
    printf("semantic error: don't know how to check %s\n", op);
    exit(1);
  }

  return NULL;
}

const char *Tree::getOp() {
  if (!strcmp("ReturnStmt", sym)) {
    return "return";
  } else if (!strcmp("MethodCall", sym)) {
    return "param";
  } else if (!strcmp("Assignment", sym)) {
    return "=";
  } else if (!strcmp("AddExpr", sym)) {
    return rule == 1320 ? "+" : "-";
  } else if (!strcmp("RelExpr", sym)) {
    if (!strcmp("token", kids[1]->sym))
      return kids[1]->tok->text;
  }

  return NULL;
}

Tree *Tree::findToken() {
  Tree *rv;
  if (!strcmp("token", sym))
    return this;

  for (int i=0; i<nkids; i++) {
    if ( (rv = kids[i]->findToken()) )
      return rv;
  }

  return NULL;
}

shared_ptr<TypeInfo> Tree::dequalify() {
  TypeInfo *rv = NULL;
  SymTabEntry *ste;
  if (!strcmp("QualifiedName", kids[0]->sym)) {
    rv = kids[0]->dequalify().get();
  } else if (!strcmp("token", kids[0]->sym) && kids[0]->tok->cat == IDENTIFIER) {
    if (!(ste = symTab->lookupEntry(kids[0]->tok->text))) {
      printf("semantic error: unknown symbol %s\n", kids[0]->tok->text);
      exit(1);
    }
    rv = ste->typ.get();
  } else {
    printf("semantic error: can't dequalify %s\n", sym);
    exit(1);
  }

  if (rv->basetype != CLASS_TYPE) {
    printf("semantic error: can't dequalify %s\n", rv->str());
    exit(1);
  }

  ste = ((ClassType*)rv)->st->lookupEntry(kids[1]->tok->text);
  if (ste)
    return ste->typ;
  
  printf("semantic error: couldn't lookup %s in %s\n", kids[1]->tok->text, rv->str());
  exit(1);

  return NULL;
}

vector<shared_ptr<TypeInfo>> *Tree::mksig() {
  vector<shared_ptr<TypeInfo>> *res = new vector<shared_ptr<TypeInfo>>();
  vector<shared_ptr<TypeInfo>>::iterator it;
  if (!strcmp("FormalParm", sym)) {
    res->push_back(kids[0]->typ);
    return res;
  } else if (!strcmp("FormalParmList", sym)) {
    vector<shared_ptr<TypeInfo>> *t1 = kids[0]->mksig();
    vector<shared_ptr<TypeInfo>> *t2 = kids[1]->mksig();

    res->insert(res->end(), t1->begin(), t1->end());
    res->insert(res->end(), t2->begin(), t2->end());

    // No need clear because it performs automatically on delete vector
    t1->clear();
    t2->clear();
    delete t1;
    delete t2;
  }

  return res;
}

void Tree::cksig(MethodType *sig) {
    int i = sig->params->size(), nactual = 1;
    Tree *t = kids[1];
    if (!t) {
      if (i != 0) {
        printf("semantic error: 0 params, expected %d\n", i);
        exit(1);
      }
    } else {
      while (!strcmp("ArgList", t->sym)) {
        nactual++;
        t = t->kids[0];
      }

      if (nactual != i) {
        printf("semantic error: %d parameters, expected %d\n", nactual, i);
        exit(1);
      }

      t = kids[1];
      i--;
      while (!strcmp("ArgList", t->sym)) {
        checkTypes(t->kids[1]->typ, sig->params->at(i));
        t = t->kids[0];
        i--;
      }
      checkTypes(t->typ, sig->params->at(0));
    }
    typ = sig->returnType;
}

shared_ptr<Address> Tree::genLabel() {
  return make_shared<Address>("lab", serial_GetId());
}

void Tree::genClassDecl() {
  map<string, SymTabEntry*>::iterator it;
  SymTabEntry* entry;

  // Emit string constants
  if (string_st->size() > 0) {
    addCode(".string", 0);
    
    for (it = string_st->t.begin(); it != string_st->t.end(); it++) {
      entry = it->second;
      if (!entry->addr) {
        printf("null label in stringtab\n");
        exit(1);
      }

      addCode("LAB", entry->addr);
      addCode("string", make_shared<Address>(entry->sym, 0));
    }
  }

  // Emit the globals
  if (global_st->size() > 0) {
    addCode(".global", 0);

    for (it = global_st->t.begin(); it != global_st->t.end(); it++) {
      entry = it->second;
      addCode("global", entry->addr, make_shared<Address>(entry->sym, 0));
    }
  }

  addCode(".code", 0);

  for (int i=0; i<nkids; i++) {
    copyIcodeFrom(kids[i]);
  }
}

void Tree::genAddExpr() {
  addr = genLocal();
  copyIcodeFrom(kids[0]);
  copyIcodeFrom(kids[1]);
  addCode(rule==1320 ? "ADD" : "SUB", addr, kids[0]->addr, kids[1]->addr);
}

void Tree::genMulExpr() {
  addr = genLocal();
  copyIcodeFrom(kids[0]);
  copyIcodeFrom(kids[1]);

  if (rule == 1310)
    addCode("MUL", addr, kids[0]->addr, kids[1]->addr);
  else if (rule == 1311)
    addCode("DIV", addr, kids[0]->addr, kids[1]->addr);
  else
    addCode("MOD", addr, kids[0]->addr, kids[1]->addr);
}

void Tree::genRelExpr() {
  const char *op = "ERROR";
  switch (kids[1]->tok->cat) {
    case '<':
      op="BLT";
      break;
    case '>':
      op="BGT";
      break;
    case LESSTHANOREQUAL:
      op="BLE";
      break;
    case GREATERTHANOREQUAL:
      op="BGE";
      break;
    default:
      break;
  }

  copyIcodeFrom(kids[0]);
  copyIcodeFrom(kids[2]);

  addCode(op, onTrue, kids[0]->addr, kids[2]->addr);
  addCode("GOTO", onFalse);
}

void Tree::genWhileStmt() {
  addCode("LAB", kids[0]->first);
  copyIcodeFrom(kids[0]);
  addCode("LAB", kids[0]->onTrue);
  copyIcodeFrom(kids[1]);
  addCode("GOTO", kids[0]->first);
}

void Tree::genIfThenStmt() {
  copyIcodeFrom(kids[0]);
  addCode("LAB", kids[0]->onTrue);
  copyIcodeFrom(kids[1]);
}

void Tree::genAssignment() {
  addr = kids[0]->addr;
  copyIcodeFrom(kids[0]);
  copyIcodeFrom(kids[2]);
  addCode("ASN", addr, kids[2]->addr);
}

void Tree::genMethodCall() {
  int nparms = 0;
  if (kids[1]) {
    copyIcodeFrom(kids[1]);
    Tree *k = kids[1];
    while (!strcmp("ArgList", k->sym)) {
      addCode("PARM", k->kids[1]->addr);
      k = k->kids[0];
      nparms++;
    }
    addCode("PARM", k->addr);
    nparms++;
  }

  if (!strcmp("QualifiedName", kids[0]->sym)) {
    copyIcodeFrom(kids[0]);
    addCode("PARM", kids[0]->kids[0]->addr);
  } else {
    addCode("PARM", make_shared<Address>("self", 0));
  }

  addCode("CALL", kids[0]->addr, make_shared<Address>("imm", nparms));
}

void Tree::genMethodDecl() {
  char *methodname = kids[0]->kids[1]->kids[0]->tok->text;
  int nparams = 0;
  int nlocals = 0;
  SymTabEntry *m = global_st->lookupEntry("hello")->st->t[methodname];
  if (!m)
    fprintf(stderr, "null m\n");
  
  nparams = ((MethodType*)(m->typ.get()))->params->size();
  nlocals = m->st->count/8;
  addCode("proc", make_shared<Address>(methodname, 0), make_shared<Address>("imm", nparams), make_shared<Address>("imm", nlocals));

  for (int i=0; i<nkids; i++) {
    copyIcodeFrom(kids[i]);
  }

  addCode("LAB", follow);
  addCode("RET");
  addCode("end");
}

void Tree::genQualifiedName() {
  SymTabEntry *ste;
  ClassType *ct;
  copyIcodeFrom(kids[0]);

  if (typ && typ->basetype == METHOD_TYPE) {// no icode, compile-time method resolution
    char *s = (char*)malloc(100);
    sprintf(s, "%s__%s", kids[0]->typ->str(), kids[1]->tok->text);
    addr = make_shared<Address>(s, 0);
  } else {
    addr = genLocal();
    if (kids[0]->typ && kids[0]->typ->basetype == ARRAY_TYPE) { // array.length
      addCode("ASIZE", addr, kids[0]->addr);
    } else if (
      kids[0]->typ &&
      kids[0]->typ->basetype == CLASS_TYPE &&
      (ct = (ClassType*)kids[0]->typ.get()) &&
      (ste = ct->st->lookupEntry(kids[1]->tok->text))
    ) {
      // lookup address within class
      if (!kids[1]->addr)
        kids[1]->addr = ste->addr;

      addCode("FIELD", addr, kids[0]->addr, kids[1]->addr);
    }
  }
}

void Tree::genToken() {
  switch (tok->cat) {
    case IDENTIFIER: {
      SymTabEntry *ste;
      ste = symTab->lookupEntry(tok->text);
      if (ste) {
        addr = ste->addr;
      }
      break;
    }
    case INTLIT: {
      addr = make_shared<Address>("imm", atoi(tok->text));
      break;
    }
    case STRINGLIT: {
      string_st->insertEntry(tok->text, true, NULL, make_shared<StringType>());
      addr = string_st->lookupEntry(tok->text)->addr;
      break;
    }
    // ...
    default:
      break;
  }
}

shared_ptr<Address> Tree::genLocal() {
  return symTab->genLocal();
}

void Tree::addCode(const char *op, shared_ptr<Address> addr1, shared_ptr<Address> addr2, shared_ptr<Address> addr3) {
  shared_ptr<Tac> tac = make_shared<Tac>(op, addr1, addr2, addr3);
  icode.push_back(tac);
  ncode++;
}

void Tree::addCode(const char *op, shared_ptr<Address> addr1, shared_ptr<Address> addr2) {
  shared_ptr<Tac> tac = make_shared<Tac>(op, addr1, addr2);
  icode.push_back(tac);
  ncode++;
}

void Tree::addCode(const char *op, shared_ptr<Address> addr1) {
  shared_ptr<Tac> tac = make_shared<Tac>(op, addr1);
  icode.push_back(tac);
  ncode++;
}

void Tree::addCode(const char *op) {
  shared_ptr<Tac> tac = make_shared<Tac>(op);
  icode.push_back(tac);
  ncode++;
}

void Tree::copyIcodeFrom(Tree *src) {
  if (src->ncode == 0)
    return;

  // copy(src->icode.begin(), src->icode.end(), std::back_inserter(icode));
  icode.insert(icode.end(), src->icode.begin(), src->icode.end());
  
  ncode += src->ncode;
}

static char *escape(char *dest, const char *src) {
  if (src[0] == '"') {
    int len = strlen(src);
    dest[0] = '\\';
    strncat(dest, src, len-1);
    strcat(dest, "\\\"");
  } else {
    strcpy(dest, src);
  }

  return dest;
}
