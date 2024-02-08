#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct CITY{
	char name[50];
	double lat;
	double lon;
	int pop;
};

struct NODE{
	struct CITY *data;
	struct NODE *next;
};

/*---LINKED LIST PROTOTYPE---*/
//These functions can be found in list.c

void add(struct CITY *new_city);
//Inserts to list in decreasing population order
void init(); 
//Initializes linked list (makes sentinel)
void release(); 
//Frees memory
void delete(char *cityname);
//deletes node
void print();
//prints linked list
int search(char *cityname);
//looks for city in list

/*---STRUCT CITY PROTOTYPES---*/
//These functions can be found in ingest.c

struct CITY *new_city(char buffer[500]);
//creates new city struct from buffer
int ingest(char *filename);
//ingests file, stores each line of database
//to a CITY structure
void which_command(char *input);
//determines what behavior the usr wants


