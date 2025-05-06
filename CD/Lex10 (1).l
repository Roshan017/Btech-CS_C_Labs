//EXP10
%{
    #include<stdio.h>
%}

%%
[' ';(){}]   {printf("\n<Bracket>\n");}
int     {printf("<int, keyword> \n");}
if      {printf("<if, keyword> \n");}
void    {printf("<void, keyword> \n");}
main    {printf("<main, keyword> \n");}
else    {printf("<else, keyword> \n");}
[0-9]+   {printf("<%s, digit> \n",yytext);}
[a-z][a-z0-9]*  {printf("<%s, identifier> \n",yytext);}
=       {printf("< =, operator> \n");}
["<"]      {printf("< <, operator> \n");}
[">"]      {printf("< >, operator> \n");}
["+"]      {printf("< +, operator> \n");}

["/"]      {printf("< /, operator> \n");}
["*"]      {printf("< *, operator> \n");}

%%

int main()
{
    FILE *fp=fopen("inp.txt","r");
    yyin=fp;
    yylex();
    fclose(yyin);
}

int yywrap()
{
    return(1);
}
/*void main()
{
	int a = 0;
	if(a>0)
	{
		a=a+1;
		printf("a");
	}
}
*/

/* Output
<void, keyword> 

<Bracket>
<main, keyword> 

<Bracket>

<Bracket>


<Bracket>

	<int, keyword> 

<Bracket>
<a, identifier> 

<Bracket>
< =, operator> 

<Bracket>
<0, digit> 

<Bracket>

	<if, keyword> 

<Bracket>
<a, identifier> 
< >, operator> 
<0, digit> 

<Bracket>

	
<Bracket>

		<a, identifier> 
< =, operator> 
<a, identifier> 
< +, operator> 
<1, digit> 

<Bracket>

		<printf, identifier> 

<Bracket>
< <, operator> 
<a, identifier> 
< <, operator> 

<Bracket>

<Bracket>

	
<Bracket>


<Bracket>





*/







