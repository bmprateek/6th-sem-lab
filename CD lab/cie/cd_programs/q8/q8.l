%{
#include<stdio.h>
int c = 0 , oc =0;
FILE* fp;
%}
%s COMMENT
%%
\n {c++;}
"/*" {BEGIN COMMENT; oc = 1; ECHO ;printf("\n comment begins in line no : %d\n",c);}
<COMMENT>\n {c++;printf("\n");ECHO;}
<COMMENT>. {ECHO;}
<COMMENT>"*/" {BEGIN 0; oc = 0; printf(": Comment ends in line no %d\n",c); ECHO;}
. ;
%%
void main()
{
yyin=fopen("file.c","r"); 
yylex(); 
fclose(yyin); 
if(oc==1)
{ 
printf("\n comment is not closed till the end of file!");
}
}
