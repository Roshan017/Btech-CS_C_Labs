//Roshan P Mathew 51
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
void main()
{
  int fd1[2],fd2[2];
  int pipe11=pipe(fd1);
  int pipe22=pipe(fd2);
  int flag=0,count;
  char word[20],palindrome[20],temp[20],result[20];
  if(pipe11==0 &&pipe22==0)
  {
    pid_t pid=fork();
    if(pid>0)
    {
       printf("\nParent process\n");
       close(fd1[0]);
       printf("Enter word to be checked: ");
       scanf("%s",word);
       write(fd1[1],word,sizeof(word));
       sleep(5);
       close(fd2[1]);
       read(fd2[0],palindrome,sizeof(palindrome));
       printf("%s",palindrome);
     }
     else if(pid==0)
     {
       sleep(7);
       printf("Child process\n");
       close(fd1[1]);
       read(fd1[0],temp,sizeof(temp));
       count=strlen(temp);
       for(int i=0;i<(count/2);i++)
       {
         if(temp[i]==temp[count-i-1])
         {
           flag=1;
         }
         else
         {
           flag=0;
           break;
         }
       }
       close(fd2[0]);
       if(flag==0)
       {
         sprintf(result,"Not palindrome");
       }
       else
       {
         sprintf(result,"Palindrome");
       }
       write(fd2[1],result,sizeof(result));
     }
  }
   else
   {
     printf("Error creating pipe");
   }
}

