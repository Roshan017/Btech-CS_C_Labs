#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
    unsigned int hex,start;

    int i,j;
    FILE *fp1,*fp2;
    char line[20],addr[20];

        
    fp1 = fopen("Input.txt","r");
    printf("Enter the actual starting Address: \n");
    scanf("%x",&start);
    


    do{
        fscanf(fp1,"%s",line);
        
        if(line[0]=='T')
        {
            for(i=1,j=0;i<7;i++,j++)
                addr[j] = line[i];
            addr[j] = '\0';


            fp2= fopen("temp.txt","r+");
            fprintf(fp2,"%s",addr);
            rewind(fp2);

            fscanf(fp2,"%x",&hex);
            fclose(fp2);
            i=9;

            while(line[i] != '\0')
            {
                printf("%x  \t%c%c\n",hex+start,line[i],line[i+1]);
                hex++;
                i=i+2;
            }

        
        }
        if(line[0]=='E')
        {
        printf("Redirecting to start: %x\n",start);
        }
    }while(!feof(fp1));
    fclose(fp1);
    
}