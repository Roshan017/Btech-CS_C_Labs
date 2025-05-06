#include<stdio.h>
void push(int n);
int pop();
void display();
int ar[10];
int top = 0;
void main(){
    int op;
    while(opt!=4)
    {
    printf("Enter your choice: \n1.Push \n2.Pop \n3.Display \n4.Exit")
    scanf("%d",&op);

    switch(op)
    {
        case 1: 
        int n;
        printf("Enter the value top be inserted: \n");
        scanf("%d",&n);
        push(n);
        break;

        case 2: 
        pop();
        printf("The deleted element is : %d \n",n);
        break;

        case 3:
        display();

        case 4;
        break;

        default:
        printf("Invalid Option\n");
        break;

    }
    }   
}

void push(int n)
{
    if(top == 19)
    {
        printf("Stack Overload\n");
    }
    else{
        ar[top++] = n;
    }

}

int pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
    }
    else{
        int n = ar[top--];

    }
    return n
}

void display()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
    }
    else{
        for(int i=0;i<10;i++)
        {
            printf("%d\t",ar[i]);
        }
    }
    

}