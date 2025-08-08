#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "j0.h"
#include "util.h"

static int yycolno;

static char* deEscape(const char* sin);

int main(int argc, char* argv[]) {
  print_pid();

  if (argc == 1) {
    printf("usage: j0 [filename]\n");
  }

  char* filename = argv[1];
  if(!(yyin = fopen(filename, "r"))) {
    printf("cannot open file: %s\n", filename);
    exit(1);
  }

  yylineno = yycolno = 1;
  yylval.sval = NULL;
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
  yylval.colno = yycolno;

  if (yylval.sval) {
    free(yylval.sval);
    yylval.sval = NULL;
  }

  switch (cat) {
    case INTLIT:
      yylval.ival = atoi(yytext);
      break;
    case DOUBLELIT:
      yylval.dval = atof(yytext);
      break;
    case STRINGLIT:
      yylval.sval = deEscape(yytext);
      break;
  }

  yycolno += strlen(yytext);
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
