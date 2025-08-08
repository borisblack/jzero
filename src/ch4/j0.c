#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "j0gram.tab.h"
#include "j0.h"
#include "util.h"

static int yycolno;
static int count;

static char* deEscape(const char* sin);
static void freeToken(Token *token);

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

  yylval.t = NULL;
  yylineno = yycolno = 1;
  count = 0;
  int i = yyparse();
  if (i == 0)
    printf("no errors, %d tokens parsed\n", count);
}

void yyerror(char *s) {
  fprintf(stderr, "line %d, column %d, lexeme \"%s\": %s\n", yylineno, yycolno, yytext, s);
  exit(1);
}

void lexErr(char *s) {
  printf("%s: line %d: %s\n", s, yylineno, yytext);
  exit(1);
}

int scan(int cat) {
  Token *t = malloc(sizeof(struct Token));
  t->cat = cat;
  t->text = yytext;
  t->lineno = yylineno;
  t->colno = yycolno;
  t->sval = NULL;

  switch (cat) {
    case INTLIT:
      t->ival = atoi(yytext);
      break;
    case DOUBLELIT:
      t->dval = atof(yytext);
      break;
    case STRINGLIT:
      t->sval = deEscape(yytext);
      break;
  }

  yylval.t = t;
  yycolno += strlen(yytext);
  count++;

  // TODO: Process token elsewhere and free

  // Free token
  freeToken(yylval.t);
  yylval.t = NULL;

  return cat;
}

void newline() {
  yylineno++;
  yycolno = 1;
}

void whitespace() {
  yycolno += strlen(yytext);
}

void comment() {
  int len = strlen(yytext);
  for (int i = 0; i < len; i++) {
    if (yytext[i] == '\n') {
        yylineno++;
        yycolno = 1;
    } else {
        yycolno++;
    }
  }
}

short ord(char* s) {
  return (short)s[0];
}

static char* deEscape(const char* sin) {
  int len = strlen(sin);
  if (len < 2)
    return NULL;

  char bufIn[len-1]; // temporary buffer for input string without start/end double quotes and with terminal '\0'
  char bufOut[len-1]; // out string buffer, max length without start/end double quotes and with '\0'
  strncpy(bufIn, sin+1, len-2); // copy string without start/end double quotes
  bufIn[len-2] = '\0'; // add terminal '\0'
  char* pBufIn = bufIn;
  int i = 0;
  while (*pBufIn) {
      char c = pBufIn[0];
      pBufIn++;
      if (c == '\\') {
        if (!*pBufIn) {
          lexErr("malformed string literal");
        } else {
          c = pBufIn[0];
          pBufIn++;
          switch (c) {
            case 't':
              bufOut[i++] = '\t';
              break;
            case 'n':
              bufOut[i++] = '\n';
              break;
            default:
              lexErr("unrecognized escape");
          }
        }
      } else {
        bufOut[i++] = c;
      }
  }
  bufOut[i] = '\0'; // add terminal '\0'

  char* sout = strdup(bufOut); // intermediate variable for debug only

  return sout;
}

static void freeToken(Token *token) {
  if (!token)
    return;

  if (token->sval)
    free(token->sval);
  free(token);
}
