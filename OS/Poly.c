#include<stdio.h>
#include<stdlib.h>

struct node{
    int coef,exp;
    struct node*link;
}
*Phead = NULL,*Qhead = NULL,*Rhead = NULL;

struct node *insert(struct node*head, int coef , int exp){
    int flag = 0;
    struct node*temp = NULL;
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->coef = coef;
    ptr->exp = exp;
    ptr->link = null;

    if(head == NULL)
    {
        ptr->link = head;
        head = ptr;
    }
    else{
        temp = head;

        if(temp->exp == exp)
        {
            temp->coef = temp->coef + coef;

        }
        else{

            while(temp->link!=NULL && temp->link->exp >= exp)
            {
                temp = temp->link;
                if(temp->exp == exp){
                    temp->coef = temp->coef+coef;
                    flag = 1;
                }
            }
            if(flag = 0)
            {
                ptr->link = temp->link;
                temp->link = ptr;
            }
        }
    }
    return head;

}

struct node create(struct node*head){
    struct node *new;
    int n , coef , exp;

    printf("Enter the no of terms: \n");
    scanf("%d",&n);
    for(int i = 0 ; i<n; i++)
    {
        printf("Enter the coefficient: \n");
        scanf("%d",&coef);
        printf("Enter the exponent: \n");
        printf("%d",&exp);
        head = insert(head , coef , exp);
    }
    return head;
    }

    struct node Apoly(struct node *head1,struct node *head2,struct node* head3){
        struct node *ptr1,*ptr2;
        ptr1 = head1,ptr2 = head2;

        while(ptr1 != NULL && ptr2 != NULL)
        {
            if(ptr1->exp == ptr2->exp)
            {
                int acoef = ptr1->coef + ptr2->coef;
                head3 = insert(head3,acoef,ptr2->exp);
                ptr1 = ptr1->link;
                ptr2 = ptr2->link;
            }
            else if(ptr1->exp > ptr2->exp)
            {
                head3 = insert(head3,ptr1->coef,ptr1->exp);
                ptr1 = ptr1->link;

            }
            else if(ptr1->exp < ptr2->exp)
            {
                head3 = insert(head3,ptr2->coef,ptr2->exp);
                ptr2 = ptr2->link;

            }
            while(ptr1->link != NULL){
                head3 = insert(head3,ptr1->coef,ptr1->exp);
                ptr1 = ptr1->link;
            }
            while(ptr2->link != NULL)
            {
                head3 = insert(head3,ptr2->coef,ptr2->exp);
                ptr2 = ptr2->link;
            }
        }
        return head3;

    }

    struct node Mpoly(struct node*head1,struct node*head2,struct node*head3)
    {
        struct node *ptr1,*ptr2;
        ptr1 = head1;
        ptr2 = head2;

        while(ptr1!=NULL)
        {
            while(ptr2!=NULL)
            {
                int mcoef = ptr1->coef*ptr2->coef;
                int mexp = ptr->exp + ptr2->exp;
                head3 = insert(head3,mcoef,mexp);
                ptr2 = ptr->link;
            }
            ptr1=ptr1->link;
            ptr2 = head2;
        }
        return head3;
    }

    struct node Dpoly(struct node*head)
    {
        if(head == NULL)
        {
            printf("The polynomial is empty");
            return;

        }

        else{
            printf("\n");
            struct node*ptr;

            while(ptr->link != NULL)
            {
                printf("%dX^%d+",ptr->coef,ptr->exp);
                ptr = ptr->link;
            }
            printf("%dX^%d+",ptr->coef,ptr->exp);
            
        }
    }

    struct node freeall(struct node*head)
    {
        struct node *p;
        p = head;
        while(p!=NULL)
        {
            head = head->link;
            free(p);
            p=head;
        }
        return head;
    }

    void main()
    {
        int opt;
        do{
        printf("Choose Operation: \n1.Addition \n2.Multiplication \n3.Exit");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: 
            printf("Enter the First Polynomial: \n");
            Phead = create(Phead);
            printf("Enter the Second Polynomial: \n");
            Qhead = create(Qhead);
            printf("The First Polynomial is : \n");
            Dpoly(Phead);
            printf("The Second Polynomial is : \n");
            Dpoly(Qhead);
            
            printf("Adding...");
            Rhead = Apoly(Rhead);
            printf("The Result is: \n");
            Dpoly(Rhead);
            Phead = freeall(Phead);
            Qhead = freeall(Qhead);
            Rhead = freeall(Rhead);
            break;

            case 2:
            printf("Enter the First Polynomial: \n");
            Phead = create(Phead);
            printf("Enter the Second Polynomial: \n");
            Qhead = create(Qhead);
            printf("The First Polynomial is : \n");
            Dpoly(Phead);
            printf("The Second Polynomial is : \n");
            Dpoly(Qhead);
            
            printf("Multiplying...");
            Rhead = Mpoly(Rhead);
            printf("The Result is: \n");
            Dpoly(Rhead);
            Phead = freeall(Phead);
            Qhead = freeall(Qhead);
            Rhead = freeall(Rhead);
            break;

            case 3:
            break;

            default:
            printf("Wrong Option\n");
            break;
        }

        
        }
        while(opt!=3)

    }