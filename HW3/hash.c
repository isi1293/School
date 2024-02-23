//Isaac Osorio Beltran
//Prof. Nick Macias
//CSE222, HW3
//[hash.c] description: hash.c contains all the functions of a hashtable
//(an array of linked lists). In brief, it provides HW3.c with all of the 
//functions needed to create, and interact with a hashtable.

#include "list.h"
#include "hash.h"
#include <math.h>

HASHENTRY *inithash(){
	//[inithash()] desc: initializes hashtable
	HASHENTRY *hashtable=malloc(sizeof(HASHENTRY)*SIZE);
	//creates array of struct node *pointers, size of SIZE
	for(int i=0;i<SIZE;i++){
		hashtable[i]=init();
	}
	return hashtable;
}

int hash(char *word){
	//[hash()] desc: hashes given word using
	//a magical hash function.
	long int hashed,sum=0;
	for(int i=0;i<(strlen(word));i++){
		sum+=(pow(i+1,2)*pow(word[i],3));
		hashed=sum%SIZE;
	}
	return hashed;
}

void addhash(HASHENTRY *hashtable, char *word, char *def){
	//[addhash()] desc: adds new word/def pair to appropriate
	//linked list.
	int index=hash(word);
	add(hashtable[index],word,def);
}

char *findhash(HASHENTRY *hashtable, char *word){
	//[findhash()] desc: searches for match to word, prints
	//word/def pair.
	int index=hash(word);
	return find(hashtable[index],word);
}

int deletehash(HASHENTRY *hashtable, char *word){
	//[deletehash()] desc: removes word/def pair at the appropriate
	//linked list, which is found by hashing the word. 
	int index=hash(word);
	delete(hashtable[index],word);
	return 0;
}

void freehash(HASHENTRY *hashtable){
	//[freehash()] desc: goes through each linked list and frees the
	//mem allocated to each node in the linked list. 
	for(int i=0;i<SIZE;i++){
		freelist(hashtable[i]);
	}
	free(hashtable);
}

void printhash(HASHENTRY *hashtable){
	//[printhash()] desc: prints the contents of the hashtable. All
	//contents of each linked list.
	for(int i=0;i<SIZE;i++){
		printf("***************\n   Entry %d   \n***************\n",i);
		printlist(hashtable[i]);
	}
}

void printload(HASHENTRY *hashtable){
	//[printload()] desc: prints the entry and the length of the linked
	//list at each entry, not including the sentinel
	for(int i=0;i<SIZE;i++){
		printf("Entry[%d] Length:%d\n",i,listlen(hashtable[i]));
	}
}

