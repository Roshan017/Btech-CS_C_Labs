//Roshan P Mathew
//51
//Client
//UDP
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main()
{

	printf("Client Side:- \n");
	char buffer[50];
	int sockfd;
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = 3008;
	connect(sockfd,(struct sockaddr*)&addr, sizeof(addr));
	int s  = sizeof(struct sockaddr_in);
	do
	{
		printf("Sending Message to Server:- \n");
		scanf("%s",buffer);
		sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr *)&addr,s);
		recvfrom(sockfd,buffer,sizeof(buffer), 0,(struct sockaddr *)&addr,&s);
		printf("Recieved From Server: %s\n",buffer);
		
	}
	
	while(strcmp(buffer,"stop")!=0);
	close(sockfd);
	
}

/*Output
Client Side:- 
Sending Message to Server:- 
hi
Recieved From Server: hello
Sending Message to Server:- 
how_are_you
Recieved From Server: fine
Sending Message to Server:- 
thank_you
Recieved From Server: stop

*/

