%option noyywrap nodefault yylineno

%{
#include "ns.tab.h"
#include "trivial.h"
%}

%%
[a-zA-Z]+   { return NAME; }
[0-9]+      { return NUMBER; }
[ \t]+      { }
.           { lexErr("unrecognized character"); }
%%
