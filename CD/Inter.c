//EXP4
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


#define MAX_EXPRE_LEN 100
#define MAX_TEMP_VARS 50

char expr[MAX_EXPRE_LEN];
char temp_vars[MAX_TEMP_VARS][4];

int temp_var_count = 0;
FILE *fp;
char* new_temp_var(){

	if(temp_var_count>=MAX_TEMP_VARS){
	printf("Error : Too many temporary variables\n");
	exit(1);
	}
	sprintf(temp_vars[temp_var_count],"T%d",temp_var_count+1);
	return temp_vars[temp_var_count++];

}

int precedence(char op){
	switch(op){
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		return 0;
	}

}



char* generate_code(char* expr){
	int len = strlen(expr);
	int paren_count = 0;
	int op_pos = -1;
	int min_precedence = 3;
	
	for(int i = len-1;i>=0;i--){
		if(expr[i]==')') paren_count++;
		else if (expr[i]=='(') paren_count--;
		else if(paren_count == 0){
			int prec = precedence(expr[i]);
			if(prec>0 && prec <=min_precedence){
				min_precedence = prec;
				op_pos = i;
			}
		}
	}
	
	if(op_pos == -1){
		if(expr[0] == '(' && expr[len-1]==')'){
			expr[len-1] = '\0';
			return generate_code(expr+1);
		}
		return expr;
	}
	
	
	char op = expr[op_pos];
	expr[op_pos] = '\0';
	char* left  = generate_code(expr);
	char* right = generate_code(expr+op_pos+1);
	
	char* temp = new_temp_var();
	printf("%s := %s %c %s\t\t\t",temp,left,op,right);
	printf("%c %s %s %s\t\t\t",op,left,right,temp);
	if(strlen(left)>1 && strlen(right)>1)
	{
		printf("%c (%d) (%d) (%d)\n",op,atoi(left+1)-1,atoi(right+1)-1,atoi(temp+1)-1);
		fprintf(fp,"%c (%d) (%d) (%d)\n",op,atoi(left+1)-1,atoi(right+1)-1,atoi(temp+1)-1);
		}
	else if(strlen(left)>1)
	{
		printf("%c (%d) %s (%d)\n",op,atoi(left+1)-1,right,atoi(temp+1)-1);
		fprintf(fp,"%c (%d) %s (%d)\n",op,atoi(left+1)-1,right,atoi(temp+1)-1);
		}
	else if(strlen(right)>1)
	{
		printf("%c %s (%d) (%d)\n",op,left,atoi(right+1)-1,atoi(temp+1)-1);
		fprintf(fp,"%c %s (%d) (%d)\n",op,left,atoi(right+1)-1,atoi(temp+1)-1);
		}
	else{
		printf("%c %s %s (%d)\n",op,left,right,atoi(temp+1)-1);
	fprintf(fp,"%s := %s %c %s\n",temp,left,op,right);
	//fclose(fp);
	}
	return temp;
}


int main(){
	fp = fopen("output.txt","w");
	printf("Intermediate Code Generation\n");
 	printf("Enter the expression :\t");
 	if(scanf("%99s",expr)!=1){
 		printf("Error Reading input");
 		return 1;
 	}
 	printf("The intermediate code : \n");
 	printf("Three-address code\t\tQuad-Address\t\t\tTriple-Address\n");
 	
 	char* assignment = strchr(expr,'=');
 	
 	if(assignment){
 	
 	*assignment = '\0';
 	char* lhs = expr;
 	char* rhs = assignment + 1;
 	char* result = generate_code(rhs);
 	printf("%s:=%s\n",lhs,result);
 	fprintf(fp,"%s:=%s\n",lhs,result);
 	}
 	else{
 		generate_code(expr);
 	}
 	return 0;
 }
 
/*Intermediate Code Generation
Enter the expression :	a+a*b
The intermediate code : 
Three-address code		Quad-Address			Triple-Address
T1 := a * b			* a b T1			* a b (0)
T2 := a + T1			+ a T1 T2			+ a (0) (1)
*/