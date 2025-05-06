
#include<stdio.h>
#include<stdlib.h>

#define max 100
int RQ[max],i,j,in,n,total=0,temp;
void fcfs();
void scan();
void cscan();
void clook();


void main(){

    int opt;

    do{

        printf("Select the type of scheduling to perform: \n1.FCFS\n2.SSTF\n3.SCAN\n4.C SCAN\n5.EXIT\n");
        scanf("%d",&opt);

        switch(opt)
        {
            case 1: 
            fcfs();
            break;
            case 2:
            scan();
            break;

            case 3:
            cscan();
            break;

            case 4:
            clook();
            break;

            case 5:
            look();
            break
        }
    }while(opt!=6);

}

void fcfs()
{
    printf("Enter the number of Requests: \n");
    scanf("%d",&n);
    printf("Enter the sequence of Requests: \n ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&RQ[i]);
    }

    printf("Enter the initial point: \n");
    scanf("%d",&in);


    for(i=0;i<n;i++)
    {

        total = total + abs(RQ[i]-in);
        printf("%d-%d ->\t",RQ[i],in);
        in =RQ[i];
    }

    printf("\nThe Total Head Movement is: %d\n",total);
}

void scan()
{
    int prev,move,size,index;
     printf("Enter the number of Requests: \n");
    scanf("%d",&n);
    printf("Enter the sequence of Requests: \n ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&RQ[i]);
    }

    printf("Enter the initial point: \n");
    scanf("%d",&in);

    printf("Enter the previous request\n");
    scanf("%d",&prev);

    if(in>prev)
    {
        move=1;
    }
    else
    {
        move = 0;
    }
    printf("Enter the no of cylinders:\n");
    scanf("%d",&size);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        
        {
            if(RQ[j]>RQ[j+1])
            {
                temp = RQ[j];
                RQ[j] = RQ[j+1];
                RQ[j+1] = temp;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        if(in<RQ[i])
        {
            index = i;
            break;
        }
    }

    if(move == 1)
    {
        for(i=index;i<n;i++)
        {
            total = total + abs(RQ[i]-in);
            printf("(%d-%d)+",RQ[i],in);
            in = RQ[i];
        }

        total = total + abs(size-RQ[i-1]-1);
        printf("(%d-%d)+",size,RQ[i]);
        in = size-1;



        for(i=index-1;i>=0;i--)
        {
             total = total + abs(RQ[i]-in);
             printf("(%d-%d)",RQ[i],in);
            in = RQ[i];
        }

    }

    if(move == 0)
    {
        for(i=index-1;i>=0;i--)
        {
            total = total + abs(RQ[i]-in);
            printf("(%d-%d)+",RQ[i],in);
            in = RQ[i];
            
        }

        total = total + abs(RQ[i+1]-0);
        printf("(%d-0)+",RQ[i+1]);
        in = 0;

        for(i=index;i<n;i++)
        {
            total = total + abs(RQ[i]-in);
            printf("(%d-%d)",RQ[i],in);
            in = RQ[i];
        }

    }
    printf("\nThe Total Head Movement is: %d\n",total);

}
void cscan()
{
    int prev,move,size,index;
     printf("Enter the number of Requests: \n");
    scanf("%d",&n);
    printf("Enter the sequence of Requests: \n ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&RQ[i]);
    }

    printf("Enter the initial point: \n");
    scanf("%d",&in);

    printf("Enter the previous request\n");
    scanf("%d",&prev);

    if(in>prev)
    {
        move=1;
    }
    else
    {
        move = 0;
    }
    printf("Enter the no of cylinders:\n");
    scanf("%d",&size);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        
        {
            if(RQ[j]>RQ[j+1])
            {
                temp = RQ[j];
                RQ[j] = RQ[j+1];
                RQ[j+1] = temp;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        if(in<RQ[i])
        {
            index = i;
            break;
        }
    }

    if(move == 1)
    {
        for(i=index;i<n;i++)
        {
            total = total + abs(RQ[i]-in);
            printf("(%d-%d)+",RQ[i],in);
            in = RQ[i];
        }

        total = total + abs(size-RQ[i-1]-1);
        printf("(%d-%d)+",size,RQ[i]);
        in = size-1;

        total = total + abs(size-0-1);
        printf("(%d-%d)+",size,RQ[i]);
        in = 0;

        

        for(i=0;i<index;i++)
        {
             total = total + abs(RQ[i]-in);
             printf("(%d-%d)",RQ[i],in);
            in = RQ[i];
        }

    }

    if(move == 0)
    {
        for(i=index-1;i>=0;i--)
        {
            total = total + abs(RQ[i]-in);
            printf("(%d-%d)+",RQ[i],in);
            in = RQ[i];
            
        }

        
        
        total = total + abs(RQ[i+1]-0);
        printf("(%d-0)+",RQ[i+1]);
        in = 0;

        total = total + abs(0-size-1);
        printf("(0-%d)+",size-1);
        in = size-1;

        for(i=n;i>=0;i--)
        {
            total = total + abs(RQ[i]-in);
            printf("(%d-%d)",RQ[i],in);
            in = RQ[i];
        }

    }
    printf("\nThe Total Head Movement is: %d\n",total);

}
void look()
{
    int prev,move,size,index;
     printf("Enter the number of Requests: \n");
    scanf("%d",&n);
    printf("Enter the sequence of Requests: \n ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&RQ[i]);
    }

    printf("Enter the initial point: \n");
    scanf("%d",&in);

    printf("Enter the previous request\n");
    scanf("%d",&prev);

    if(in>prev)
    {
        move=1;
    }
    else
    {
        move = 0;
    }
    printf("Enter the no of cylinders:\n");
    scanf("%d",&size);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        
        {
            if(RQ[j]>RQ[j+1])
            {
                temp = RQ[j];
                RQ[j] = RQ[j+1];
                RQ[j+1] = temp;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        if(in<RQ[i])
        {
            index = i;
            break;
        }
    }

    if(move == 1)
    {
        for(i=index;i<n;i++)
        {
            total = total + abs(RQ[i]-in);
            printf("(%d-%d)+",RQ[i],in);
            in = RQ[i];
        }
        for(i=index-1;i>=0;i--)
        {
            total = total + abs(RQ[i]-in);
            printf("(%d-%d)+",RQ[i],in);
            in = RQ[i];
        }

    }

    if(move == 0)
    {
        for(i=index-1;i>=0;i--)
        {
            total = total + abs(RQ[i]-in);
            printf("(%d-%d)+",RQ[i],in);
            in = RQ[i];
        }
        for(i=index;i<n;i++)
        {
            total = total + abs(RQ[i]-in);
            printf("(%d-%d)+",RQ[i],in);
            in = RQ[i];
        }

    }
    printf("\nThe Total Head Movement is: %d\n",total);

}





