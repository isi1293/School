#include <stdio.h>
#include <stdlib.h>


struct node{
	int data;
	struct node *left;
	struct node *right;
};

int search(struct node *root,int data);
struct node *insert(struct node *root, int data);
void LNR(struct node *);
void RNL(struct node *);
void NLR(struct node *);
void LRN(struct node *);

int main(void){
	/*
	 * Manula Entry of Binary Search Tree
	 *
	struct node *root=malloc(sizeof(struct node));
	struct node *left=malloc(sizeof(struct node));
	struct node *right=malloc(sizeof(struct node));
	struct node *left2=malloc(sizeof(struct node));
	struct node *right2=malloc(sizeof(struct node));

	root->left=left;
	root->right=right;
	root->data=10;

	left->left=left2;
	left->right=right2;
	left->data=5;

	right->left=NULL;
	right->right=NULL;
	right->data=15;

	left2->left=NULL;
	left2->right=NULL;
	left2->data=3;

	right2->left=NULL;
	right2->right=NULL;
	right2->data=7;

	printf("---LNR---\n");
	LNR(root);
	printf("\n");
	printf("---RNL---\n");
	RNL(root);
	printf("\n");
	printf("---NLR---\n");
	NLR(root);
	printf("\n");
	printf("---LRN---\n");
	LRN(root);
	printf("\n");

	insert(root,1);
	insert(root,20);

	printf("New tree: ");
	NLR(root);
	printf("\n");

*
*/
	struct node *root=NULL;
	root=insert(root,10);
	insert(root,20);
	insert(root,5);
	insert(root,-7);
	insert(root,23);
	insert(root,15);
	insert(root,-5);
	insert(root,8);

	LNR(root);
	printf("\n");
	NLR(root);
	printf("\n");

}

int search(struct node *root,int data){
	if(root==NULL) return 0;
	if(root->data == data) return 1;
	if(data < (root->data)) return search(root->left,data);
	else return search(root->right,data);
}



struct node *insert(struct node *root, int data){
	if(root==NULL){
		struct node *newroot=malloc(sizeof(struct node));
		newroot->data=data;
		newroot->left=NULL;
		newroot->right=NULL;
		return newroot;
	}
	if(data < root->data) root->left=insert(root->left,data);
	else root->right=insert(root->right,data);
	return root;
}

void LNR(struct node *root){
	if(root==NULL) return;
	LNR(root->left);
	printf("%d ", root->data);
	LNR(root->right);
}

void RNL(struct node *root){
	if(root == NULL) return;
	RNL(root->right);
	printf("%d ",root->data);
	RNL(root->left);
}

void NLR(struct node *root){
	if(root == NULL) return;
	printf("%d ", root->data);
	NLR(root->left);
	NLR(root->right);
}

void LRN(struct node *root){
	if(root == NULL) return;
	LRN(root->left);
	LRN(root->right);
	printf("%d ",root->data);
}

