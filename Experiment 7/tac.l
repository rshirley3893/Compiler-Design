%{
#include "y.tab.h"
#include <string.h>
#include <stdlib.h>
%}

%option noyywrap

%%

[a-zA-Z][a-zA-Z0-9]* {
    yylval.str = strdup(yytext);
    return ID;
}

[0-9]+ {
    yylval.str = strdup(yytext);
    return NUM;
}

[ \t]+ ;

\n {
    return '\n';
}

. {
    return yytext[0];
}

%%