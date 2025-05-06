//Roshan P Mathew
//EXPERIMENT 10
//SERVER SIDE

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
  printf("\nServer side");
  char buffer[50]="",domainName[50]="";
  int sskt=socket(AF_INET,SOCK_STREAM,0);
  struct sockaddr_in addr1,addr2;
  int addr2_size=sizeof(addr2);
  addr1.sin_family=AF_INET;
  addr1.sin_addr.s_addr=INADDR_ANY;
  addr1.sin_port=7800;
  bind(sskt,(struct sockaddr*)&addr1,sizeof(addr1));
  listen(sskt,5);
  int cskt=accept(sskt,(struct sockaddr*)&addr2,(&addr2_size));
  printf("connection established");
  while(1)
  {
    recv(cskt,email.to,sizeof(email.to),0);
    recv(cskt,email.from,sizeof(email.from),0);
    recv(cskt,email.sub,sizeof(email.sub),0);
    recv(cskt,email.message,sizeof(email.message),0);
    printf("\n\nclient request mail:\nto:%s\nfrom:%s\nsub:%s\nmessage:%s\n",email.to,email.from,email.sub,email.message);
    char *domain=strchr(email.to,'@');
    if(domain==NULL)
    {
      send(cskt,"INVALID TO ADDRESS",sizeof(buffer),0);
    }
    else
    {
      strcpy(buffer,domain);
      strcpy(buffer,index(buffer,buffer[1]));
      int len=1;
      for(int i=0;i<strlen(buffer);i++)
      { 
        if(buffer[i]=='.')
        {
          len=i;
          break;
        }
      }
      if(len==-1)
      {
        send(cskt,"INVALID TO ADDRESS",sizeof(buffer),0);
      }
      else
      {
        strncpy(domainName,buffer,len);
        send(cskt,domainName,sizeof(domainName),0);
      }
    }
  }
  close(sskt);
  close(cskt);
}

