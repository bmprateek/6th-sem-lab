#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
int main(){
	FILE* fp;
	int commentcheck=0;
	int i;
	int lineno=0; 
	int comment=0; 
	char line[100]; 
	int open=0,close=0,openlineno,closelineno;
	fp=fopen("file.txt", "r");
	if(fp == NULL)
		exit(0);
	printf("\nFile opened correctly!\n");
	while(fgets(line , sizeof(line) , fp) !=NULL){
		lineno++;
		commentcheck =0;
		comment = 0;
		if(open == 1 && close == 0)
			printf("%s\n" , line);
		if(strstr(line , "/*") && open==0){
			open =1 ;
			close =0;
			openlineno = lineno;
			printf("%s\n", line);
			comment =1;
		}
		if(strstr(line,"//"))
			printf("Single line comment identified at line no: %d\n",lineno);
		if(strstr(line , "*/") && open ==1 && close == 0){
			closelineno = lineno;
			open =  0;
			close = 1;
			printf("\n comment is displayed above \n comment opened in line no %d and closed in line no %d" , openlineno , closelineno);
		}
	}
	if(open==1&&close==0){
		printf("Comment not ended\nOpened at line = %d\n",openlineno);
		commentcheck=1;
	}
	else if(comment==1&&commentcheck==0){
		printf("Closed\n");
	}
	return 0;
}
