#ifndef J0_H
#define J0_H

#include <stdio.h>
#include "tree.h"
#include "symtab.h"

extern FILE *yyin;
extern char *yytext;
extern int yylineno;

int yylex(void);
void yyerror(const char *s);

void lexErr(const char* s);
int scan(int cat);
void newline();
void whitespace();
void comment();
short ord(const char* s);
Tree *node(const char *sym, int rule, int nkids, ...);
void calcType(Tree *tree);
void printRoot(Tree *root);
void semantic(Tree *root);
void gencode(Tree *root);

#endif /* J0_H */
