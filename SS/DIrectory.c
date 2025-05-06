//Neil John
//Directory
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
struct dir{
	char name[50],file_name[50][50];
	struct dir *subdir[10];
	int num_subdir,num_files;
};
struct dir root;

struct node{
	char name[100];
	bool isDir;
	struct node *c[100];
	int no_child;
	struct node *p;
};
char pwd[20];
struct direct
{
	char d_name[20];
	int  n_file;
	char f_name[15][15];
};
struct master
{
	char name[15];
	int n_user;
	struct direct user[10];
};
struct directory
{
	char name[20];
	int n_file;
	char f_name[15][15];
	int n_direct;
	struct directory *subd[10];
};
int check(char str[],char f_name[15][15], int n)
{	
	for(int i=0;i<n;i++)
	{
		if(strcmp(str,f_name[i])==0)
		{
			return i;
		}
	}
	return -1;
	
}

struct node *curr=NULL;
struct node *head=NULL;
void ls(){
	if(curr->no_child == 0){
		printf("\nEmpty Directory");
		return;
	}
	printf("\nDirectory->%s\n",pwd);
	for(int i=0;i<curr->no_child;i++){
		if(curr->c[i]->isDir){
			printf("\nDir->%s ",curr->c[i]->name);
			continue;
		}
		printf("File->%s  ",curr->c[i]->name);
	}
}
void touch(bool d){
	char name[20];
	printf("\nEnter the name: ");
	scanf("%s",name);
	struct node * temp=(struct node*)malloc(sizeof(struct node));
	strcpy(temp->name,name);
	temp->isDir=d;
	temp->p=curr;
	curr->c[curr->no_child]=temp;
	curr->no_child=(curr->no_child)+1;
	if(d){
		if(curr ==NULL)	printf("\nDirectory %s has been created as root directory",name);
		else	printf("\nDirectory %s has been created with parent directory %s",name,pwd);
	}
	else 	printf("\nFile%s has been created in directory %s",name,pwd);
		
}
void cd(){
	char name[20];
	printf("\nEnter the directory name : ");
	scanf("%s",name);
	for(int i=0;i<curr->no_child;i++){
		if((!strcmp(curr->c[i]->name,name)) && (curr->c[i]->isDir)){
			curr=curr->c[i];
			printf("\nPwd is now %s",name);
			strcpy(pwd,name);
			return;
		}
	}
	printf("\nDirectory not found");
}
void cdup(){
	if(curr->p ==NULL){
		printf("\nAt root"); 
		return;
	}
	curr=curr->p;
	printf("\nPWD is %s",curr->name);
	strcpy(pwd,curr->name);
}
void rm(bool d){
	char name[20];
	printf("Enter the name: ");
	scanf("%s",name);
	for(int i=0;i<curr->no_child;i++){
		if((!strcmp(curr->c[i]->name,name)) && (d && curr->c[i]->isDir==true) || (!d && curr->c[i]->isDir == false)){
			int t=i;
			while(t< curr->no_child-1){
				curr->c[t]=curr->c[t+1];
				t++;
			}
			curr->no_child = (curr->no_child) -1 ;
			printf("\n%s Deleted\n",name);
			return;
		}
	}
	printf("\nNot Found");
} 
 void tree(){
	int c;
	head=(struct node*)malloc(sizeof(struct node));
	curr=(struct node*)malloc(sizeof(struct node));
	strcpy(head->name,"root");
	curr->no_child =0;
	strcpy(curr->name,"root");
	strcpy(pwd,"root");
	curr->p=NULL;
	curr->isDir=true;
	do{
		printf("\nTree Structure\n................");
		printf("\n1.Create Directory\n2.Create file\n3.Display all contents\n4.Change directory\n5.Delete file\n6.Delete dir\n7.cdup\n8.Exit\n...............................");
		printf("\nYou are in %s\n",pwd);
		printf("\nEnter the choice: ");
		scanf("%d",&c);
		switch(c){
			case 1:
				touch(true);
				break;
			case 2:
				touch(false);
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
void main()
{
	int choice;
	while(1)
	{
		
		printf("\n1.Single Level 2.Two level 3.Tree stucture 4.Exit \nenter your choice:");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				single();
				break;
			case 2:
				two();
				break;
			case 3:
				tree();
				break;
			case 4:
				exit(0);
			default:
				printf("\n Invalid choice");
		}
	}
	
}
