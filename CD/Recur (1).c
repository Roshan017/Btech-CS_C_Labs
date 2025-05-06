//EXP 2
//Grammar
//E->TE'
//E'->+TE/@
//T->FT'
//T'->*FT'/@
//F->(E)/id

#include<stdio.h>
#include<string.h>
#include<ctype.h>

char input[100];
int i=0;

int E();
int EP();
int T();
int TP();
int F();


void main()
{
	printf("\nRecursive Descent parsing for the Following Grammar");
	printf("\nE->TE'\nE'->+TE/@\nT->FT'\nT'->*FT'/@\nF->(E)/id\n");
	printf("Enter The String To be Checked: \n");
	scanf("%s",input);
	i=0;
	if(E() && input[i] == '\0' )
	{
		printf("String is Accepted\n");
	}
	else
	{
	printf("String not Accepted\n");
	}
}
int E()
{	printf("In E->TE'\n");
	if(T())
	{
		if(EP())
			return 1;
		else
			return 0;
		
	}
	else
		return 0;
	
}

int EP()
{
	printf("In E'->+TE/@\n");
	if(input[i] == '+')
	{
		i++;
		if(T())
		{
			if(EP())
				return 1;
			else
				return 0;
				
		}
		else
			return 0;
		
	}
	else 
		return 1; 
	
}
int T(){
	printf("In T->FT'\n");

	if(F())
	{
		if(TP())
			return 1;
		else
			return 0;
		
	}
	else
		return 0;
		
}
int TP()
{
	printf("In T'->*FT'/@\n");
	if(input[i] == '*')
	{
		i++;
		if(F())
		{
			if(TP())
				return 1;
			else
				return 0;
			
		}
		else
			return 0;
		
	}
	else
		return 1;
	
}
int F()
{
	printf("In F->(E)/id\n");
	if(input[i] == '(')
	{
		i++;
		if(E())
		{
			if(input[i] == ')')
			{
				i++;
				return 1;
			}
			else
				return 0;
			
		}
		else
			return 0;
		
	}
	else if(isalnum(input[i]))
	{
		i++;
		return 1;
	}
	else
		return 0;
	
}
