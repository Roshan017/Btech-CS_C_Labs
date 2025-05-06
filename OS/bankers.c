#include<stdio.h>
#include<stdbool.h>

#define max 10

void main()

{

    int i,k,j,n,m,P[max],alloc[max][max],need[max][max],Max[max][max],avail[max],sq[max];
        int finish[max]={0},idx;
    printf("Enter the no of Processes:-\n");
    scanf("%d",&n);
    printf("Enter the no of Resources:-\n");
    scanf("%d",&m);
    printf("Enter Process Ids:-\n");
    for(i=0;i<n;i++)
    {
        
        scanf("%d",&P[i]);
    }


    for(i=0;i<n;i++)
    {
        printf("Enter the Allocation for Process%d\n",i+1);

        for(j=0;j<m;j++)
        {
            printf("For Resorce%d:\n",j);
            scanf("%d",&alloc[i][j]);
        }
    }

    for(i=0;i<n;i++)
    {
        printf("Enter the Max for Process%d\n",i);

        for(j=0;j<m;j++)
        {
            printf("For Resorce%d:\n",j);
            scanf("%d",&Max[i][j]);
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j] = Max[i][j] - alloc[i][j];
        }
    }

    printf("Enter the Available Matrix:- \n");
    for(i=0;i<m;i++)
    {
        scanf("%d",&avail[i]);
    }
        

    int y=0;
    for(k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        { 
            if(finish[i]==0)
            { 
                int flag = 0; 
                for(int j=0;j<m;j++)
                { 
            if(need[i][j]>avail[j])
            { 
        flag = 1; //if needed resources are more in number than the available ones, move to the next process
          break; 
                }
                } 
                
                if(flag==0)
                {  //if available resources fulfilled the need
                    sq[idx++] = i; //the index of process, that has been allocated the resources
                    for(int y=0;y<m;y++)
                    { 
                        avail[y] += alloc[i][y]; 
                    }
                    finish[i] = 1; 
                } 
            } 
        } 
    
    }
    bool flag = true;
    for(int i=0; i<n; i++)
    {
        if(finish[i] == 0)
        { 
            flag = false; 
            printf("System is in deadlock !!"); break; 
        }
    }
    
    if(flag==true)
    {
        printf("System is in safe state and following is the safe sequence: \n");
        for(int i=0;i<n-1;i++)
        {
            printf("P%d->",sq[i]); 
        }
        printf("P%d->END",sq[n-1]);
    }  

int n1,R_need[max];
printf("Resource request:-\n");
printf("Enter the Process id: \n");

scanf("%d",&n1);

printf("Enter the Resource need: \n");
for(i=0;i<m;i++)
{
    scanf("%d",&R_need[i]);
}

for(i=0;i<m;i++)
{
    avail[i] = avail[i] - R_need[i];
    alloc[n1][i] = alloc[n1][i] + R_need[i];
    need[n1][i]  = need[n1][i] - R_need[i];
}
for(i=0;i<n;i++)
{
    finish[i]=0;
}
for(k=0;k<n;k++)
{
for(int i=0;i<n;i++)
        { 
            if(finish[i]==0)
            { 
                int flag = 0; 
                for(int j=0;j<m;j++)
                { 
            if(need[i][j]>avail[j])
            { 
        flag = 1; //if needed resources are more in number than the available ones, move to the next process
          break; 
                }
                } 
                
                if(flag==0)
                {  //if available resources fulfilled the need
                    sq[idx++] = i; //the index of process, that has been allocated the resources
                    for(int y=0;y<m;y++)
                    { 
                        avail[y] += alloc[i][y]; 
                    }
                    finish[i] = 1; 
                } 
            } 
        } 
}
         bool flag1 = true;
    for(int i=0; i<n; i++)
    {
        if(finish[i] == 0)
        { 
            flag1 = false; 
            printf("Access Denied"); break; 
        }
    }
    
    if(flag1==true)
    {
        printf("Access Granted,System is in safe state and following is the safe sequence: \n");
        for(int i=0;i<n-1;i++)
        {
            printf("P%d->",sq[i]); 
        }
        printf("P%d->END",sq[n-1]);
    }  

    
}