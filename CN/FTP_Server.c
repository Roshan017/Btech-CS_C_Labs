//Roshan P Mathew
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

void main()
{
	printf("Server Side\n");
	char buffer[50],filename[100],writebuffer[100];
	int sockfd,newsocket;
	struct sockaddr_in addr1,addr2;
	addr1.sin_family=AF_INET;
	addr1.sin_addr.s_addr=INADDR_ANY;
	addr1.sin_port=3008;
	int s = sizeof(struct sockaddr_in);
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	bind(sockfd,(struct sockaddr*)&addr1,sizeof(addr1));
	listen(sockfd,5);
	newsocket=accept(sockfd,(struct sockaddr*)&addr2,(&s));
	do{
		printf("Connection Established\n");
		printf("Recieving Message from Client \n");
		recv(newsocket,buffer,sizeof(buffer),0);
		printf("%s",buffer);
		strcpy(filename,buffer);
		FILE *file1=fopen(filename,"r");
		fscanf(file1,"%[^EOF]%*c",writebuffer);
		fclose(file1);
		send(newsocket,writebuffer,sizeof(writebuffer),0);
	}
	while(strcmp(buffer,"stop")!=0);
	close(newsocket);
	close(sockfd);
}

/*Server Side
Connection Established
Recieving Message from Client 
file1.txtConnection Established
Recieving Message from Client 
*/
