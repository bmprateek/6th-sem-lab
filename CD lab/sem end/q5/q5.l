%{
#include <stdio.h>
int c=0;
FILE *fp;
%}
id [a-zA-Z][a-zA-Z0-9]*
num [0-9]+
rel [<>=!]=?
%%
"if""("({id}|{num})({rel}({id}|{num}))*")""{".*"}"(\n)*("else if""("({id}|{num})({rel}({id}|{num}))*")""{".*"}")*(\n)*("else""{".*"}")? {printf("Found an if statement ! ");ECHO;}
("else if""("({id}|{num})({rel}({id}|{num}))*")""{".*"}")*(\n)*("else""{".*"}")? {printf("No preceding if statement before if else! ");ECHO;}
. ;
%%
int main(){
yyin=fopen("file.c","r");
yylex();
fclose(yyin);
}
