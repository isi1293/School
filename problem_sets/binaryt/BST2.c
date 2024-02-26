#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

int height(struct node *root);
struct node *insert(struct node *root, int data);
void LNR(struct node *root);

int main(void){
	struct node *root=insert(root,12);
	insert(root,123);
	insert(root,11);
	insert(root,43);
	insert(root,1);
	insert(root,50);
	insert(root,21);
	insert(root,6);
	insert(root,4);
	insert(root,3);
	LNR(root);
	printf("\n");
	printf("Height of tree: %d\n",height(root));
	
	struct node *tree2=insert(tree2,63);
	insert(tree2,12);
	insert(tree2,73);
	insert(tree2,90);
	printf("Height of tree2: %d\n",height(tree2));
}

int height(struct node *root){
	if(root == NULL) return -1;
	if((height(root->left) > height(root->right))) return 1+height(root->left);
	else return 1+height(root->right);
}

struct node *insert(struct node *root,int num){
	if(root==NULL){
		struct node *new;
		new=malloc(sizeof(struct node));
		new->left=NULL;
		new->right=NULL;
		new->data=num;
		return new;
	}
	if(num < root->data) root->left=insert(root->left, num);
	else root->right=insert(root->right, num);
	return root;
}

void LNR(struct node *root){
	if(root==NULL) return;
	LNR(root->left);
	printf("%d ",root->data);
	LNR(root->right);
}

