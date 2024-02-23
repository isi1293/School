//Isaac Osorio Beltran
//Prof. Nick Macias
//list.c description: list.c contatins all of the functions of a linked list. 
//These functions have been modified to handle interaction with a hashtable
//(an array of linked lists).

#include "list.h"
#include "hash.h"

struct node *init(){
	//[init()] desc: initializes new node
	struct node *sent;
	sent=malloc(sizeof(struct node));
	sent->word=NULL;
	sent->def=NULL;
	sent->next=NULL;
	return sent;
}

void add(struct node *sentinel, char *word, char *def){
	//[add()] desc: adds new node to specified linked list
	struct node *new,*temp;
	temp=sentinel;
	new=malloc(sizeof(struct node));
	new->word=malloc(1+strlen(word));
	//plus 1 to accomodate '\0'
	strcpy(new->word,word);
	new->def=malloc(1+strlen(def));
	strcpy(new->def,def);
	new->next=temp->next;
	temp->next=new;
}

char *find(struct node *sentinel, char *word){
	//[find()] desc: looks for word match in specified
	//linked list.
	struct node *temp;
	temp=sentinel->next;
	while(temp != NULL){
		if(strcmp(temp->word,word) == 0){
			//found a match
			printf("[list.c][find()] Found match for <%s>\nDefinition:%s\n",word,temp->def);
			return temp->def;
		}
		temp=temp->next;
	}
	//No match found
	printf("[list.c][find()] No matching key for <%s>\n",word);
	return NULL;
}

int delete(struct node *sentinel, char *word){
	//[delete()] desc: deletes node specified
	//by the given word value
	struct node *temp,*save;
	temp=sentinel; 
	while(temp->next != NULL){
		if(strcmp(temp->next->word,word) == 0){
			save=temp->next;
			temp->next=temp->next->next;
			free(save->word);
			free(save->def);
			free(save);
			printf("[list.c][delete()] Removed entry for <%s>\n",word);
			return 0;
		}
		temp=temp->next;
	}
	//No match found
	printf("[list.c][delete()] Could not delete <%s>\n", word);
	return 1;
}
		
void freelist(struct node *sentinel){
	//[freelist()] desc: frees mem allocated to each 
	//node in specified linked list.
	struct node *temp,*prev;
	temp=sentinel->next;
	prev=sentinel;
	while(temp != NULL){
		free(prev->word);
		free(prev->def);
		free(prev);
		prev=temp;
		temp=temp->next;
	}
	//reached the end of list, temp is NULL
	free(prev->word);
	free(prev->def);
	free(prev);
}

void printlist(struct node *sentinel){
	//[printlist()] desc: prints the contents of 
	//specified linked list.
	struct node *temp;
	temp=sentinel->next;
	while(temp != NULL){
		printf("Word:%s, Definition:%s\n",temp->word,temp->def); 
		temp=temp->next;
	}
}

int listlen(struct node *sentinel){
	//[listlen()] desc: returns the length of
	//specified linked list.
	struct node *temp;
	int count=0;
	temp=sentinel->next;
	while(temp != NULL){
		count++;
		temp=temp->next;
	}
	return count;
}
