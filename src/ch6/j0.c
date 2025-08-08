#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#include "j0gram.tab.h"
#include "j0.h"
#include "util.h"

static int yycolno;
static int count;
static int serial;
static char *yyfilename;
static SymTab *global_st;

static int getid();

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

  tree_Free(yylval.t);
  fclose(yyin);

  if (i == 0)
    printf("no errors, %d tokens parsed\n", count);
}

void yyerror(char *s) {
  fprintf(stderr, "line %d, column %d, lexeme \"%s\": %s\n", yylineno, yycolno, yytext, s);
  exit(1);
}

void lexErr(char *s) {
  printf("%s: line %d: %s\n", s, yylineno, yytext);
  exit(1);
}

int scan(int cat) {
  Tree *tree = malloc(sizeof(Tree));
  tree->sym = "token";
  tree->rule = 0;
  tree->tok.id = getid();
  tree->tok.cat = cat;
  tree->tok.text = strdup(yytext);
  tree->tok.lineno = yylineno;
  tree->tok.colno = yycolno;
  tree->id = getid();
  tree->nkids = 0;
  tree->kids = NULL;
  tree->isConst = false;
  tree->symTab = NULL;

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

short ord(char* s) {
  return (short)s[0];
}

Tree *node(char *sym, int rule, int nkids, ...) {
  va_list ap;
  va_start(ap, nkids);
  
  Tree *tree = malloc(sizeof(Tree));
  tree->sym = sym;
  tree->rule = rule;
  tree->tok.id = 0;
  tree->tok.cat = -1;
  tree->tok.text = NULL;
  tree->tok.lineno = 0;
  tree->tok.colno = 0;
  tree->id = getid();
  tree->nkids = nkids;
  tree->kids = calloc(nkids, sizeof(Tree));
  tree->isConst = false;
  tree->symTab = NULL;

  for (int i = 0; i < nkids; i++) {
    tree->kids[i] = va_arg(ap, Tree*);
  }

  va_end(ap);

  return tree;
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
  tree_PrintGraph(f, root);
  fprintf(f, "}\n");
  fclose(f);
}

void semantic(Tree *root) {
  SymTab *System_st, *out_st;

  global_st = symtab_Create("global", NULL);
  System_st = symtab_Create("class", NULL);
  out_st = symtab_Create("class", NULL);

  symtab_InsertEntry(out_st, "println", false, NULL);
  symtab_InsertEntry(System_st, "out", false, out_st);
  symtab_InsertEntry(global_st, "System", false, System_st);

  tree_MkSymTables(root, global_st);
  tree_PopulateSymTables(root);
  tree_CheckSymTables(root);
  symtab_Print(global_st, 0);
}

static int getid() {
  return ++serial;
}
