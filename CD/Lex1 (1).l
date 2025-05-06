//EXP5
%{
#include<stdio.h>
int c_letter=0,s_letter = 0, lines=0,words=0,character = 0,sp_char = 0, dig=0;
%}
%%
\n { lines++, words++; }
[\t ] words++;
[A-Z] c_letter++;
[a-z] s_letter++;
[0-9] dig++;
 .sp_char++;
%%

int main()
{
	FILE *fp = fopen("inp.txt","r");
	yyin = fp;
	FILE *fp1 = fopen("out.txt","w");
	yyout = fp1;
	yylex();
	
	character = s_letter+c_letter+dig+sp_char;
	fprintf(yyout,"This File Contains..\n");
	fprintf(yyout,"%d Small Letters\n",s_letter);
	fprintf(yyout,"%d Capital Letters\n",c_letter);
	fprintf(yyout,"%d Lines\n",lines);
	fprintf(yyout,"%d Words\n",words);
	fprintf(yyout,"%d Digits\n",dig);
	fprintf(yyout,"%d Special Characters\n",sp_char);
	fprintf(yyout,"%d Total Elements\n",character);
	fclose(yyin);
	fclose(yyout);
	
}
int yywrap()
{
	return(1);
}
//Input
hello, I am Roshan 
roll no 51

//Output
,      This File Contains..
18 Small Letters
2 Capital Letters
2 Lines
2 Words
2 Digits
0 Special Characters
22 Total Elements
