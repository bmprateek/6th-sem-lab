%{
#include<stdio.h>
int c = 1;
FILE* fp;
%}
%s DECLARE VAR
identifier [a-zA-Z][a-zA-Z0-9]*
number [0-9]+([.][0-9]*)?
string ["][a-zA-Z0-9]*["]
%%
\n {c++;}
("int"|"float") {BEGIN DECLARE;}
<DECLARE>{identifier}("="{number})? {BEGIN VAR; ECHO; printf("declaration at line %d\n", c);}
<DECLARE>{identifier}("="{string}) {BEGIN VAR; ECHO; printf("Invalid declaration at line %d\n", c);}
<VAR>";" {BEGIN 0;}
<VAR>"," {BEGIN DECLARE;}
<VAR>[,][,]+ {ECHO; printf("Invalid! dont use 2 commas at line %d\n", c);}
<VAR>.
<VAR>[\n]+ {BEGIN 0; c++;}
. ;
%%
void main(){
    yyin = fopen("file.c", "r");
    yylex();
    fclose(yyin);
}
