//Isaac Osorio Beltran
//CSE 222, Prof. Nick Macias
//1/24/2024
//Description: This header file includes all the necessary libraries,
//prototypes, and structure definitions to make the main program work

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct CITY { 			//Structure defined as specified in	
	char name[120];		//assignment instructions
	double lat;
	double lon;
	int pop;
};

int ingest_file(FILE *fp, struct CITY cities[50]);
void pass_int(int num,struct CITY cities[50]);
void pass_string(int size, char *word, struct CITY cities[50]);

