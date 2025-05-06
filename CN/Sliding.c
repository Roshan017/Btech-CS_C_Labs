//ROSHAN P MATHEW
//Go Back Sliding Window
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct Frame{
int seqNo;
int ack;
}frame;
int checkAck()
{
	return rand()%2;
}
void main()
{
	int n, windowSize;
	printf("Enter the window size: ");
	scanf("%d",&windowSize);
	printf("\n Enter the number of frames to send: ");
	scanf("%d",&n);
	frame f[n];
	printf("\n");
	for(int i = 0 ; i<n;i++)
	{
		f[i].seqNo = i ;
		f[i].ack = -1;
	}
	int x;
printf("\n Transmitting data: \n");
for (int i = 0; i < n; i = x)
{
    if (i + windowSize >= n)
        x = n;
    else
        x = i + windowSize;
    
    for (int j = i; j < x; j++)
    {
        printf("Sending frame %d\n", f[j].seqNo);
    }
    printf("\n\n");

    for (int j = i; j < x; j++)
    {
        f[j].ack = checkAck();
        sleep(1);
        if (f[j].ack)
        {
            printf("Received ack for frame %d\n", f[j].seqNo);
        }
        else
        {
            printf("Didn't receive ack for frame %d\n", f[j].seqNo);
            sleep(1);
            x = j;
            break;
        }
    }
}
}

/*Enter the window size: 10

 Enter the number of frames to send: 5


 Transmitting data: 
Sending frame 1
Sending frame 2
Sending frame 3
Sending frame 4


Received ack for frame 1
Didn't receive ack for frame2
Sending frame 1
Sending frame 2
Sending frame 3
Sending frame 4


Received ack for frame 1
Received ack for frame 2
Received ack for frame 3
Received ack for frame 4
Finished transmitting the Data
*/
