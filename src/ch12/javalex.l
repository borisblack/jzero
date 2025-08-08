%option noyywrap nodefault noyylineno
%{
#include "j0gram.tab.h"
#include "j0.h"
%}

ID ([a-zA-Z_][a-zA-Z0-9_]*)

%%
"/*"([^*]|"*"+[^/*])*"*"+"/" { comment(); }
"//".*\r?\n                  { comment(); }
[ \t\r\f]+                   { whitespace(); }
\n                           { newline(); }
"break"                { return scan(BREAK); }
"double"               { return scan(DOUBLE); } 
"else"                 { return scan(ELSE); }
"false"                { return scan(BOOLLIT); }
"for"                  { return scan(FOR); }
"if"                   { return scan(IF); }
"int"                  { return scan(INT); }
"new"                  { return scan(NEW); }
"null"                 { return scan(NULLVAL); }
"public"               { return scan(PUBLIC); }
"return"               { return scan(RETURN); }
"static"               { return scan(STATIC); }
"String"               { return scan(STRING); }
"true"                 { return scan(BOOLLIT); }
"bool"                 { return scan(BOOLEAN); }
"void"                 { return scan(VOID); }
"while"                { return scan(WHILE); }
"class"                { return scan(CLASS); }
"("                    { return scan(ord("("));}
")"                    { return scan(ord(")"));}
"["                    { return scan(ord("["));}
"]"                    { return scan(ord("]"));}
"{"                    { return scan(ord("{"));}
"}"                    { return scan(ord("}"));}
";"                    { return scan(ord(";"));}
":"                    { return scan(ord(":"));}
"!"                    { return scan(ord("!"));}
"*"                    { return scan(ord("*"));}
"/"                    { return scan(ord("/"));}
"%"                    { return scan(ord("%"));}
"+"                    { return scan(ord("+"));}
"-"                    { return scan(ord("-"));}
"<"                    { return scan(ord("<"));}
"<="                   { return scan(LESSTHANOREQUAL);}
">"                    { return scan(ord(">"));}
">="                   { return scan(GREATERTHANOREQUAL);}
"=="                   { return scan(ISEQUALTO);}
"!="                   { return scan(NOTEQUALTO);}
"&&"                   { return scan(LOGICALAND);}
"||"                   { return scan(LOGICALOR);}
"="                    { return scan(ord("=")); }
"+="                   { return scan(INCREMENT); }
"-="                   { return scan(DECREMENT); }
","                    { return scan(ord(",")); }
"."                    { return scan(ord(".")); }
{ID}                   { return scan(IDENTIFIER); }
[0-9]+                 { return scan(INTLIT); }
[0-9]*"."[0-9]*([eE][+-]?[0-9]+)? { return scan(DOUBLELIT); }
([0-9]+)([eE][+-]?([0-9]+))  { return scan(DOUBLELIT); }
\"([^\"]|(\\.))*\"     { return scan(STRINGLIT); }
.                      { lexErr("unrecognized character"); }
%%
