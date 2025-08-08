#include <stdio.h>

extern FILE *yyin;
extern char *yytext;
extern int yylineno;

int yylex(void);
void yyerror(char *s);

void lexErr(char* s);
int scan(int cat);
void newline();
void whitespace();
void comment();
short ord(char* s);

struct Token {
  int cat;
  char* text;
  int lineno;
  int colno;
  int ival;
  char* sval;
  double dval;
};

typedef struct Token Token;
