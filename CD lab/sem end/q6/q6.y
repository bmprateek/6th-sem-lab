%{
#include <stdio.h>
int res=0;
%}

%token id num

%%
stmt:expr {res=$$;};
expr: expr '+''+' {printf("\n++ sign detected");exit(0);}
	|expr '-''-' {printf("\n-- sign detected");exit(0);}
	|expr '+' expr {$$=$1+$3;printf("\n+ sign detected");}
	|expr '-' expr {$$=$1-$3;printf("\n- sign detected");}
	|expr '*' expr {$$=$1*$3;printf("\n* sign detected");}
	|expr '/' expr {$$=$1/$3;printf("\n/ sign detected");}
	|expr '*' {printf("\nError no right operand!");exit(0);}
	|'(' expr ')' {$$=$2;printf("\nbrackets detected");}
	|id
	|num
	;
%%
void main()
{
printf("\nEnter the expression : ");
yyparse();
printf("\n the result size is %d" , res);
exit(0);
}
void yyerror()
{
printf("Invalid\n");
exit(0);
}
