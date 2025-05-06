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
    if((r+1)%10 == f)
    {
        printf("Queue is full\n");
    }
    else if(f== -1 && r==-1)
    {
        f=0;
        r=0;
        ar[r] = n;
    }
    else{
    r=(r+1)%10;
    ar[r] = n;
}
}

void Deq()
{
        
    if(f==-1 && r==-1)
    {
        printf("Queue is empty\n");
    }

    else if(f==r)
    {
        int d = ar[f];
        printf("The deleted element is : %d \n",d);
        f=-1;
        r=-1;
    }
    

    else{
        int d = ar[f];
         printf("The deleted element is : %d \n",d);
        f=(f+1)%10;
       
    }
    
}
void display()
{
    int i=f;
    if(f==-1 && r==-1)
    {
        printf("Queue is empty\n");
    }
    else{
        while( i <= r )
        {
            printf("%d\t",ar[i]);
            i=(i+1)%10;
        }
    }


}
