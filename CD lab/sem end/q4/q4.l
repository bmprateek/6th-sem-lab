%{
#include<stdio.h>
int c = 0;
FILE* fp;
%}
id [a-zA-Z][a-zA-z0-9]
num [0-9]+\
types "int"|"float"|"char"
dec {types}" "{id}(","{id})*
%%
\n {c++;}
"struct"" "{id}"{"({dec}";"|(\n))*"}"({id}(","{id})*)?";" {printf("Valid declaration at lin no: %d\n",c);ECHO;printf("\n");}
"struct"" "{id}" "({dec}";"|(\n))*"}"({id})?";" {printf("Opening braces of structure missing at line no: %d\n",c);ECHO;printf("\n");}
"struct"" "{id}"{"({dec}";"|(\n))*" "({id})?";" {printf("Closing braces of structure missing at line no: %d\n",c);ECHO;printf("\n");}
.|\n ;
%%
int main()
{
yyin = fopen("file.c", "r");
yylex();
fclose(yyin);
}
