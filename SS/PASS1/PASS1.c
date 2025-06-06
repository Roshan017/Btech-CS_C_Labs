#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>

char opcode[20],label[20],operand[20],ch,t1[10],t2[10],t3[10];
int i,j,o=-1,s=-1,opd,loctr,start,size=0,len,flag;

FILE *fp1,*fp2,*fp3,*fp4,*fp5;

struct SYMTAB
{
    char label[20];
    int addr;
}ST[30];

struct OPTAB
{
    char opcode[20];
    char hexcode[20];
}OT[30];


void read_OPTAB(){
    while(1)
    {
        o++;
        fscanf(fp2,"%s%s",OT[o].opcode,OT[o].hexcode);

        if(getc(fp2)==EOF)
        {
            break;
        }

    }
}

void read_line()
{
    strcpy(t1,"");
    strcpy(t2,"");
    strcpy(t3,"");


    fscanf(fp1,"%s",t1);
    if(getc(fp1)!='\n')
    {
        fscanf(fp1,"%s",t2);
            if(getc(fp1)!='\n')
            {
                fscanf(fp1,"%s",t3);
            }

    }

    if(strcmp(t1,"")!=0 && strcmp(t2,"")!=0 && strcmp(t3,"")!=0){
        strcpy(label,t1);
        strcpy(opcode,t2);
        strcpy(operand,t3);
    }
    else if(strcmp(t1,"")!=0 && strcmp(t2,"")!=0 && strcmp(t3,"")==0){
        strcpy(label,"");
        strcpy(opcode,t1);
        strcpy(operand,t2);
    }
    else if(strcmp(t1,"")!=0 && strcmp(t2,"")==0 && strcmp(t3,"")!=0){
        strcpy(label,"");
        strcpy(opcode,t1);
        strcpy(operand,"");
    }
}
int main(){
    fp1 = fopen("Input.txt","r");
    fp2 = fopen("optab.txt","r");
    fp3 = fopen("symtab.txt","w");
    fp4 = fopen("intermediate.txt","w");
    fp5 = fopen("length.txt","w");

    read_OPTAB();

    fscanf(fp1,"%s%s%x",label,opcode,&opd);
    if(strcmp(opcode,"START")==0)
    {
        start = opd;
        loctr = start;
        fprintf(fp4,"%s\t%s\t%x",label,opcode,opd);
        read_line();

    }
    else{
        loctr = 0;
    }

    while(strcmp(opcode,"END")!=0)
    {
                fprintf(fp4,"%x\t%s\t%s\t%s",loctr,label,opcode,operand);
                if(strcmp(label,"")!=0)
                {
                    for(i=0;i<s;i++)
                    {
                        if(strcmp(ST[s].label,label)==0)
                        {
                            printf("ERROR");
                            exit(0);
                        }
                    }
                    s++;
                    strcpy(ST[s].label,label);
                    ST[s].addr = loctr;
                }

                flag=0;

                for(i=0;i<o;i++)
                {
                    if(strcmp(opcode,OT[i].opcode)==0)
                    {
                        loctr+=3;
                        size+=3;
                        flag=1;
                        break;
                    }
                }

                if(flag==0)
                {
                    if(strcmp(opcode,"WORD")==0)
                    {
                        loctr+=3;
                        size+=3;
                    }
                    else if(strcmp(opcode,"RESW")==0)
                    
                    {
                        loctr+= 3*(atoi(operand));
                    }

                    else if(strcmp(opcode,"RESW")==0)\
                    {
                        loctr += atoi(operand);
                    }

                    else if(strcmp(opcode,"BYTE")==0)
                    {
                        len = strlen(operand);
                        if(operand[0] == 'C' || operand[0] == 'c')
                        {
                            len = len-3;
                        }
                        else{
                            len = (len-3)/2;
                        }
                        loctr += len;
                        size+=len;

                    }
                }

                read_line();

    }
                fprintf(fp4,"%s\t%s\t%s\n",label,opcode,operand);
                for(i=0;i<s;i++)
                {
                    fprintf(fp3,"%s%s",ST[i].label,ST[i].addr);
                    if(i!=s)
                    {
                        fprintf(fp3,'\n');
                    }

                }

                fprintf(fp5,"%x\n%x",loctr-start,size);

                fclose(fp1);
                fclose(fp2);
                fclose(fp3);
                fclose(fp4);
                fclose(fp5);
}
