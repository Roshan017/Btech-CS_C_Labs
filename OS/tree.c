#include<stdio.h>
#include<stdlib.h>

struct node *root=NULL;
struct node *Raw=NULL;

struct node{

    int data;
    struct node*left;
    struct node*right;
};

struct node*create()
{
    int val;

    printf("Enter the value to be inserted (-1 for NULL): \n");
    scanf("%d",&val);

    if(val==-1)
    {
        return NULL;
    }

    struct node*new = (struct node*)malloc(sizeof(struct node));

    new->data = val;

    printf("Enter the left child of %d\n",val);
    new->left = create();
     printf("Enter the right child of %d\n",val);
    new->right = create();

    return new;

}

void inorder(struct node*Raw)
{
    if(Raw!= NULL)
    {
        inorder(Raw->left);
        printf("%d\t",Raw->data);
        inorder(Raw->right);
    }
}
void preorder(struct node*Raw)
{
    if(Raw!= NULL)
    {
        printf("%d\t",Raw->data);
        preorder(Raw->left);
        preorder(Raw->right);
    }
}
void postorder(struct node*Raw)
{
    if(Raw!= NULL)
    {
        postorder(Raw->left);
        postorder(Raw->right);
        printf("%d\t",Raw->data);
    }
}

struct node* inorderPre( struct node* root)
{
    root = root->left;

    while(root->right!= NULL)
    {
        root=root->right;
    }
    return root;
}


struct node*delete(struct node*root,int n)
{
    struct node *iPre;
    if(root == NULL)
    {
        return NULL;
    }

    if(root->left == NULL && root->right == NULL)
    {
        free(root);
    }

    if(n < root->data)
    {
        delete(root->left,n);
    }

    else if(n > root->data)
    {
        delete(root->right,n);
    }

    else{
        iPre = inorderPre(root);
        root->data = iPre->data;
        delete(iPre->data,n);
    }
    
    return root;
    
    }
int main()
{
    int op;
    while(op!=4)
    {
    printf("Choose your option: \n1.Create \n2.Traversals \n3.Deletion \n4.Exit");
    scanf("%d",&op);

    switch(op)
    {
        case 1: 
        root = create();
        break;

        case 2: 
        printf("Inorder: \n");
        inorder(root);
        printf("\n");
        printf("Postorder: \n");
        postorder(root);
        printf("\n");
        printf("Preorder: \n");
        preorder(root);
        printf("\n");
        break;

        case 3:
        int n;
        printf("Enter the value to be deleted: \n");
        scanf("%d",&n);
        delete(root,n);
        break;
        
        case 4:
        break;

        default:
        printf("Invalid Option:\n");

    }
    }
}