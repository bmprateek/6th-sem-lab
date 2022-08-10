#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int lineno=0,open=0,close=0,string=0,strcheck,i;
	char line[100];
	FILE* fp;
	fp = fopen("file.txt" ,"r");
	while((fgets(line , sizeof(line) , fp)) != NULL){
		lineno ++;
		open = 0;
		close = strcheck = string = 0;
		for(i =0 ; i< strlen(line) ; i++){
			if(line[i] == '"'){
			string = 1;
			if(open ==1 && close ==0)
				close =1;
			else if(open == 0 && close == 0)
				open = 1;
			else if(open ==1 && close ==1)
				close = 0;
			}
		}
		if(open==1&&close==0){
			printf("Unterminated string at line = %d\n",lineno);
			strcheck=1;
		}
		else if(string==1&&strcheck==0)
			printf("String usage validated at line = %d\n",lineno);
	}
	return 0;
}
