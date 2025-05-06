//EXP7
%{
#include<stdio.h>
int v=0,c=0;
%}
%%
[A,a,E,e,I,i,O,o,U,u] v++;
[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z] c++;

%%

int main()
{
	FILE *fp = fopen("inp.txt","r");
	yyin = fp;
	FILE *fp1 = fopen("out.txt","w");
	yyout = fp1;
	yylex();
	
	fprintf(yyout,"The File Contains:\n");
	fprintf(yyout,"%d Vowels\n",v);
	fprintf(yyout,"%d Consonants\n",c);
	
	fclose(yyin);
	fclose(yyout);
	
}
int yywrap()
{
	return(1);
}
//INPUT
hello my name is Roshan
//OUTPUT
    
The File Contains:
7 Vowels
12 Consonants
