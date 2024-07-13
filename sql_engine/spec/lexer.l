
%top{
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../parser/parser.h"
}

digit        [0-9]
letter       [a-zA-Z]
identifier   {letter}({letter}|{digit}|"_")*
int_value    {digit}+
string_value \"([^\"\\]|\\.)*\"
bool_value   ("true"|"false")

%%

"CREATE"               { return CREATE; }
"TABLE"                { return TABLE; }
"INSERT"               { return INSERT; }
"INTO"                 { return INTO; }
"SELECT"               { return SELECT; }
"FROM"                 { return FROM; }
"WHERE"                { return WHERE; }
"GROUP"                { return GROUP; }
"BY"                   { return BY; }
"ORDER"                { return ORDER; }
"DROP"                 { return DROP; }
"MIN"                  { return MIN; }
"MAX"                  { return MAX; }
"SUM"                  { return SUM; }
"COUNT"                { return COUNT; }
"TOP"                  { return TOP; }
"int32"                { return INT32; }
"string"               { return STRING; }
"bool"                 { return BOOL; }
"="                    { return EQ; }
">"                    { return GT; }
">="                   { return GE; }
"<"                    { return LT; }
"<="                   { return LE; }
"!="                   { return NE; }
"*"                    { return STAR; }
"("                    { return LPAREN; }
")"                    { return RPAREN; }
","                    { return COMMA; }
{int_value}            { yylval.intval = atoi(yytext); return INT_VALUE; }
{string_value}         { yylval.strval = strdup(yytext); return STRING_VALUE; }
{bool_value}           { yylval.boolval = (strcmp(yytext, "true") == 0); return BOOL_VALUE; }
{identifier}           { yylval.strval = strdup(yytext); return IDENTIFIER; }
[ \t\n\r]+             { /* skip whitespace */ }
.                      { /* skip unrecognized characters */ }
%%

int yywrap() {
    return 1;
}
