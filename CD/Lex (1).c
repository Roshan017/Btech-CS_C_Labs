	//EXP1
	#include<stdio.h>
	#include<ctype.h>
	#include<string.h>




	int main(){
		
		FILE *input,*output,*symbol;
		int l = 1;
		int t = 1;
		int id = 1;
		int i , flag;
		char ch,str[20];
		input = fopen("input.txt","r");
		output = fopen("output.txt","w");
		symbol = fopen("symbol.txt", "w");
		char Symbol_table[100][20];
		int symbol_ct = 0;
		fprintf(output,"Line no \t Token No \t\t\tToken\t\tLexeme\n\n");
		fprintf(symbol, "Symbol Table\n");
		
		fprintf(symbol, "Identifier No\t\t\t Identifier\n");
		
		while((ch=fgetc(input))!=EOF){
			i = 0;
			flag = 0;
			
			if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '!'|| ch == '<' || ch == '>')
			
			{
				char op = ch;
				
				ch = fgetc(input);
				
				if((op == '=' && ch == '=') || (op == '+' && ch == '=') || (op == '-' && ch == '=') || (op == '<' && ch == '=') || (op == '>' && ch == '=') || (op == '!' && ch == '=') )
				{
				
					fprintf(output,"%7d\t\t%7d\t\tOperator\t%7c%c\n",l,t++,op,ch);
					
				}
				else if((op == '&' && ch == '&') || (op == '|' && ch == '&'))
				{
					fprintf(output,"%7d\t\t%7d\t\tOperator\t%7c%c\n",l,t++,op,ch);
				
				}
				else{
				
					ungetc(ch,input);
					fprintf(output,"%7d\t\t%7d\t\tOperator\t%7c%c\n",l,t++,op,ch);
				}
			}
			else if(ch== ';' || ch == '{' || ch == '}' || ch == '(' || ch == ')' || ch == '?' || ch == '%'){
				
				fprintf(output,"%7d\t\t%7d\t\tSpecial Symbol\t%7c\n",l,t++,ch);
			
			}
			
			else if(isdigit(ch)){
				str[i]=ch;
				i++;
				ch = fgetc(input);
				
				while(isdigit(ch)){
				str[i]=ch;
				i++;
				ch = fgetc(input);
				}
				str[i] = '\0';
				
				fprintf(output,"%7d\t\t%7d\t\tNumber\t\t%7s\n",l,t++,str);
				ungetc(ch,input);
			}
			
			else if(isalpha(ch)){
				str[i] = ch;
				i++;
				ch = fgetc(input);
				
				while(isalnum(ch) || ch == '_'){
				str[i] = ch;
				i++;
				ch = fgetc(input);
				}
				str[i] = '\0';
				
				if(str[0] == 'i'){
					
					if(str[1] == 'f')
					{
						if(str[2] == '\0')
						{
							flag = 1;
						}
					}
				
					else if(str[1] == 'n'){
						if(str[2] == 't'){
							if(str[3] == '\0'){
								
								flag = 1;
							
							}
						}
					}
				} 
				else if(str[0] == 'm'){
					if(str[1] == 'a'){
						if(str[2] == 'i')
						{
							if(str[3] == 'n')
							{
								if(str[4] == '\0')
								{
									flag = 1;
								}
							}
						}
					}
				}
				
				else if(str[0] == 'f'){
				
					if(str[1] == 'o'){
						if(str[2] == 'r')
							if(str[3] == '\0')
							{
								flag = 1;
							}
					}
					else if(str[1] == 'l'){
						if(str[2] == 'o'){
							if(str[3]== 'a'){
								if(str[4] == 't'){
									if(str[5] == '\0'){
										flag = 1;
									}
								}
							}
						}
					}
				}
				else if(str[0] == 'v'){
					if(str[1] == 'o')
					{
						if(str[2] == 'i'){
							if(str[3] == 'd'){
								if(str[4] == '\0')
								{
									flag = 1;
								}
							}
						}
					}
				}
				
				
				else if(str[0] == 'w'){
					if(str[1] == 'h'){
						if(str[2] == 'i'){
							if(str[3] == 'l')
							{
								if(str[4] == 'e'){
									if(str[5] == '\0')
									{
										flag = 1;
									}
								}
							}
						}
					}
				}
				if(flag == 1)
				{
					fprintf(output,"%7d\t\t%7d\t\tKeyword\t%7s\n",l,t++,str);
				}
				else{
					int isDup = 0 ;
					for(int j = 0 ; j < symbol_ct;j++)
					{
						if(strcmp(Symbol_table[j],str) == 0)
						{
							isDup = 1;
							break;
						}
					}
					if(!isDup)
					{
						strcpy(Symbol_table[symbol_ct++],str);
						fprintf(symbol,"ID%d\t\t\t%7s\n",id,str);
						
					}
					
								
				}
				ungetc(ch,input);
			}
			else if(ch =='\n'){
				l++;
			}
		}
		
		fclose(input);
		fclose(output);
		return 0;
		
		
	}

	/*INPUT
	void main()
	{
		int a = 5;
		if(a >= 0)
		{
			a = a + 1;
		}
	}

	OUTPUT
	Line no 	 Token No 			Token		Lexeme

		1		      1		Keyword	   void
		1		      2		Keyword	   main
		1		      3		Special Symbol	      (
		1		      4		Special Symbol	      )
		2		      5		Special Symbol	      {
		3		      6		Keyword	    int
		3		      7		Operator	      = 
		3		      8		Number		      5
		3		      9		Special Symbol	      ;
		4		     10		Keyword	     if
		4		     11		Special Symbol	      (
		4		     12		Operator	      >=
		4		     13		Number		      0
		4		     14		Special Symbol	      )
		5		     15		Special Symbol	      {
		6		     16		Operator	      = 
		6		     17		Operator	      + 
		6		     18		Number		      1
		6		     19		Special Symbol	      ;
		7		     20		Special Symbol	      }
		8		     21		Special Symbol	      }
		

	Symbol Table
	Identifier No			 Identifier
	ID1			      a
	*/
