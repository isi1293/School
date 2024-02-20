#include "list.h"
#include "hash.h"

int ingest(HASHENTRY *hashtable,char *filename){
	FILE *fp;
	char word[120],def[1025];
	int tally[SIZE]={0};
	fp=fopen(filename,"r");
	if(fp == NULL){
		printf("Could not open file\n");
		return 1;
	}

	while(fgets(word,sizeof(word),fp) != NULL){
		word[-1+strlen(word)]='\0';
		tally[hash(word)]+=1;
		fgets(def,sizeof(def),fp);
		def[-1+strlen(def)]='\0';
		addhash(hashtable,word,def);
	}
	for(int i=0;i<SIZE;i++){
		printf("Tally[%d]:%d\n",i,tally[i]);
	}
	return 0;
}
		

