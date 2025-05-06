//exp8.y
%{
	#include<stdio.h>
	#include<stdlib.h>
	int yylex(void);
	int yyerror(char* s);
%}

%token NUMBER ID
%left '+''-'
%left '*''/''%'
%left '('')'


%%
expr: expr'+'expr
 |expr'-'expr
 |expr'*'expr
 |expr'/'expr
 |'-'NUMBER
 |'-'ID
 |'('expr')'
 |NUMBER
 |ID
%%

int main()
{
	printf("\nEnter The expression:\n");
	yyparse();
	printf("Expression is valid\n");
	return 0;
}
int yyerror(char* s)
{
	printf("\nExpression is invalid\n");
	exit(0);
}

/*Enter The expression:
id+id*id
Expression is valid*/
