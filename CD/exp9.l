//exp9.l
%{
#include"y.tab.h"
%}
%%
[a-zA-Z_][a-zA-Z_0-9]* return lt;
[0-9] return dt;
. return other;
\n return 0;
%%

int yywrap()
{
return 1;
}


