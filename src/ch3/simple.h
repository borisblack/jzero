#include <stdio.h>

extern FILE *yyin;
extern char *yytext;
int yylex(void);

void lexErr(char* s);
