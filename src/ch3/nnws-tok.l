%option noyywrap nodefault
%{
# include "simple2.h"

token yylval;
%}

%%
[a-zA-Z]+  { return scan(1); }
[0-9]+     { return scan(2); }
[ \t]+     { }
\r?\n      { increment_lineno(); }
.          { lexErr("unrecognized character"); }
%%
