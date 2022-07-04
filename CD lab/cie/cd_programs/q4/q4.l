%{
#include<stdio.h>
int c =1;
FILE* fp;
%}
operator [-+*/]
number [0-9]+
identifier [a-zA-Z0-9]*
expr ({identifier}|{number})[ ]{operator}[ ]({identifier}|{number})
%%
\n {c++;}
{identifier}" = "{expr}";" {printf("Valid expression at line %d\n", c);}
{number}" = "{expr}";" {printf("Invalid expression at line %d! LHS issue\n", c);}
{identifier}" = "{expr} {printf("Invalid expression at line %d! Line not terminated\n", c);}
{identifier}" =; " {printf("Invalid expression at line %d! Missing expression\n", c);}
{operator}{operator}+ {printf("Only one operand must be present\n");}
. ;
%%

void main()
{
yyin = fopen("file.c" , "r");
yylex();
fclose(yyin);
}

