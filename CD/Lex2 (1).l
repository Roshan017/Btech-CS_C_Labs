//EXP6
%{
#include<stdio.h>
#include<ctype.h>
%}

%%
[a-z]+	{
	int i;
	for(i=0; yytext[i] != '\0';i++)
	{
		yytext[i] = toupper(yytext[i]);
	}
	fprintf(yyout,"%s",yytext);
}

\n	{
	fprintf(yyout,"\n");
}

%%

int main()
{
	FILE *fp = fopen("inp.txt","r");
	yyin = fp;
	FILE *fp1 = fopen("out.txt","w");
	yyout = fp1;
	yylex();
	fclose(yyin);
	fclose(yyout);
	return 0;
	
}
int yywrap()
{
	return(1);
}
//INPUT
hello
i am Roshan

//OUTPUT
HELLO
I AM ROSHAN
