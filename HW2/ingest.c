/*Isaac Osorio Beltran
 * Professor Nick Macias
 *
 * Description: This file ingests a file, inserting them into a linked list
 * in decreasing population order
 * */

#include "list.h"


int ingest(char *input){
	char buffer[500],command[500];
	struct CITY *city;
	FILE *fp;

	fp=fopen(input, "r");
	if(fp == NULL){
		printf("Could not open file named '%s'\n",input);
		return 1;
	}

	
	//DO YOU NEED THIS? char *save_buff;
	//
	//Read file and add 
	while(fgets(buffer,500,fp) != NULL){
		buffer[-1+strlen(buffer)]='\0'; //Replaces newline with NULL terminator
		//At every line, parse data and store in appropriate fields of struct CITY
		//save_buff=buffer;
		city=new_city(buffer);
		add(city);
		
		}
}

struct CITY *new_city(char *data){
	struct CITY *new_city;
	new_city=malloc(sizeof(struct CITY));
	if(new_city == NULL){
		printf("new_city malloc failed\n");
		return NULL;
	}
	char *p_name,*p_lat,*p_lon,*p_pop; //temp variables for parsing
	double lat,lon;
	int pop;
	
	p_name=strtok(data,"|");
	strcpy(new_city->name,p_name);
	p_lat=strtok(NULL,"|");
	sscanf(p_lat,"%lf",&lat);
	new_city->lat=lat;
	p_lon=strtok(NULL,"|");
	sscanf(p_lon,"%lf",&lon);
	new_city->lon=lon;
	p_pop=strtok(NULL,"|");
	sscanf(p_pop,"%d",&pop);
	new_city->pop=pop;
	return new_city;
}

void which_command(char *command){
	char *first_field,*city,*save;
	int help_message, print_all, delete_city;
	command[-1+strlen(command)]='\0'; //removes newline
	strcpy(save,command);
	first_field=strtok(command," ");
	help_message = strcmp(first_field,"?");
	print_all = strcmp(first_field,"*");
	delete_city = strcmp(first_field, "*delete");
	
	if(help_message == 0){
		printf("Command summary:\n* -print all city data\n*delete city - delete city\ncityname - print that city's info\n? - print this help message\n^D - exit\n");
		return;
	}
	if(print_all == 0){
		print();
		return;
	}
	if(delete_city == 0){
		city=strtok(NULL,"~");
		delete(city);
		printf("Deleted <%s>\n",city);
		return;
	}
	else{
		search(save);
		//look for entry in linked list
	}
}
