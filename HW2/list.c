//Isaac Osorio Beltran
//Professor Nick Macias
//CSE 222
//Description: This program contains all the functions of a linked list

#include "list.h"

struct NODE *sentinel;

struct NODE *new_node(struct CITY *new_city){
	struct NODE *temp;

	temp=malloc(sizeof(struct NODE));
	temp->data=new_city;
	temp->next=NULL;

	return temp;
}

void init(){
	sentinel=malloc(sizeof(struct NODE));
	sentinel->data=NULL;
	sentinel->next=NULL;
}

void add(struct CITY *new_city){
	struct NODE *temp,*new;
	int lowest_pop;
	temp=sentinel;
	while(temp->next != NULL){
		if((new_city->pop) > (temp->next->data->pop)){
			new=new_node(new_city);
			new->next=temp->next;
			temp->next=new;
			return;
		}
		temp=temp->next;
		//reads file and adds them to linked list
		//in decreasing population order
	}
	//In the case the list is empty
	new=new_node(new_city);
	new->next=temp->next;
	temp->next=new;
	return;
}

void delete(char *city_name){
	struct NODE *temp, *save;
	temp=sentinel;
	while(temp->next != NULL){
		if(strcmp(temp->next->data->name, city_name) == 0){
			//found a match
			save=temp->next;
			temp->next=temp->next->next;
			free(save->data);
			free(save);
			return;
		}
		temp=temp->next;
	}
	printf("City <%s> does not in list, could not delete\n",city_name);

}

		
void print(){
	struct NODE *temp;
	temp=sentinel;
	if((temp->data==NULL)){
		temp=temp->next;
	}
	while(temp != NULL){
		printf("City: %s Lat: %lf Lon: %lf Population: %d\n",temp->data->name,temp->data->lat,temp->data->lon,temp->data->pop);
		temp=temp->next;
	}

}
//search function looks for cityname in list of cities. Called by which command (ingest.c) in the case where no other command was specified
int search(char *cityname){
	struct NODE *temp;
	temp=sentinel;
	while(temp->next != NULL){
		if(temp->next != NULL){
			if(strcmp(cityname,temp->next->data->name) == 0){
				printf("%s %lf %lf %d\n",temp->next->data->name,temp->next->data->lat,temp->next->data->lon,temp->next->data->pop);
				return 1;
			}
			temp=temp->next;	
		}
	}
	//if no match was found
	printf("Error: no city named '%s' was found\n",cityname);
	return 0;
}

void release(){
	struct NODE *temp,*save;
	temp=sentinel;
	while(temp->next != NULL){
		save=temp;
		temp=temp->next;
		free(save->data);
		free(save);
	}
	free(temp->data);
	free(temp);
}

