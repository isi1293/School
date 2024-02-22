//Isaac Osorio Beltran 
//CSE222 Prof. Nick Macias
//HW3.c Description: HW3.c acts as the central hub to the entire program
//It ingests the file inputted on the command-line and makes calls to hash.c
//which then makes calls to list.c 
//
//=========== Hierarchy of the program =================
//
//               HW3.c
//                |    \   list.h
//                |     \    ^
//                V      \   |
//               Hash.c----->*
//                |      /   |
//                |     /    V
//                V    /    hash.h
//               List.c
//
//======================================================


#include "list.h"
#include "hash.h"

int which_command(HASHENTRY *hashtable,char *command);
//[which_command()] synopsis: Take hashtable, and command input, and 
//determine desired function of the program.

int ingest(HASHENTRY *hashtable,char *filename,FILE *fp);
//[ingest()] synopsis: Take hashtable and command-line(fileneame) then
//process the specified dictionary file of the format:
//
//word1\n
//def1\n
//word2\n
//def2\n


int main(int argc,char **argv){
	
	if(argc != 2){
		if(argc>2) printf("[HW3.c][main()] Invalid call to program, too many arguments\n");
		if(argc<2) printf("[HW3.c][main()] Invalid call to program, not enough arguments\n");
		return 1;
	}

	HASHENTRY *hashtable;
	//HASHENTRY defined as typedef struct node *HASHENTRY. Thus, hashtable
	//is of type struct node **
	hashtable=inithash();
	//Initializes array of struct node * (linked lists) of size SIZE, defined
	//in hash.h
	
	char buffer[120];
	FILE *fp;

	//IGNORE Hardcode for testing on local machine:
	//if(ingest(hashtable,"/home/notisaac/Clark/CSE222/School/HW3/dictionary.txt",fp)==0){
	
	if(ingest(hashtable,argv[1],fp)==0){
		//if successful ingestion, loop until user breaks with CTRL-D
		while(1){
			printf("> ");
			if(fgets(buffer,sizeof(buffer),stdin) == NULL){
				printf("Goodbye\n");
				freehash(hashtable);
				return 0;
			}
			else{
				buffer[-1+strlen(buffer)]='\0';
				which_command(hashtable,buffer);
			}
		}
	}
}


int ingest(HASHENTRY *hashtable,char *filename,FILE *fp){

	char word[120],def[1025];
	int tally[SIZE]={0};
	int count=0;

	fp=fopen(filename,"r");

	if(fp == NULL){
		printf("Could not open file\n");
		freehash(hashtable);
		return 1;
	}

	while(fgets(word,sizeof(word),fp) != NULL){
		word[-1+strlen(word)]='\0';
		tally[hash(word)]+=1;
		fgets(def,sizeof(def),fp);
		def[-1+strlen(def)]='\0';
		addhash(hashtable,word,def);
		count++;
	}
	//successful ingest \(^.^)/
	fclose(fp);
	return 0;
}

int which_command(HASHENTRY *hashtable,char *command){
	//commands to take: *, *delete, ?, *word
	char *field,copy[1024];
	int help,remove,print_table,load;

	strcpy(copy,command);
	field=strtok(command," ");
	if(field == NULL){
		//strtok returns NULL if there is nothing in the string.
		//' ' is used as the delimiter, therefore, tokenizing ' '
		//returns NULL, return to avoid seg fault.
		printf("' ' is an invalid word. Please enter a different word or '?' for help\n");
		return 1;
	}
	help=strcmp(field,"?");
	remove=strcmp(field,"*delete");
	print_table=strcmp(field,"*");
	load=strcmp(field,"*load");
	while(field != NULL){
		if(help ==0){
			printf("Command summary:\n* - print all words in the hashtable\n*load - print length of each linked list\n*delete word - delete word from hashtable\nword - print definition of the word\n? - print this help message\n^D - exit\n");
			return 0;
		}
		if(remove == 0){
			field=strtok(NULL,"~");
			if(field != NULL){
				deletehash(hashtable,field);
			}
			return 0;
		}
		if(print_table == 0){
			printhash(hashtable);
			return 0;
		}
		if(load == 0){
			printload(hashtable);
			return 0;
		}
		else{
			field=strtok(copy,"~");
			findhash(hashtable,field);
			return 0;
		}
	}
}
	
		

