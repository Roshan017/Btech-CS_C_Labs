#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>

char t1[20], t2[20], t3[20], t4[20], address[10], label[20], opcode[20],
    operand[20], length[10], size[10], a[10], ad[10], str_addr[20];

int s = -1, o = -1, i, j;

FILE *fp1, *fp2, *fp3, *fp4, *fp5, *fp6;

struct SYMTAB
{
    char label[10];
    char addr[10];
} ST[30];

struct OPTAB
{
    char opcode[10];
    char hexcode[10];
} OT[30];

void read_OPTAB()
{
    while (1)
    {
        o++;
        fscanf(fp3, "%s%s", OT[o].opcode, OT[o].hexcode) ;
        if (getc(fp3) != EOF) 
        {
        break;
    }
    }
}
void read_SYMTAB()
{
    while (1)
    {
        s++;
        fscanf(fp2, "%s%s", ST[s].label, ST[s].addr);
         if (getc(fp2) != EOF) 
         {
         break;
    }
}
}

void read_line()
{
    strcpy(t1, "");
    strcpy(t2, "");
    strcpy(t3, "");
    strcpy(t4, "");

    fscanf(fp1, "%s", t1);

    if (fgetc(fp1) != '\n')
    {
        fscanf(fp1, "%s", t2);

        if (fgetc(fp1) != '\n')
        {
            fscanf(fp1, "%s", t3);

            if (fgetc(fp1) != '\n')
            {
                fscanf(fp1, "%s", t4);
            }
        }
    }

    if (strcmp(t1, "") != 0 && strcmp(t2, "") != 0 && strcmp(t3, "") != 0 && strcmp(t4, "") != 0)
    {
        strcpy(address, t1);
        strcpy(label, t2);
        strcpy(opcode, t3);
        strcpy(operand, t4);
    }
    else if (strcmp(t1, "") != 0 && strcmp(t2, "") != 0 && strcmp(t3, "") != 0 && strcmp(t4, "") == 0)
    {
        strcpy(address, t1);
        strcpy(label, "");
        strcpy(opcode, t2);
        strcpy(operand, t3);
    }
    else if (strcmp(t1, "") != 0 && strcmp(t2, "") != 0 && strcmp(t3, "") == 0 && strcmp(t4, "") == 0)
    {
        if (strcmp(t1, "END") == 0)
        {
            strcpy(address, "");
            strcpy(label, "");
            strcpy(opcode, t1);
            strcpy(operand, t2);
        }
        else
        {
            strcpy(address, t1);
            strcpy(label, "");
            strcpy(opcode, t2);
            strcpy(operand, "");
        }
    }
}


int main()
{
    fp1 = fopen("intermed.txt","r");
    fp2 = fopen("symtab.txt","r");
    fp3 = fopen("optab.txt","r");
    fp4 = fopen("length.txt","r");
    fp5 = fopen("assmlist.txt","w");
    fp6 = fopen("objcode.txt","w");

    fscanf(fp4,"%s%s",length,size);
    read_OPTAB();
    read_SYMTAB();

    fscanf(fp1,"%s%s%s",label,opcode,operand);
    strcpy(str_addr,operand);

    if(strcmp(opcode,"START")==0)
    {
        fprintf(fp5,"%s%s%s",label,opcode,operand);
        fprintf(fp6,"H^%s  ^00%s^0000%s",label,opcode,operand);
        fprintf(fp6,"T^00%s^%s",operand,size);
        read_line();
    }

    while(strcmp(opcode,"END")!=0)
    {
        if(strcmp(opcode,"BYTE")==0)
        {
            fprintf(fp5,"%s\t%s\t%s\t%s\t",address,label,opcode,operand);
            sprintf(ad,"%x",operand[2]);
            fprintf(fp5,"%s\n",ad);
            fprintf(fp6,"^%s",ad);
    
        }
        else if(strcmp(opcode,"WORD")==0)
        {
            sprintf(a,"%x",atoi(operand));
            fprintf(fp5,"%s\t%s\t%s\t%s\t00000%s\n",address,label,opcode,operand,a);
            fprintf(fp6,"00000%s",a);

        }

        else if(strcmp(opcode,"RESW")==0 || strcmp(opcode,"RESB")==0)
        {
                        fprintf(fp5,"%s\t%s\t%s\t%s\n",address,label,opcode,operand);

        }

        else{
            j=0;
            while(strcmp(opcode,OT[j].opcode)!=0)
            j++;

            i=0;
            while(strcmp(operand,ST[i].label)!=0)
            i++;


            fprintf(fp5,"%s\t%s\t%s\t%s\t%s%s\n",address,label,opcode,operand,OT[j].hexcode,ST[i].addr);
            fprintf(fp6,"%s%s",OT[j].hexcode,ST[i].addr);
        }
        read_line();
    }
   fprintf(fp5,"\t%s\t%s\t%s",label,opcode,operand);
   fprintf(fp6,"\nE^00%s",str_addr);
   getch();

}