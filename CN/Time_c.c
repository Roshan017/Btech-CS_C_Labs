#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
int main()
{
  printf("\nClient side:-");
  char buffer[100];
  int sockfd;
  sockfd=socket(AF_INET,SOCK_DGRAM,0);
  struct sockaddr_in addr;
  addr.sin_family=AF_INET;
  addr.sin_addr.s_addr=INADDR_ANY;
  addr.sin_port=9000;
  int s=sizeof(struct sockaddr_in);
  connect(sockfd,(struct sockaddr*)&addr,sizeof(addr));
  do
  {
    printf("\nSend request for time:\n");
    scanf("%s",buffer);
    sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&addr,s);
    recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&addr,&s);
    printf("\nResponse from server: %s",buffer);
  }
  while(strcmp(buffer,"stop")!=0);
  close(sockfd);
}


