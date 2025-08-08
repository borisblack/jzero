%{
#include "trivial.h"
%}

%token NAME NUMBER

%%
sequence : pair sequence | ;
pair : NAME NUMBER ;
%%
