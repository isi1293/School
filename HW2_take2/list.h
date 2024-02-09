#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct city{
	char name[120];
	double lat;
	double lon;
	int pop;
};


struct node{
	struct city *data;
	struct node *next;
};

//---Prototypes for list.c---
int init();
struct node *new();
int add(char *name,double lat,double lon,int pop);
int delete(char *cityname);
int search(char *cityname,char *mode);
int release();
int print_all();

//---Prototypes for ingest.c---
int which_command();
int ingest(char *filename);
int newcity(char *citydat,int index);
