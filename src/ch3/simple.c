#include <stdio.h>
#include <stdlib.h>
#include "simple.h"

int main(int argc, char* argv[]) {
  if (argc == 1) {
      printf("usage: simple [file]\n");
  }

  char* filename = argv[1];
  if(!(yyin = fopen(filename, "r"))) {
    printf("cannot open file: %s\n", filename);
    exit(1);
  }

  int i;
  while (i = yylex()) {
    printf("token %d: %s\n", i, yytext);
  }
}

void lexErr(char* s) {
  printf("%s: %s\n", s, yytext);
  exit(1);
}
