#include <stdio.h>
#include <string.h> //for strtok
#include <stdlib.h> //for malloc

struct node{
	char *word;
	char *def;
	struct node *next;
};

struct node *init();
//initializes sentinel node
void add(struct node *sentinel, char *word, char *def);
//make a new node containing word and defand add to 
//given linked list
char *find(struct node *sentinel, char *word);
//search the given list for the given word, return the 
//def, or NULL if not found
int delete(struct node *sentinel, char *word);
//delete the given word from the given list, return 1 
//on success, 0 if word not found
void freelist(struct node *sentinel);
//release all memory associated with this linked list
void printlist(struct node *sentinel);
//print pairs of words/defs from the given list
int listlen(struct node *sentinel);
//print the length of the given list (0 for an empty list)
