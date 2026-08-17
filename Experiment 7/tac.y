%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(void);
int yyerror(const char *s);

int tempCount = 1;
char temp[20];

void printTAC(char *result, char *op1, char *operator, char *op2)
{
    printf("%s = %s %s %s\n", result, op1, operator, op2);
}

void printAssign(char *var, char *val)
{
    printf("%s = %s\n", var, val);
}
%}

%union
{
    char *str;
}

%token <str> ID NUM
%type <str> expr

%left '+' '-'
%left '*' '/'

%%

stmt
    : ID '=' expr '\n'
      {
          printAssign($1, $3);
      }
    ;

expr
    : expr '+' expr
      {
          sprintf(temp, "t%d", tempCount++);
          printTAC(temp, $1, "+", $3);
          $$ = strdup(temp);
      }

    | expr '-' expr
      {
          sprintf(temp, "t%d", tempCount++);
          printTAC(temp, $1, "-", $3);
          $$ = strdup(temp);
      }

    | expr '*' expr
      {
          sprintf(temp, "t%d", tempCount++);
          printTAC(temp, $1, "*", $3);
          $$ = strdup(temp);
      }

    | expr '/' expr
      {
          sprintf(temp, "t%d", tempCount++);
          printTAC(temp, $1, "/", $3);
          $$ = strdup(temp);
      }

    | ID
      {
          $$ = $1;
      }

    | NUM
      {
          $$ = $1;
      }
    ;

%%

int main()
{
    printf("Enter the expression:\n");
    yyparse();
    return 0;
}

int yyerror(const char *s)
{
    printf("Invalid expression\n");
    return 0;
}