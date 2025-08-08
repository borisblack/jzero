#include <stdio.h>

extern FILE *yyin;
extern char *yytext;
extern int yylineno;

typedef struct token token;
extern token yylval;

int yylex(void);

void lexErr(char* s);
int scan(int cat);
void newline();
void whitespace();
void comment();
short ord(char* s);

typedef struct token {
  int cat;
  char* text;
  int lineno;
  int colno;
  int ival;
  char* sval;
  double dval;
} token;

typedef enum SymbolKind {
  BREAK=257,
  PUBLIC=258,
  DOUBLE=259,
  ELSE=260,
  FOR=261,
  IF=262,
  INT=263,
  RETURN=264,
  VOID=265,
  WHILE=266,
  IDENTIFIER=267,
  CLASSNAME=268,
  CLASS=269,
  STATIC=270,
  STRING=273,
  BOOL=274,
  INTLIT=275,
  DOUBLELIT=276,
  STRINGLIT=277,
  BOOLLIT=278,
  NULLVAL=280,
  LESSTHANOREQUAL=298,
  GREATERTHANOREQUAL=300,
  ISEQUALTO=301,
  NOTEQUALTO=302,
  LOGICALAND=303,
  LOGICALOR=304,
  INCREMENT=306,
  DECREMENT=307,
  YYERRCODE=256
} SymbolKind;
