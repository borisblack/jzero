#ifndef TREE_H
#define TREE_H

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
};

const char* token_Name(int t);
void tree_Print(Tree *tree, int level);
void tree_PrintGraph(FILE *f, Tree *tree);
void tree_Free(Tree *tree);

#endif /* TREE_H */
