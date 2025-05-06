//Roshan P Mathew
//51
//Server
//UDP
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

void main()
{
	printf("Server side:-\n");
	char buffer[50];
	int sockfd;
	struct sockaddr_in addr;
	addr.sin_family=AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = 3008;
	int s  = sizeof(struct sockaddr_in);
	sockfd = socket(AF_INET,SOCK_DGRAM ,0);
	bind(sockfd,(struct sockaddr*) & addr,sizeof(addr));
	
	
	do{
		printf("Connection Established:\n");
		printf("\nRecieving Message From Client:");
		recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr *)&addr,&s);
		printf("%s",buffer);
		printf("\nEnter the Message: ");
		scanf("%s",buffer);
		sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr *)&addr,s);
		
	}
	while(strcmp(buffer,"stop")!=0);
	close(sockfd);
	
        

}

/*Output
Server side:-
Connection Established:

Recieving Message From Client:hi
Enter the Message: hello
Connection Established:

Recieving Message From Client:how_are_you
Enter the Message: fine 
Connection Established:

Recieving Message From Client:thank_you
Enter the Message: stop
*/

