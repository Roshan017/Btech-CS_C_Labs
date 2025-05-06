#include<stdio.h>
void st();void qu();void push();void pop();void enq();void deq();
int stack[5],queue[5];
int top=-1,front=-1,rear=-1;
void main()
{	int op;	
	while(op!=3)	
	{	printf("Choose option \n1-Stack\n2-Queue\n3-Exit\n");
		scanf("%d",&op);
		if(op==1)
		{	st();}
		else if(op==2)
		{	qu();}
	}printf("\n");}

void st()
{	int c;
	while(c!=4)
	{	printf("Choose operation\n1-push\n2-pop\n3-Display\n4-continue\n");
		scanf("%d",&c);
		if(c==1)
		{	push();}
		else if(c==2)
		{	pop();}
		else if(c==3)
		{	for(int i=0; i<=top;i++)
			{	printf("%d\t",stack[i]);}}
		else if(c==4)
		{	continue;}
		else
		{	printf("Invalid choice\n");}printf("\n");}}
void qu()
{	int h;
	while(h!=4)
	{	printf("Choose operation\n1-enqueue\n2-dequeue\n3-Display\n4-Exit\n");
		scanf("%d",&h);
		if(h==1)
		{	enq();}
		else if(h==2)
		{	deq();}
		else if(h==3)
		{	for(int i=front; i<=rear;i++)
			{	printf("%d\t",queue[i]);}
		}
		else if(h==4)
		{	continue;
		}
		else
		{	printf("Invalid choice\n");
		}printf("\n");
 	}
}
void push()
{       int l;	
	printf("Enter number to push to stack\n");	
	scanf("%d",&l);
	if(top==4)
	{	printf("Stack overflow \n");
	}
	else
	{ 	top++;
		stack[top]=l;
	}printf("\n");
}
void pop()
{	int x;	
	if(top==-1)
	{	printf("Stack underflow\n");
	}
	else 
	{	x= stack[top];
		top--;
		printf("Popped %d \n",x);
	}printf("\n");
	
}
void enq()
{	int k;	
	printf("Enter number to enqueue\n");	
	scanf("%d",&k);
	if(rear==4)
	{	printf("Queue overflow\n");
	}
	else
	{	rear++;
		queue[rear]=k;
		if(front==-1)
		{	front++;
		}
		
	}printf("\n");
}

void deq()
{	if(front==-1)
	{	printf("Queue underflow");
	}
	else
	{	
		int y= queue[front];
		front++;
		printf("Dequeued number  is %d",y);
		if(front>rear)
		{	front=rear=-1;}
	}
}



























	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
