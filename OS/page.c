#include<stdio.h>
int n,rs[100],count,f,i,j,k,m[10] ,pf=0;
void fifo();
void lru();
void op();

void main()
{

    
    int opt;
    do{
    printf("\nChoose option\n1.FIFO\n2.LRU\n3.OPTIMAL\n4.Exit");
    scanf("%d",&opt);
    
        switch(opt)
        {
            case 1: 
            fifo();
            break;

            case 2: 
            lru();
            break;

            case 3: 
            op();
            break;

            default:
            break;
        }
    } while(opt!=4);
}

    void fifo()
    {
    printf("\nEnter the length of reference string: \n");
    scanf("%d",&n);
    printf("Enter the reference string: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&rs[i]);
    }
    printf("Enter the no of frames: \n");
    scanf("%d",&f);
    for(i=0;i<f;i++)
    {
        m[i] = -1;
    }

    for(i=0;i<n;i++)
    {

        for(k=0;k<f;k++)
        {

            if(m[k] == rs[i])
            {
                break;
            }
        }

        if(k==f)
        {
            m[count++] = rs[i];
            pf++;
        }

        for(j=0;j<f;j++)
        printf("\t%d",m[j]);
        if(k==f)
        {
        printf("\tPf No: %d",pf);
        }
        printf("\n");
        
        if(f==count)
        {
            count = 0;
        }
    }
    printf("\nTotal Page faults = %d",pf);

}

void lru()
{
    int flag[100],ct[100],next=0;
    printf("\nEnter the length of reference string: \n");
    scanf("%d",&n);
    printf("Enter the reference string: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&rs[i]);
        flag[i] = 0;
    }
    printf("Enter the no of frames: \n");
    scanf("%d",&f);
    for(i=0;i<f;i++)
    {
        m[i] = -1;
        ct[i] = 0;
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<f;j++)
        {
            if(m[j] == rs[i])
            {
                flag[i] = 1;
                ct[j] = next;
                next++;
            }
        }

        if(flag[i]==0)
        {
            if(i<f)
            {
                m[i] = rs[i]; 
                ct[i] = next;
                next++;
            }

            else{

                int min=0;
                for(j=1;j<f;j++)
                if(ct[min] > ct[j])
                min = j;
                m[min] = rs[i];
                ct[min]  = next;
                next++;


            }
            pf++;
        }
        for(j=0;j<f;j++)
        printf("\t%d",m[j]);
        if(flag[i]==0)
        printf("\tPf no %d",pf);
        printf("\n");

        
    }

    printf("\nTotal no of Page faults is : %d",pf);
    


}

void op()
{
    int f1,f2,temp[100],pos,max,f3;
    printf("\nEnter the length of reference string: \n");
    scanf("%d",&n);
    printf("Enter the reference string: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&rs[i]);
        
    }
    printf("Enter the no of frames: \n");
    scanf("%d",&f);

    for(i=0;i<f;i++)
    {
        m[i] = -1;
    }

    for(i=0;i<n;i++)
    {
        f1=f2=0;
        for(j=0;j<f;j++)
        {
            if(m[j] == rs[i] )
            {
                f1=f2=1;
                break;
            }
        }

        if(f1==0)
        {
            for(j=0;j<f;j++)
            {
                if(m[j]==-1)
                {
                    pf++;
                    m[j] = rs[i];
                    f2=1;
                    break;
                }
            }
        }

        if(f2==0)
        {
            f3=0;
            
            for(j=0;j<f;j++)
            {
                temp[j] = -1;

                for(k=i+1;k<n;k++)
                {
                    if(m[j] == rs[k])
                    {
                        temp[j] = k;
                        break;
                    }
                }
            }            
        

        if(f3==0)
        {
            max=temp[0];
            pos=0;

            for(j=1;j<f;j++)
            {
                if(temp[j]>max){
                    max=temp[j];
                    pos = j;
                }
            }
        }
        m[pos] = rs[i];
        pf++;
        }

     printf("\n");
    for(j=0;j<f;j++)
    {
        printf("%d\t",m[j]);
    }
    if(f1==0||f2==0)
    {
        printf("\tPf NO : %d",pf);
    }
    }
    printf("
    \nTotal no page faults is: %d",pf);
}