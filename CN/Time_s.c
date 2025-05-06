#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
void main()
{
  printf("\nServer side:-");
  char buffer[100];
  int sockfd;
  time_t rawtime;
  struct tm *info;
  struct sockaddr_in addr;
  addr.sin_family=AF_INET;
  addr.sin_addr.s_addr=INADDR_ANY;
  addr.sin_port=9000;
  int s=sizeof(struct sockaddr_in);
  sockfd=socket(AF_INET,SOCK_DGRAM,0);
  bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
  do
  {
    printf("\nConnection established\n");
    printf("\nWaiting for request from client: \n");
    recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&addr,&s);
    printf("%s",buffer);
    time(&rawtime);
    info=localtime(&rawtime);
    sprintf(buffer,"\nDate and Time is :%s\n",asctime(info));
    sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&addr,s);
  }
  while(1==1);
  close(sockfd);
}

