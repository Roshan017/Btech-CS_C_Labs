#include<stdio.h>

void Enq(int n);
void Deq();
void display();

int f = -1;
int r = -1;
int ar[10];

void main()
{
    int op;
    while(op!=4)
    {
    printf("\nEnter your choice: \n1.Enque \n2.Deqeue \n3.Display \n4.Exit\n");
    scanf("%d",&op);

    switch(op)
    {
        case 1: 
        int n;
        printf("Enter the value to be inserted: \n");
        scanf("%d",&n);
        Enq(n);
        break;

        case 2: 
        Deq();
        
        break;

        case 3:
        display();

        case 4:
        break;

        default:
        printf("Invalid Option\n");
        break;

    }
    }   

}
void Enq(int n)
{
    if(r==9)
    {
        printf("Queue is full\n");
    }
    if(f== -1 || r==-1)
    {
        f++;
    }
    r++;
    ar[r] = n;
}

void Deq()
{
        //int n;
    if(f==-1|| f>r)
    {
        printf("Queue is empty\n");
    }
    /*else if(f=r)
    {
        n = ar[f];
        r=0;
        f=0;    
    }*/

    else{
        int d = ar[f];
        f++;
        printf("The deleted element is : %d \n",d);
    }
    
}
void display()
{
    if(f==-1)
    {
        printf("Queue is empty\n");
    }
    else{
        for(int i = f;i<=r;i++)
        {
            printf("%d\t",ar[i]);
            
        }
    }


}
