#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>




int main()
{

    int fd1[2],fd2[2],fd3[2],n,i,sum=0;
    int p1msg[10],p2msg[10],p3msg[10],readmsg[10];

    pid_t p,p2;
    pipe(fd1);
    pipe(fd2);
    pipe(fd3);
    printf("\n\tProcess1:- Getting elements: \n");
    printf("Enter the no of digits: \n");
    scanf("%d",&n);
    printf("Enter the elements: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p1msg[i]);
    }
    p = fork();

    if(p>0)
    {
            close(fd1[0]);//close rside of p1
            close(fd3[1]);//close wside of p3

            printf("Writing to pipe1: \n");
            write(fd1[1],p1msg,sizeof(p1msg));
            read(fd3[0],readmsg,sizeof(readmsg));
            printf("\n\tProcess1:-The sum of squares of the digits are: \n");
            printf("\t%d\n",readmsg[0]);
    }
    else
    {
    p2 = fork();
    if(p2>0)
    {
        close(fd2[0]);
        close(fd1[1]);
        read(fd1[0],readmsg,sizeof(readmsg));
        printf("\n\tProcess2:- Reading from Pipe1\n");
          for(i-0;i<n;i++)
        {
            printf("%d\t",readmsg[i]);
        }
        printf("\n\tSquaring the elements: \n");
        for(i=0;i<n;i++)
        {
            p2msg[i] = readmsg[i] * readmsg[i];
        }
        printf("\tWriting elements to Pipe2: \n");
        write(fd2[1],p2msg,sizeof(p2msg));
    }
    else
    {
        close(fd3[0]);
        close(fd2[1]);
        read(fd2[0],readmsg,sizeof(readmsg));
        printf("\n\tProcess3:- Reading from Pipe2: Message \n");
        for(i=0;i<n;i++)
        {
            printf("\t%d",readmsg[i]);
        }
        printf("\n\tGenerating Sum of elements... \n");
        for ( i = 0; i < n; i++)
        {
            sum = sum + readmsg[i];
        }
        p3msg[0] = sum;
        printf("\n\tWriting to Pipe3: \n");
        write(fd3[1],p3msg,sizeof(p3msg));
        
    }
    }
    return 0;
}
