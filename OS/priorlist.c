#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    int priorty;
    struct node*link;
};

struct node*front = NULL;


void insert(int n ,int m)
{
    struct node*ptr,*temp;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = n;
    ptr->priorty = m;
    if(front == NULL || m > front->priorty )
    {
        ptr->link = front;
        front = ptr;
    }
    else{
        temp = front;
        while(temp->link != NULL && temp->link->priorty <= m )
        {
            temp = temp->link;
            ptr->link = temp->link;
            temp->link = ptr;
        }
    }
}
void del()
{
    struct node*ptr;
    {
        if(front == NULL)
        {
            printf("Queue is empty\n");
        }
        else{
            front = ptr;
            front = front->link;
            free(ptr);
        }
    }
}
void display()  
{  
    struct node *ptr;  
    ptr = front;  
    if(front == NULL)  
        printf("Queue is empty\n");  
    else  
    {     
        printf("Queue is :\n");  
        printf("Priority       Item\n");  
        while(ptr != NULL)  
        {  
            printf("%5d        %5d\n",ptr->priorty,ptr->data);  
            ptr = ptr->link;  
        }  
    }  
}  
int main()  
{  
    int choice, data, priority;  
    do  
    {  
        printf("1.Insert\n");  
        printf("2.Delete\n");  
        printf("3.Display\n");  
        printf("4.Quit\n");  
        printf("Enter your choice : ");  
        scanf("%d", &choice);  
        switch(choice)  
        {  
            case 1:  
                printf("Enter the data which is to be added in the queue : ");  
                scanf("%d",&data);  
                printf("Enter its priority : ");  
                scanf("%d",&priority);  
                insert(data,priority);  
                break;  
            case 2:  
                del();  
                break;  
            case 3:  
                display();  
                break;  
            case 4:  
            break;  
                default :  
                printf("Wrong choice\n");  
        }  
    }while(choice!=4);  
  
    return 0;  
} 
