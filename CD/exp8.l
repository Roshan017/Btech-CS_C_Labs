//exp8.l
%{
	#include<stdio.h>
	#include<stdlib.h>
	#include "y.tab.h"
	int yyerror(char* s);

%}

%%
[0-9]+ {return NUMBER;}
[a-zA-Z]+ {return ID;}
[\t]+ {;}
\n    {return 0;}
.	{return yytext[0];}

%%

int yywrap()
{
	return 1;
}
