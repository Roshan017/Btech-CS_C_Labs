#include<stdio.h>
#include<stdlib.h>

void fcfs ();
void sjf();
void priorty();
void rr();

int n, bt[20], at[20], P[20], wt[20], tat[20], total_WT, total_TAT;
float awt = 0, atat = 0;

int
main ()
{


  printf ("Enter the no of Process: \n");
  scanf ("%d", &n);
  int i;
  printf ("Enter Process name: \n");
  for (i = 0; i < n; i++)
    {
      scanf ("%d", &P[i]);
    }
  for (i = 0; i < n; i++)
    {
      printf ("Enter the arrival time and burst time of P%d: \n", i);
      scanf ("%d", &at[i]);
      scanf ("%d", &bt[i]);
    }
  int opt;
  do
    {
      printf
	("Choose the Scheduling to be done:\n\t1.FCFS\n\t2.SJF\n\t3.Priorty\n\t4.Round Robin\n\t5.Exit\n");
      scanf ("%d", &opt);
      switch (opt)
	{
	case 1:
	  fcfs ();
	  break;

	case 2:
	  sjf();
	  break;

	case 3:
	  priorty();
	  break;

	case 4:
	  rr();
	  break;

	default:
	  break;
	}
    }
  while (opt != 5);
}

void
fcfs ()
{
  int sum = 0, ct[20], j, k;

  for (int j = 0; j < n; j++)
    {
      sum += bt[j];
      ct[j] += sum;
    }
  for (int k = 0; k < n; k++)
    {
      tat[k] = ct[k] - at[k];
      total_TAT += tat[k];
    }
  for (int k = 0; k < n; k++)
    {
      wt[k] = tat[k] - bt[k];
      total_WT += wt[k];
    }
  awt = (float) total_WT / n;
  atat = (float) total_TAT / n;
  printf ("Scheduling.... \n\n");
  printf ("Processes\t AT\t BT\t CT\t WT\t TAT\t\n\n");

  for (int i = 0; i < n; i++)
    {
      printf ("P%d\t\t %d\t %d\t %d\t %d\t %d\n", i + 1, at[i], bt[i], ct[i],
	      wt[i], tat[i]);
    }

  printf ("\n\nAverage Turnaround Time = %f\n", awt);
  printf ("Average WT = %f\n\n", atat);
}

void sjf ()
{
  int t,i, k, j,tp[20],sum=0;

  for(i=0;i<n;i++)
  {
      bt[i] = tp[i];
  }



  for (j = 0; j < n; j++)
    {
      sum+=tp[j];
    if(at[ j]<=sum){

      for (k = 0; k < n - j - 1; k++)
          {
            if (bt[k] > bt[k + 1])
              {
                t = bt[k];
                bt[k] = bt[k + 1];
                bt[k + 1] = t;

                t = at[k];
                at[k] = at[k + 1];
                at[k + 1] = t;

                t = P[k];
                P[k] = P[k + 1];
                P[k + 1] = t;
              }
          }
      }

    }
  printf ("\n\tProcessNo\tAT\tBT\tWT\tTAT\t\n");

  for (j = 0; j < n; j++)
    {
      wt[j] = 0;
      tat[j] = 0;

      for (k = 0; k < n; k++)
	{
	  wt[k] += wt[k] + bt[k];
	}

      tat[j] = wt[j] + bt[j];
      total_WT += wt[j];
      total_TAT += tat[j];
    }

  awt = (float) total_WT / n;
  atat = (float) total_TAT / n;
  for (j = 0; j < n; j++)
    {
      printf ("\t%d\t\t%d\t%d\t%d\t%d\t\n", P[j], at[j], bt[j], wt[j],
	      tat[j]);
    }

  printf ("Average Waiting time is: %f\n", awt);
  printf ("Average Turn Around time is: %f\n", atat);
}

void priorty(){

    int i,j,pr[20],pos,t;

    printf("Enter the Priorty of the Processes:-\n");

    for(i=0;i<n;i++)
    {
        printf("Priorty of P%d\n",i);
        scanf("%d",&pr[i]);
    }
    
    for(i=0;i<n;i++)
    {
        

        for(j=0;j<n-i-1;j++)
        {
            if(pr[j]>pr[j+1])
            {
            t=pr[j];
            pr[j] = pr[j+1];
            pr[j+1] = t;
            
            t = bt[j];
            bt[j] = bt[j + 1];
            bt[j + 1] = t;

            t = at[j];
            at[j] = at[j + 1];
            at[i + 1] = t;

            t = P[j];
            P[j] = P[j + 1];
            P[j + 1] = t;
    }
        }
    }

            
            printf ("\n\tProcessNo\tAT\tBT\tPr\tWT\tTAT\t\n");

            for(i=0;i<n;i++)
            {
                wt[i] = 0;
                tat[i] = 0;

                for(j=0;j<i;j++)
                {
                    wt[i] = wt[i]+ bt[j];
                }

                tat[i] = wt[i] + bt[i];
                total_WT += wt[i];
                total_TAT += tat[i];
            }




    awt = (float) total_WT / n;
    atat = (float) total_TAT / n;
    for (j = 0; j < n; j++)
    {
      printf ("\t%d\t\t%d\t%d\t%d\t%d\t%d\t\n", P[j], at[j], bt[j],pr[j], wt[j],
	      tat[j]);
    }

    printf ("Average Waiting time is: %f\n", awt);
    printf ("Average Turn Around time is: %f\n", atat);
}

void rr()
{
    int rem_bt[10],sq=0,count=0,i,j,k,qt,t;
    printf("Enter the Quantum time: \n ");
    scanf("%d",&qt);
    for(i=0;i<n;i++)
    {
        rem_bt[i] = bt[i];
    }
    while(1)
    {
        for(i=0,count=0;i<n;i++)
        {
            if(rem_bt[i]==0)
            {
                count++;
                continue;
            }

            if(rem_bt[i]>qt){
                rem_bt[i] = rem_bt[i]-qt;
            }
            else{

                if(rem_bt[i]>=0)
                {
                    t = rem_bt[i];
                    rem_bt[i] = 0;
                }

                sq = sq+t;
                tat[i] = sq;
            }
        }

        if(n==count)
        {
            break;
        }
    }
    printf ("\n\tProcessNo\tAT\tBT\tWT\tTAT\t\n");

            for(i=0;i<n;i++)
            {
                wt[i] = tat[i] - bt[i];
                total_WT += wt[i];
                total_TAT += tat[i];
            }




    awt = (float) total_WT / n;
    atat = (float) total_TAT / n;
    for (j = 0; j < n; j++)
    {
      printf ("\t%d\t\t%d\t%d\t%d\t%d\t\n", P[j], at[j], bt[j], wt[j],
	      tat[j]);
    }

    printf ("Average Waiting time is: %f\n", awt);
    printf ("Average Turn Around time is: %f\n", atat);
}
    


