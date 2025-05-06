//Roshan P Mathew
//EXPERIMENT 10
//CLIENT SIDE

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
struct{
 char to[45],from[45],sub[45],message[100];
 }email;
void main()
{
  printf("\nClient side");
  char buffer[50]="";
  int sskt=socket(AF_INET,SOCK_STREAM,0);
  struct sockaddr_in addr1;
  int addr2_size=sizeof(addr1);
  addr1.sin_family=AF_INET;
  addr1.sin_addr.s_addr=INADDR_ANY;
  addr1.sin_port=7800;
  int errno=connect(sskt,(struct sockaddr*)&addr1,sizeof(addr1));
  while(1)
  {
   EMAIL: printf("Enter recepient mail: ");
          scanf("%s",email.to);
          if(strcmp(email.to,"")==0)goto EMAIL;
          printf("Enter sender mail: ");
          scanf("%s",email.from);
          getchar();
          printf("enter email subject: ");
          scanf("%[^\n]s",email.sub);
          getchar();
          printf("Enter email message: ");
          scanf("%[^\n]s",email.message);
          getchar();
          send(sskt,email.to,sizeof(email.to),0);
          send(sskt,email.from,sizeof(email.from),0);
          send(sskt,email.sub,sizeof(email.sub),0);
          send(sskt,email.message,sizeof(email.message),0);
          recv(sskt,buffer,sizeof(buffer),0);
          printf("\n\nDomain name:%s",buffer);
   };
   close(sskt);
}


