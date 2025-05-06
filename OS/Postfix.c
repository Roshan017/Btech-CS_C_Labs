#include<stdio.h>
#include<math.h>
#include<ctype.h>

int top = -1;
int priorty(char c);
void Postfix()
void Post_eval();

int S[20],P[20],I[20],E[20];

int priorty(char c)
{
    if(c == '+'|| c== '-')
    return 0;
    if(c=='*'|| c=='/')
    return 1;

    if(c == '^')
    return 2;


}

void main()
{
    printf("Enter the infix expression: \n");
    gets(I);
    Postfix();
    Post_eval();
    
}

void Postfix()
{
    int i=0,j=0;
    char x,y;

    while(I[i] != '\0')
    {
        if(isdigit(I[i]))
        {
            P[top++] = I[i];
        }
        else if(I[i] == '(')
        {
            S[top++] = I[i];
            
        }  

        else if(I[i] = ')')
        {
            while(S[top] != '(')
            {
                P[j++] = S[top--];
            }
            top--;
        }      

        else{
            x=I[i];
            y=S[top];

            if(y==-1 || priorty(y)<priorty(x) || y=='(')
            {
                S[++top] = I[i];
            }
            else{
                while(y!=0 || priorty(x)<priorty(y) || y!='(')
                {
                    P[j++] = S[top--]
                    y = S[top];
                }
                S[++top] = x;
            }

        }
        i++;
    }
    while(top != '\0')
    {
        P[j++] = S[top--];
        
    }
    P[j] = '\0';
    printf("The postfix Expression is: %s",P);
}
void Post_eval()
{
    int i, n1,n2,n3,num;

    while(P[i] != '\0')
    {
        if(isdigit(P[i]))
        {
            num = P[i] + 48;
            E[top++] = num;
        }
        else{
            n1 = E[top--];
            n2 = E[top--];

            switch(P[i])
            {
                case '+':
                {
                n3 = n1 + n2;
                break;
                }
                case '-':
                {
                n3 = n2-n1;
                break;
                }
                case '*':
                {
                n3 = n2*n1;
                break;
                }
                case '/':
                {
                n3 = n2/n1;
                break;
                }
                case '^':
                {
                    n3 = pow(n2,n1);
                }
            }

            E[top++] = n3;
        }
        i++;
    }
    printf("Value of Postfix Expression %s is : %d",P,E[top--]);
}