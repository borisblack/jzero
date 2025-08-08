#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include "ilist.h"
#include "symtab.h"
#include "typeinfo.h"
#include "tac.h"

typedef struct Token Token;
typedef struct Tree Tree;

struct Token {
  int id;
  int cat;
  char *text;
  int lineno;
  int colno;
  TypeInfo *typ;
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
  TypeInfo *typ;
  int ncode;
  dlist_head icode;
  Address *addr;
  Address *first;
  Address *follow;
  Address *onTrue;
  Address *onFalse;
};

const char *token_Name(int t);
TypeInfo *token_CatType(int cat);
TypeInfo *token_Type(Token *token, SymTab *stab);
void tree_Print(Tree *tree, int level);
void tree_PrintGraph(FILE *f, Tree *tree);
void tree_CalcIsConst(Tree *tree);
void tree_MkSymTables(Tree *tree, SymTab *stab);
void tree_PopulateSymTables(Tree *tree);
void tree_CheckSymTables(Tree *tree);
void tree_CalcType(Tree *tree);
void tree_AssignType(Tree *tree, TypeInfo *typeInfo);
void tree_CheckType(Tree *tree, bool inCodeBlock);
void tree_MkCls(Tree *tree);
void tree_GenFirst(Tree *tree);
void tree_GenFollow(Tree *tree);
void tree_GenTargets(Tree *tree);
void tree_GenCode(Tree *tree);
void tree_PrintIcode(Tree *tree);
void tree_Free(Tree *tree);

#endif /* TREE_H */
