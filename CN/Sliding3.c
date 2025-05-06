//ROSHAN P MATHEW
//STOP AND WAIT SLIDING WINDOW
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct frame{

int data;
int seqNo;
int ack;
}frame;

int checkAck(){
	return rand()%2;
}

int main(){
	int n;
	printf("Input the number of frames to be sent: \n");
	scanf("%d",&n);
	frame f[n];
	for(int i = 0 ;i<n; i++)
	{
		printf("Enter the frame[%d]:",i);
		scanf("%d",&f[i].data);
		f[i].seqNo=i;
		f[i].ack = -1;
	}
	printf("Transmitting Data: \n");
	for(int i = 0; i<n; i++)
	{
		printf("\n Sending frame %d \n",f[i].seqNo);
		f[i].ack= checkAck();
		sleep(1);
		if(f[i].ack)
		{
			printf("Received Ack for frame[%d]",f[i].seqNo);
		}
		else{
			printf(" Not received Ack for frame[%d]",f[i].seqNo);
		}
	}
	printf("\n Transmitting Finished\n");
}

/*Input the number of frames to be sent: 
5
Enter the frame[0]:1
Enter the frame[1]:2
Enter the frame[2]:3
Enter the frame[3]:4
Enter the frame[4]:5
Transmitting Data: 

 Sending frame 0 
Received Ack for frame[0]
 Sending frame 1 
 Not received Ack for frame[1]
 Sending frame 2 
Received Ack for frame[2]
 Sending frame 3 
Received Ack for frame[3]
 Sending frame 4 
Received Ack for frame[4]
 Transmitting Finished
*/
