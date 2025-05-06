#include<stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 10


struct node{

	int data;
	struct node*link;
};

struct node*head[TABLE_SIZE]={NULL},*c;

void insert()
{
	int i,k;
	
	printf("\n Enter the value to be inserted: \n");
	scanf("%d",&k);

	i = k%TABLE_SIZE;

	struct node *n = (struct node*)malloc(sizeof(struct node));
	n->data = k;
	n->link = NULL;

	if(head[i]==NULL)
	{
		head[i] = n;
	}

	else{
		c = head[i];
		while(c->link != NULL)
		{
			c= c->link ;

		}
		c->link=n;
	}
}

void search()
{
	int i,k;

	printf("\nEnter the number to be searched: \n");
	scanf("%d",&k);
	i = k%TABLE_SIZE;

	if(head[i] == NULL)
	{
		printf("Element not founds\n");
	}
	else{
		for(c=head[i];c!=NULL;c=c->link)
		{
			if(c->data==k)
			{
				printf("\n Element found at index: %d",i);
				break;
			}
		}
		if(c==NULL)
		{
			printf("Element not found!\n");
		}
	}

}

void display()
{

	int i;

	for(i=0;i<TABLE_SIZE;i++)
	{

		if(head[i] == NULL)
		{
			continue;
		}

		else{

			for(c=head[i];c!=NULL;c=c->link)
			{
				printf("%d\t",c->data);
				
			}
			//printf("\n");
		}
	}
}

void main()
{
	int opt;
	while(opt!=4)
	{
		printf("\nChoose your Option \n1.Insert\n2.Search\n3.Display\n4.Exit\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1: 
			insert();
			break;

			case 2: 
			search();
			break;

			case 3:
			display();
			break;

			case 4:
			break;

			default:
			printf("\nInvalid Option!");
		}

	}
}