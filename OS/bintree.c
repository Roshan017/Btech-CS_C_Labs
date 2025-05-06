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
					
	
	
	
	
	
	
	
																		
																		
																		
																		
																		
																		
																		
																		
																		
																		
																		
																		
																		
																		
																		
																		
																		
																		
																		
																		
																		
																		
