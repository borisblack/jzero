%option noyywrap nodefault yylineno
%{
# include "simple.h"
%}

%%
[a-zA-Z]+   { return 1; }
[0-9]+      { return 2; }
[ \t]+      { }
.	          { lexErr("unrecognized character"); }
%%
