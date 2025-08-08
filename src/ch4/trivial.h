#ifndef TRIVIAL_H
#define TRIVIAL_H

#include <stdio.h>

extern FILE *yyin;

int yylex(void);
void yyerror(char *s);

void lexErr(char* s);

#endif /* TRIVIAL_H */