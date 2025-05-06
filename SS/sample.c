#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node
{
    char name[50];
    bool isDir;
    struct node *c[100];
    int no_child;
    struct node *p;
};

char pwd[20];


struct node *curr = NULL;
struct node *head = NULL;

void ls(){
    int i;
    if(curr->no_child==0)
    {
        printf("Empty Directory!");
        return;
    }

    printf("\nDirectory->%s",pwd);
    for(i=0;i<curr->no_child;i++)
    {
        if(curr->c[i]->isDir)
        {
            printf("\nDir->%s\t",curr->c[i]->name);
            continue;
        }
        printf("\nFile->%s\t",curr->c[i]->name);

    }
}

void create(bool d)
{
    char names[20];
    printf("Enter a Name: \n");
    scanf("%s",names);
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    strcpy(temp->name,names);
    temp->isDir=d;
    temp->p=curr;
    curr->c[curr->no_child]= temp;
    curr->no_child++;

    if(d)
    {
        if(curr==NULL)
        {
            printf("\nDirectory %s has been created as root directory\n",names);

        }
        else{
            printf("\nDirectory %s has been created with parent directory %s",names,pwd);
        }

        
    }
    else{
        printf("\nFile %s has been created in Directory %s",names,pwd);
    }
}

void cd(){
    char names[20];
    printf("Enter the Name of the directory: \n");
    scanf("%s",names);
    for(int i=0;i<curr->no_child;i++)
    {
        if(!strcmp(curr->c[i]->name,names) && (curr->c[i]->isDir))
        {
            curr = curr->c[i];
            printf("\n PWD is now %s",names);
            strcpy(pwd,names);
            return;
        }
    }
    printf("Directory not found\n");
}

void cdup()
{
    if(curr == NULL)
    {
        printf("At Root\n");
        return;
    }

    curr = curr->p;
    printf("\n PWD is %s",curr->name);
    strcpy(pwd,curr->name);
}

void rm(bool d)
{
    char names[20];
    printf("Enter the name: \n");
    scanf("%s",names);
    for(int i = 0 ;i<curr->no_child;i++)
    {
    for((!strcmp(curr->c[i]->name,names)) && (d && curr->c[i]->isDir==true)|| (!d && curr->c[i]->isDir==false) )
    {
        int t = i;
        while(t<curr->no_child-1)
        {
            curr->c[t] = curr->c[t-1];
            t++;
        }

        curr->no_child = (curr->no_child)-1;
        printf("Deleted\n");
        return;
    }
    }

    printf("Not Found\n");
}

void main()
{
    int c;
    head = (struct node*)malloc(sizeof(struct node));
    curr = (struct node*)malloc(sizeof(struct node));

    strcpy(head->name,"Root");
    curr->no_child=0;
    strcpy(curr->name, "Root");
    strcpy(pwd,"root");

    curr->p = NULL;
    curr->isDir = true;  
    do{
		printf("\nTree Structure\n................");
		printf("\n1.Create Directory\n2.Create file\n3.Display all contents\n4.Change directory\n5.Delete file\n6.Delete dir\n7.cdup\n8.Exit\n...............................");
		printf("\nYou are in %s\n",pwd);
		printf("\nEnter the choice: ");
		scanf("%d",&c);
		switch(c){
			case 1:
				create(true);
				break;
			case 2:
				create(false);
				break;
			case 3:
				ls();
				break;
			case 4:
				cd();
				break;
			case 5:
				rm(false);
				break;
			case 6:
				rm(true);
				break;
			case 7:
				cdup();
				break;
			case 8:
				printf("\nExiting\n");
				break;
			default:
				printf("\nInvalud Choice\n");
				break;
		}
	}while(c!=8);
}				
