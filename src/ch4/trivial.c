#include <stdlib.h>
#include "ns.tab.h"
#include "trivial.h"
#include "util.h"

int main(int argc, char* argv[]) {
  print_pid();

  if (argc == 1) {
    printf("usage: trivial [filename]\n");
  }

  char* filename = argv[1];
  if(!(yyin = fopen(filename, "r"))) {
    printf("cannot open file: %s\n", filename);
    exit(1);
  }

  int i = yyparse();
  if (i == 0)
    printf("no errors\n");
}

void yyerror(char *s) {
  fprintf(stderr, "error: %s\n", s);
  exit(1);
}

void lexErr(char* s) {
  printf("%s\n", s);
  exit(1);
}