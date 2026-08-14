%{
#include <stdlib.h>
#include "y.tab.h"
%}

%option noyywrap

DIGIT   [0-9]+(\.[0-9]+)?

%%

{DIGIT}    { yylval.dval = atof(yytext); return NUM; }

[ \t]+     ;

\n         { return '\n'; }

.          { return yytext[0]; }

%%