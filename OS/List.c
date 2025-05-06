insertatbegin(struct node*head , int n)
{
    struct node*new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = n;
    new->link = head;
    head = new;

}

insertatend(struct node*head, int n)
{
    struct node*ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = n;
    ptr->link = NULL;
    struct node*temp = head;

    if(head == NULL)
    {
        head = ptr;
    }
    else{
        while(temp->link != NULL)
        temp = temp->link;
        temp->link = ptr;
           }
}
insertafter(struct node *head, int n ,int key)
{
    struct node*ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = n;
    ptr->link = NULL;
    struct node*q= head;

    while(q->data != key)
    {
        q = q->link;
    }

    ptr->link = q->link;
    q->link = ptr;


}

deletefrombegin(struct node *head,int key){
    struct node*temp = head,*ptr;

    if(temp!=NULL && temp->data = key)
    {
        head = temp->link;
        free(temp);
    }
    if(temp==NULL)
    {
        printf("Key not found")
    }
    while(temp!=NULL && temp->data != key)
    {
        ptr = temp;
        temp = temp->link;
    }
    ptr->link = temp->link;
    free(temp);
}
