#include "list.h"
#include "hash.h"

struct node *init(){
	struct node *sent;
	sent=malloc(sizeof(struct node));
	sent->word=NULL;
	sent->def=NULL;
	sent->next=NULL;
	return sent;
}

void add(struct node *sentinel, char *word, char *def){
	struct node *new,*temp;
	temp=sentinel;
	new=malloc(sizeof(struct node));
	strcpy(new->word,word);
	new->def=def;
	new->next=temp->next;
	temp->next=new;
}

char *find(struct node *sentinel, char *word){
	struct node *temp;
	temp=sentinel->next;
	while(temp != NULL){
		if(strcmp(temp->word,word) == 0){
			//found a match
			return temp->def;
		}
		temp=temp->next;
	}
}

int delete(struct node *sentinel, char *word){
	struct node *temp,*save;
	temp=sentinel; while(temp->next != NULL){
		if(strcmp(temp->next->word,word) == 0){
			save=temp;
			temp->next=temp->next->next;
			free(save->word);
			free(save->def);
			free(save);
			return 0;
		}
		temp=temp->next;
	}
	//No match found
	printf("[File:list.c Fn:delete, could not delete <%s>, no match found\n", word);
}
		
void freelist(struct node *sentinel){
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
	struct node *temp;
	temp=sentinel->next;
	while(temp != NULL){
		printf("Word: %s, Definition: %s\n",temp->word,temp->def); 
		temp=temp->next;
	}
}

int listlen(struct node *sentinel){
	struct node *temp;
	int count=0;
	temp=sentinel->next;
	while(temp != NULL){
		count++;
		temp=temp->next;
	}
	return count;
}
