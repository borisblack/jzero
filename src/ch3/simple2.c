#include <stdio.h>
#include <stdlib.h>
#include "simple2.h"

int main(int argc, char* argv[]) {
  if (argc == 1) {
      printf("usage: simple2 [filename]\n");
  }

  char* filename = argv[1];
  if(!(yyin = fopen(filename, "r"))) {
    printf("cannot open file: %s\n", filename);
    exit(1);
  }

  yylineno = 1;
  int i;
  while ((i = yylex())) {
    printf("token %d (line %d): %s\n", i, yylval.lineno, yytext);
  }
}

void lexErr(char* s) {
  printf("%s: line %d: %s\n", s, yylineno, yytext);
  exit(1);
}

int scan(int cat) {
  yylval.cat = cat;
  yylval.text = yytext;
  yylval.lineno = yylineno;

  return cat;
}

void increment_lineno() {
  yylineno++;
}
