#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct stack{
	struct node *root;
	struct stack *next;
};

struct queue{
	struct node *root;
	struct queue *next;
};

//--- Stack Functions ---
void stack_init();
void stack_push(struct node *tree);
struct node *pop();
int stack_empty();
void print_stack();
struct stack *new_snode(struct node *tree);
void stack_LNR(struct node *tree);

//--- Queue Functions ---
void queue_init();
struct queue *new_qnode(struct node *tree);
struct queue *qpop();
void print_queue();
int queue_empty();
void queue_push();
void breadth_first(struct node *tree);



#define max(a,b) ((a) > (b) ? (a) : (b))

//--- Tree Functions ---
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
	struct node *tree=NULL;
	tree=insert(tree,10);
	insert(tree,9);
	insert(tree,8);
	insert(tree,5);
	insert(tree,6);
	insert(tree,1);
	insert(tree,2);
	insert(tree,3);
	insert(tree,4);
	insert(tree,25);
	insert(tree,20);
	insert(tree,30);

	struct node *tree1=insert(tree1,10);
	insert(tree1,9);
	insert(tree1,15);
	insert(tree1,3);
	insert(tree1,7);
	insert(tree1,1);
	insert(tree1,4);
	insert(tree1,6);
	insert(tree1,8);
	
	stack_init();
	printf("Recursive LNR, Tree: ");
	LNR(tree);
	printf("\n");
	printf("Iterative LNR, Tree: ");
	stack_LNR(tree);
	queue_init();
	printf("Breadth First, Tree: ");
	breadth_first(tree);
	printf("\nBreadth First, Tree1: ");
	breadth_first(tree1);
	printf("LNR, Tree1: ");
	stack_LNR(tree1);
	LNR(tree1);
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


//--- Stack Functions ---


struct stack *new_snode(struct node *tree){
	struct stack *new=malloc(sizeof(struct stack));
	new->root=tree;
	new->next=NULL;
	return new;
}

struct stack *stack_head=NULL;

void stack_init(){
	stack_head=new_snode(NULL);
}

void stack_push(struct node *root){
	struct stack *new_stack;
	new_stack=new_snode(root);
	new_stack->next=stack_head->next;
	stack_head->next=new_stack;
}

int stack_empty(){
	if(stack_head->next == NULL) return 1;
	else return 0;
}

struct node *pop(){
	struct stack *temp;
	struct node *tree;
	if(!stack_empty()){
		temp=stack_head->next;
		tree=temp->root;
		stack_head->next=stack_head->next->next;
		free(temp);
		return tree;
	}
	else{
		printf("No tree to pop\n");
		return NULL;
	}
}

void print_stack(){
	struct stack *temp;
	if(!stack_empty()){
		temp=stack_head->next;
		printf("Head:: ");
		while(temp->next != NULL){
			printf("%d ",temp->root->data);
			temp=temp->next;
		}
		printf("%d ::Tail\n", temp->root->data);
	}
	else printf("Head:: ::Tail\n");
}

void stack_LNR(struct node *root){
	stack_push(root);
	struct node *temp = root;
	while(!stack_empty()){
		while(temp->left != NULL){
			temp=temp->left;
			stack_push(temp);
		}
		while(!stack_empty()){
			struct node *popped=pop();
			printf("%d ",popped->data);
			if(popped->right != NULL){
				stack_push(popped->right);
				temp=popped->right;
				break;
			}
		}
	}
	printf("\n");
}
	

//--- Queue Functions ---
struct queue *qhead=NULL,*tailptr=NULL;

/*
 * void queue_init();
struct queue *new_qnode(struct node *tree);
struct queue *qpop();
void print_queue();
int queue_empty();
void queue_push();
void breadth_first();
*
*/

struct queue *new_qnode(struct node *tree){
	struct queue *new=malloc(sizeof(struct queue));
	new->root=tree;
	new->next=NULL;
	return new;
}

void queue_init(){
	qhead=new_qnode(NULL);
	tailptr=qhead;
}

int queue_empty(){
	if(qhead->next == NULL) return 1;
	else return 0;
}

void queue_push(struct node *tree){
	struct queue *new=new_qnode(tree);
	tailptr->next=new;
	tailptr=new;
}

struct queue *qpop(){
	if(queue_empty()){
		printf("Can't pop empty queue\n");
		return NULL;
	}
	struct queue *popped=qhead->next;
	qhead->next=qhead->next->next;
	if(queue_empty()){
		tailptr=qhead;
	}
	return popped;
	//remember to free this when you finish using it
}

void print_queue(){
	if(queue_empty()){
		printf("Head:: ::Tail\n");
		return;
	}
	struct queue *temp=qhead->next;
	printf("Head:: ");
	while(temp != NULL){
		printf("%d ",temp->root->data);
		temp=temp->next;
	}
	printf("::Tail\n");
}

void breadth_first(struct node *tree){
	queue_push(tree);
	struct queue *popped=NULL;
	//variable to store pop value
	while(!queue_empty()){
		popped=qpop();
		printf("%d ",popped->root->data);
		if(popped->root->left != NULL){
			queue_push(popped->root->left);
		}
		if(popped->root->right != NULL){
			queue_push(popped->root->right);
		}
		free(popped);
	}
	printf("\n");
}
