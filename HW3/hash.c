#include "list.h"
#include "hash.h"

HASHENTRY *inithash(){
	HASHENTRY *hashtable=malloc(sizeof(HASHENTRY)*SIZE);
	//creates array of struct node *pointers, size of SIZE
	return hashtable;
}

int hash(char *word){

}

void addhash(HASHENTRY *hashtable, char *word){

}

char *findhash(HASHENTRY *hashtable, char *word){

}

int deletehash(HASHENTRY *hashtable, char *word){

}

void freehash(HASHENTRY *hashtable){

}

void printhash(HASHENTRY *hashtable){

}

void printload(HASHENTRY *hashtable){

}

