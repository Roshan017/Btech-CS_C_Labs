//Roshan P Mathew 51
#include<stdio.h>
int table[10];
int tableSize=10;
void insert(int key){
int index=key % tableSize;
while(table[index]!=0)
index=(index+1)% tableSize;
table[index]=key;
}
int search(int item){
int index=item %tableSize;
int c=0;
while(table[index]!=item){
index=(index+1)% tableSize;
c++;
if(c==tableSize)
return -1;
}
return index;
}
void main(){
printf("\n1.Insert\n2.Search\n3.Display\n4.Exit");
int c,key,index,item;
do{
printf("\nEnter the choice:");
scanf("%d",&c);
switch(c){
case 1:
printf("\nEnter the value to be inserted:");
scanf("%d",&key);
insert(key);
break;
case 2:
printf("Enter the item to be searched:");
scanf("%d",&item);
index=search(item);
if(index==-1)
printf("\nItem not found");
else
printf("\nItem found in %d position",index);
break;
case 3:
for(int i=0;i<tableSize;i++)
printf("%d\t",table[i]);
break;
case 4:
printf("Exiting....");
break;
default:
printf("Error");
}
}while (c!=4);
}
/*OUTPUT
1.Insert
2.Search
3.Display
4.Exit
Enter the choice:1
Enter the value to be inserted:6
Enter the choice:1
Enter the value to be inserted:4
Enter the choice:1
Enter the value to be inserted:7
Enter the choice:2
Enter the item to be searched:7
Item found in 7 position
Enter the choice:2
Enter the item to be searched:6
Item found in 6 position
Enter the choice:3
0 0 0 0 4 0 6 7 0 0
Enter the choice:1
Enter the value to be inserted:54
Enter the choice:3
0 0 0 0 4 54 6 7 0 0
Enter the choice:54
Error
Enter the choice:2
Enter the item to be searched:54
Item found in 5 position
Enter the choice:4
Exiting....*/
















//Roshan P Mathew 51

#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*left;
struct node*right;
};
struct node*insert(struct node*root,int data){
if(root==NULL){
root=(struct node*)malloc(sizeof(struct node));
root->data=data;
root->left=NULL;
root->right=NULL;
}
else if(data<root->data){
root->left=insert(root->left,data);
}
else if(data>root->data){
root->right=insert(root->right,data);
}
return root;
}
void preorder(struct node*root){
if(root==NULL){
return;
}
printf("%d\t",root->data);
preorder(root->left);
preorder(root->right);
}
void inorder(struct node*root){
if(root==NULL){
return;
}
inorder(root->left);
printf("%d\t",root->data);
inorder(root->right);
}
void postorder(struct node*root){
if(root==NULL){
return;
}
postorder(root->left);
postorder(root->right);
printf("%d\t",root->data);
}
struct node*min(struct node*root){
if(root==NULL){
return NULL;
}
else if(root->left==NULL){
return root;
}
else{
return min(root->left);
}
}
struct node*delete(struct node* root,int data){
struct node* temp;
if(root==NULL)
return NULL;
else if(data<root->data){
root->left=delete(root->left,data);
}
else if(data>root->data){
root->right=delete(root->right,data);
}
else if(root->left!=NULL && root->right!=NULL){
temp=min(root->right);
root->data=temp->data;
root->right=delete(root->right,root->data);
}
else{
temp=root;
if(root->left==NULL)
root=root->right;
else if(root->right==NULL)
root=root->left;
free(temp);
}
return root;
}
void main(){
struct node*tree=NULL;
int cho;
printf("1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Delete\n6.Exit\n");
do{
int data,del;
printf("\nEnter a choice:");
scanf("%d",&cho);
switch(cho){
case 1:
printf("Enter element to be inserted:");
scanf("%d",&data);
tree=insert(tree,data);
break;
case 2:
printf("Preorder Sequence is\n");
preorder(tree);
break;
case 3:
printf("Inorder Sequence is\n");
inorder(tree);
break;
case 4:
printf("Postorder Sequence is\n");
postorder(tree);
break;
case 5:
printf("Enter the element to be deleted:");
scanf("%d",&del);
delete(tree,del);
break;
case 6:
printf("Exiting...\n");
break;
default:
printf("Error");
}
}while(cho!=6);
}
/*OUTPUT
1.Insert
2.Preorder
3.Inorder
4.Postorder
5.Delete
6.Exit
Enter a choice:1
Enter element to be inserted:8
Enter a choice:1
Enter element to be inserted:7
Enter a choice:1
Enter element to be inserted:5
Enter a choice:1
Enter element to be inserted:9
Enter a choice:1
Enter element to be inserted:11