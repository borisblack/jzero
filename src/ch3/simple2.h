#include <stdio.h>

extern FILE *yyin;
extern char *yytext;
extern int yylineno;

typedef struct token token;
extern token yylval;

int yylex(void);

void lexErr(char* s);
int scan(int cat);
void increment_lineno();

typedef struct token {
  int cat;
  char* text;
  int lineno;
} token;
