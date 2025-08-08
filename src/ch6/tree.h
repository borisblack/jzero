#ifndef TREE_H
#define TREE_H

#include "symtab.h"

typedef struct Token Token;
typedef struct Tree Tree;

struct Token {
  int id;
  int cat;
  char *text;
  int lineno;
  int colno;
};

struct Tree {
  int id;
  char *sym;
  int rule;
  Token tok;
  int nkids;
  Tree **kids;
  bool isConst;
  SymTab *symTab;
};

const char* token_Name(int t);
void tree_Print(Tree *tree, int level);
void tree_PrintGraph(FILE *f, Tree *tree);
void tree_Free(Tree *tree);
void tree_CalcIsConst(Tree *tree);
void tree_MkSymTables(Tree *tree, SymTab *stab);
void tree_PopulateSymTables(Tree *tree);
void tree_CheckSymTables(Tree *tree);

#endif /* TREE_H */
