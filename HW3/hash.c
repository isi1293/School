#include "list.h"
#include "hash.h"
#include <math.h>

HASHENTRY *inithash(){
	HASHENTRY *hashtable=malloc(sizeof(HASHENTRY)*SIZE);
	//creates array of struct node *pointers, size of SIZE
	for(int i=0;i<SIZE;i++){
		hashtable[i]=init();
	}
	return hashtable;
}

int hash(char *word){
	int hashed,sum=0;
	for(int i=0;i<(strlen(word));i++){
		sum+=(pow(i+1,2)*pow(word[i+1],3));
	}
	hashed=sum%SIZE;
	return hashed;
}

void addhash(HASHENTRY *hashtable, char *word, char *def){
	int index=hash(word);
	add(hashtable[index],word,def);
}

char *findhash(HASHENTRY *hashtable, char *word){
	int index=hash(word);
	return find(hashtable[index],word);
}

int deletehash(HASHENTRY *hashtable, char *word){
	int index=hash(word);
	delete(hashtable[index],word);
	return 0;
}

void freehash(HASHENTRY *hashtable){
	for(int i=0;i<SIZE;i++){
		freelist(hashtable[i]);
	}
	free(hashtable);
}

void printhash(HASHENTRY *hashtable){
	for(int i=0;i<SIZE;i++){
		printlist(hashtable[i]);
	}
}

void printload(HASHENTRY *hashtable){
	for(int i=0;i<SIZE;i++){
		printf("[%d] Length:%d\n",i,listlen(hashtable[i]));
	}
}

