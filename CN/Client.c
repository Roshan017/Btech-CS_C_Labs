//Roshan P Mathew 51
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
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in addr1,addr2;
	addr2.sin_family = AF_INET;
	addr2.sin_addr.s_addr = INADDR_ANY;
	addr2.sin_port = 3008;
	connect(sockfd,(struct sockaddr*)&addr2, sizeof(addr2));
	
	do
	{
		printf("Sending Message to Server:- \n");
		scanf("%s",buffer);
		send(sockfd,buffer,sizeof(buffer),0);
		recv(sockfd,buffer,sizeof(buffer), 0);
		printf("Recieved From Server: %s\n",buffer);
		
	}
	
	while(strcmp(buffer,"stop")!=0);
	close(sockfd);
	
}


/*Client Side:- 
Sending Message to Server:- 
Heloo
Recieved From Server: hi
Sending Message to Server:- 
Byee
Recieved From Server: welcome
Sending Message to Server:- 
thanks
Recieved From Server: stop
*/
