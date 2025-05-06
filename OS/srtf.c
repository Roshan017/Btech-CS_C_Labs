#include<stdio.h>
#include<stdlib.h>

struct process
{
    int pid,at,bt,wt,ct,tat,st;
};


int main()
{
    int n,i;
    float atat=0,awt=0;
    int idle_time=0;
    struct process p[6];
    int bt_remain[100];
    int is_comp[100];
    int current_time=0;
    int completed=0;
    int prev=0;



    printf("Enter the No of Processess: \n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter the Arrival Time of P%d: ",i+1);
        scanf("%d",&p[i].at);
        printf("Enter the burst Time of P%d: ",i+1);
        scanf("%d",&p[i].bt);
       // cout <<endl;
    }
    for(i=0;i<n;i++)
    {
        bt_remain[i] = p[i].bt;
        p[i].pid=i+1;
        is_comp[i]=0;
    }

    
    printf("Pid\tAT\tBT\tCT\tWT\tTAT\t\n");
    while(completed!=n)
    {
        int idx=-1;
        int min=9999999;
        //printf("qds");

        for(i=0;i<n;i++)
        {
            if((p[i].at<=current_time) && (is_comp[i]==0))
            {
                if(bt_remain[i]<min)
                {
                    min=bt_remain[i];
                    idx=i;
                }

                if(bt_remain[i]==min)
                {
                        if(p[i].at<p[idx].at)
                        {
                            min=bt_remain[i];
                            idx=i;
                        }
                }
                
            }



        }

        if(idx!=-1)
        {
            //printf("hh");
            if(p[idx].bt == bt_remain[idx])
            {
                p[idx].st = current_time;
                idle_time += p[idx].st - prev;
            }

            bt_remain[idx]--;
            current_time++;
            prev= current_time;

            if(bt_remain[idx]==0)
            {
                p[idx].ct = current_time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat-p[idx].bt;

                awt += p[idx].wt;
                atat+=p[idx].tat;

                is_comp[idx] = 1;
                printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[idx].pid,p[idx].at,p[idx].bt,p[idx].ct,p[idx].wt,p[idx].tat);
                completed++;
            }


        }

        else{
            current_time++;
        }
        
        
    }

    awt = (float)awt/n;
    atat = (float)atat/n;

    
   /* for(int j=0;j<n;j++)
    {
        
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[j].pid,p[j].at,p[j].bt,p[j].ct,p[j].wt,p[j].tat);
    }*/

    printf("Average Wating time:%f \n",awt);
    printf("Average Turnaround time:%f\n",atat);

}
