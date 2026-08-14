%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
int yyerror(const char *s);
%}

%token IF ELSE FOR WHILE SWITCH CASE DEFAULT
%token ID NUM
%token LBRACE RBRACE LPAREN RPAREN COLON SEMICOLON
%token EQ LE GE LT GT ASSIGN

%%

program
        : stmt
        ;

stmt
        : if_stmt
        | while_stmt
        | for_stmt
        | switch_stmt
        | block
        | assignment
        ;

block
        : LBRACE assignment RBRACE
        ;

assignment
        : ID ASSIGN NUM SEMICOLON
        ;

if_stmt
        : IF LPAREN cond RPAREN block
        | IF LPAREN cond RPAREN block ELSE block
        ;

while_stmt
        : WHILE LPAREN cond RPAREN block
        ;

for_stmt
        : FOR LPAREN
          ID ASSIGN NUM SEMICOLON
          cond SEMICOLON
          ID ASSIGN NUM
          RPAREN
          block
        ;

switch_stmt
        : SWITCH LPAREN ID RPAREN
          LBRACE
          case_list
          RBRACE
        ;

case_list
        : CASE NUM COLON assignment
        | CASE NUM COLON assignment DEFAULT COLON assignment
        ;

cond
        : ID relop NUM
        ;

relop
        : EQ
        | LE
        | GE
        | LT
        | GT
        ;

%%

int main()
{
    printf("Enter a C control structure syntax:\n");
    yyparse();
    printf("Valid control structure syntax.\n");
    return 0;
}

int yyerror(const char *s)
{
    printf("Invalid control structure syntax.\n");
    exit(0);
}