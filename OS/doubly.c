#include<stdio.h>
#include<stdlib.h>

struct node*{
    int data;
    struct node*next,*prev;
}
struct node*head;

I_begin(int n)
{
    struct node*ptr = (struct node*)malloc(sizeof(struct node));
    if(head == NULL)
    {
        ptr->data = n;
        ptr->prev = NULL;
        ptr->next = NULL;
        head = ptr;
    }
    else{
        ptr->data = n;
        ptr->next = head;
        head->prev = ptr;
        ptr->prev = NULL;
        head = ptr;
    }
}

I_last(int n)
{
    struct node*ptr = (struct node*)malloc(sizeof(struct node));
    struct node*temp;
    if(head==NULL)
    {
        ptr->data = n;
        ptr->next = NULL;
        ptr->prev = NULL;
        head = ptr;

    }

    else{
        temp = head;
        while(temp->link != NULL)
        {
            temp = temp->link;
        }

        temp->link = ptr;
        ptr->data = n;
        ptr->prev = temp;
        ptr->next = NULL;
        
    }
}

I_specified(int n,int key)
{
    struct node*ptr = (struct node*)malloc(sizeof(struct node));
    struct node*temp;

    if(head == NULL)
    {
        printf("Key not found\n");
    }
    else{
        temp = head;
        while(temp->data != key)
        {
            temp = temp->next;
        }
        ptr->data = n;
        ptr->next = temp->next;
        ptr->prev = temp;
        temp->next->prev = ptr;
        temp->next = ptr;

    }
}
D_begin()
{
    struct node*ptr;
    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else if(head->next == NULL)
    {
        head = ptr;
        free(ptr);
    }
    else{
        ptr = head;
        ptr->prev = NULL;
        head = head->next;
        free(ptr);
        
    }

}
D_End()
{
    struct node*ptr;
    if(head == NULL)
    {
        printf("List is empty\n");
    }
     else if(head->next == NULL)
    {
        head = ptr;
        free(ptr);
    }
    else{
        ptr = head;
    while(ptr->link != NULL)
    {
        ptr = ptr->next;
    }

    ptr->prev->next = NULL;
    free(ptr);

}
}

D_after(int key)
{
    struct node*ptr
    struct node*temp;
    struct node*ptr;
    head = ptr;
    while(ptr->data != key)
    {
        ptr = ptr->link;
        if(ptr->link == NULL )
        {
            printf("Can't delete\n");
        }
        else if(ptr->next->next == NULL)
        {
            ptr->next = NULL;
        }
        else{
            temp = ptr->next;
            ptr->next = temp->next;
            temp->next->prev = ptr;
            free(temp);
        }
    }
}