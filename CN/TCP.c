//Roshan P Mathew 51
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
	int sockfd,newsocket;
	struct sockaddr_in addr1,addr2;
	addr1.sin_family=AF_INET;
	addr1.sin_addr.s_addr = INADDR_ANY;
	addr1.sin_port = 3008;
	int s  = sizeof(struct sockaddr_in);
	sockfd = socket(AF_INET,SOCK_STREAM ,0);
	bind(sockfd,(struct sockaddr*) & addr1,sizeof(addr1));
	listen(sockfd,5);
	newsocket = accept(sockfd,(struct sockaddr*)&addr2,(&s));
	
	do{
		printf("Connection Established:\n");
		
		recv(newsocket,buffer,sizeof(buffer),0);
		printf("\nRecieving Message From Client: %s",buffer);

		printf("\nEnter the Message: ");
		scanf("%s",buffer);
		send(newsocket,buffer,sizeof(buffer),0);
		
	}
	while(strcmp(buffer,"stop")!=0);
	close(sockfd);
	
        

}

/*Server side:-
Connection Established:

Recieving Message From Client: 

Heloo
Enter the Message: hi
Connection Established:

Recieving Message From Client: 

Byee
Enter the Message: welcome
Connection Established:

Recieving Message From Client: 

thanks
Enter the Message: stop
*/
