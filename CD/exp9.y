//exp9.y
%{
#include <stdio.h>
int valid=1;
%}
%token dt lt other
%%
start:other char|lt char;
char:|lt char|dt char;
%%

int yyerror()
{
	printf("\nNot a valid identifier!\n");
	valid=0;
	return 0;
}

int main()
{
	printf("\nEnter the string to be tested:");
	yyparse();
	if(valid){
	printf("\nIdentifier is valid\n");
	}
}

/*
Enter the string to be tested:@ab123

Identifier is valid


Enter the string to be tested:_@123

Not a valid identifier!*/
