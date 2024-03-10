#include <stdio.h>
#include <stdlib.h>

#define max(a,b) ((a) > (b) ? (a) : (b))

struct node{
	int data;
	struct node *left;
	struct node *right;
};


int balanced(struct node *root);
int height(struct node *root);
struct node *insert(struct node *root, int data);
void LNR(struct node *root);
struct node *rightmost(struct node *root);
struct node *leftmost(struct node *root);
struct node *right_w_parent(struct node *root);
struct node *left_w_parent(struct node *root);
struct node *rootdelete(struct node *root);
struct node *delete(struct node *root,int data);

int main(void){

	/*
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
	printf("Rightmost node: %d\n",rightmost(root)->data);
	right_w_parent(root);
	printf("Leftmost node: %d\n",leftmost(root)->data);
	left_w_parent(root);
	printf("1 if balanced, else 0: %d\n", balanced(root));
	
	struct node *tree2=insert(tree2,63);
	insert(tree2,12);
	insert(tree2,73);
	insert(tree2,90);
	printf("Height of tree2: %d\n",height(tree2));
	printf("Rightmost node: %d\n",rightmost(tree2)->data);
	right_w_parent(tree2);
	printf("Leftmost node: %d\n",leftmost(tree2)->data);
	left_w_parent(tree2);
	printf("1 if balanced, else 0: %d\n", balanced(tree2));
	*/

	//-- Test trees for balanced function --
	
	/*
	struct node *tree3=insert(tree3,10);
	insert(tree3,5);
	LNR(tree3);
	printf("\n");
	printf("1 if balanced, else 0: %d\n", balanced(tree3));
	insert(tree3,15);
	LNR(tree3);
	printf("\n");
	printf("1 if balanced, else 0: %d\n", balanced(tree3));
	insert(tree3,2);
	LNR(tree3);
	printf("\n");
	printf("1 if balanced, else 0: %d\n", balanced(tree3));
	insert(tree3,1);
	LNR(tree3);
	printf("\n");
	printf("1 if balanced, else 0: %d\n", balanced(tree3));
	insert(tree3,20);
	insert(tree3,25);
	LNR(tree3);
	printf("\n");
	printf("1 if balanced, else 0: %d\n", balanced(tree3));
	right_w_parent(tree3);
	left_w_parent(tree3);
	
	struct node *tree4=insert(tree4,10);
	insert(tree4,15);
	insert(tree4,9);
	insert(tree4,3);
	insert(tree4,7);
	insert(tree4,8);
	insert(tree4,6);
	insert(tree4,1);
	insert(tree4,4);
	LNR(tree4);
	printf("\n");
	printf("1 if balanced, else 0: %d\n", balanced(tree4));
	right_w_parent(tree4);
	left_w_parent(tree4);
	*/

	//---Testing rootdelete() function---
	struct node *tree1, *tree2, *tree3, *tree4, *tree5, *tree6;

		tree1=insert(tree1,10);

		tree2=insert(tree2,10);
		insert(tree2,12);

		tree3=insert(tree3,10);
		insert(tree3,12);
		insert(tree3,9);

		tree4=insert(tree4,10);
		insert(tree4,9);
		insert(tree4,8);
		insert(tree4,7);
		insert(tree4,6);
		insert(tree4,5);

		tree5=insert(tree5,10);
		insert(tree5,9);

		tree6=insert(tree6,50);
		insert(tree6,25);
		insert(tree6,75);
		insert(tree6,28);
		insert(tree6,23);
		insert(tree6,78);
		insert(tree6,62);

		LNR(tree1);
		printf("\n");
		LNR(tree2);
		printf("\n");
		LNR(tree3);
		printf("\n");
		LNR(tree4);
		printf("\n");
		LNR(tree5);
		printf("\n");
		LNR(tree6);
		printf("\n");

		/*
		 * tree1=rootdelete(tree1);
		tree2=rootdelete(tree2);
		tree3=rootdelete(tree3);
		tree4=rootdelete(tree4);
		tree5=rootdelete(tree5);
		tree6=rootdelete(tree6);
		*
		*/

		tree1=delete(tree1,12);
		tree2=delete(tree2,10);
		tree3=delete(tree3,12);
		tree4=delete(tree4,5);
		tree5=delete(tree5,9);
		tree6=delete(tree6,23);

		if(tree1==NULL){
			printf("Tree 1 is now an empty tree, NULL\n");
		}

		LNR(tree1);
		printf("\n");
		LNR(tree2);
		printf("\n");
		LNR(tree3);
		printf("\n");
		LNR(tree4);
		printf("\n");
		LNR(tree5);
		printf("\n");
		LNR(tree6);
		printf("\n");
}

int height(struct node *root){
	if(root == NULL) return -1;
	return 1 + max(height(root->left), height(root->right));
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


struct node *rightmost(struct node *root){
	if(root == NULL) return root;
	else if(root->right != NULL) return rightmost(root->right);
	return root;
}

struct node *right_w_parent(struct node *root){
	if(root == NULL){
		printf("Empty root given.\n");
		return root;
	}
	
	if(root->right == NULL){
		printf("No parent.\n");
		return root;
	}

	struct node *rightmost,*rightmostparent;
	rightmost=root->right;
	rightmostparent=root;

	while(rightmost->right != NULL){
		rightmostparent=rightmost;
		rightmost=rightmost->right;
	}

	printf("Rightmost parent: %d\n", rightmostparent->data);
	printf("Rightmost node: %d\n", rightmost->data);

	return rightmost;
}

struct node *left_w_parent(struct node *root){
	if(root == NULL){
		printf("Empty root given.\n");
		return root;
	}
	if(root->left == NULL){
		printf("No parent.\n");
		return root;
	}
	
	struct node *leftmost,*leftmostparent;
	leftmost=root->left;
	leftmostparent=root;
	
	while(leftmost->left != NULL){
		leftmostparent=leftmost;
		leftmost=leftmost->left;
	}

	printf("Leftmost parent: %d\n", leftmostparent->data);
	printf("Leftmost node: %d\n", leftmost->data);
	
	return leftmost;
}

struct node *leftmost(struct node *root){
	if(root == NULL) return root;
	else if(root->left != NULL) return leftmost(root->left);
	return root;
}
	
int balanced(struct node *root){
	if(root == NULL) return 1;
	if(abs(height(root->left) - height(root->right)) > 1) return 0;
	if(balanced(root->left) == 0 || balanced(root->right) == 0) return 0;
	else return 1;
}

struct node *rootdelete(struct node *root){
	if(root == NULL){
		printf("Passed empty root");
		return root;
	}

	if(root->left == NULL){
		struct node *temp=root;
		root=root->right;
		free(temp);
		return root;
	}

	struct node *largest=root->left,*POL=NULL;
	//assume root->left is largest

	while(largest->right != NULL){
		//traverse left sub-tree
		POL=largest;
		largest=largest->right;
	}

	if(POL==NULL){
		//if root->left is the largest
		largest->right=root->right;
		free(root);
		return largest;
	}

	//else, parent of largest adopts the child of 
	//largest, and largest replaces root.
	POL->right=largest->left;
	largest->right=root->right;
	largest->left=root->left;
	free(root);
	return largest;
}	

struct node *delete(struct node *root, int data){
	if(root == NULL) return NULL;
	if(root->data == data) return rootdelete(root);
	if(data < root->data){
		root->left = delete(root->left,data);
		return root;
	}
	else{
		root->right = delete(root->right,data);
		return root;
	}
	//if not found, function will return NULL
}
