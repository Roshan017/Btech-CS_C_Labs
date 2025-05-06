#include<stdio.h>
#include<ctype.h>

char I[100],P[100];//S1[100]
int S[100];

//int top1=-1;
int top=-1;


int priorty(char c)
{
    switch(c)
    {
        case '+':
        case '-':
        return 1;

        case '*':
        case '/':
        return 2;

        case '^':
        return 3;
    }

}

void postfix()
{
    int i=0,j=0;
    char x,y;

    while(I[i]!='\0')
    {
        if(isdigit(I[i]))
        {
            P[j++]=I[i];
        }
        else if(I[i]=='(')
        {
            S[++top] = I[i];
        }

        else if(I[i]==')')
        {
            while(S[top]!='(')
            {
                P[j++] = S[top--];
            }
            top--;
        }

        else{
            x=I[i];
            y=S[top];

            if(top==-1||priorty(y)<priorty(x)||y=='(')
            {
                S[++top] = I[i];
            }

            else{ 
            
            while(top!=-1   &&   priorty(x)<=priorty(y)   &&   y !='(')
            {
                P[j++] = S[top--];
                y=S[top];
            }
            S[++top]=x;
        }
        }
        i++;
    }
    

    while(top!=-1)
    {
       P[j++] = S[top--] ;
       
    }
    P[j] = '\0';
    printf("The postfix Expression is: %s",P);
}

void main()
{
    printf("Enter the infix expression: \n");
    gets(I);
    postfix();
    //post_eval();
}