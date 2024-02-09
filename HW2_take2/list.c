//Isaac Osorio Beltran
//CSE222, Prof. Nick Macias
//[list.c] Description: This file contains the implementaion
//of a linked list. Functions include init(),new(),add(),delete(),
//search(), and release(). See individual function for more desc.

#include "list.h" //Header with prototypes/libraries

struct node *sentinel; //Global sentinel

struct node *new(){
	//desc: new function creates a new node, allocating the 
	//appropriate mem in the appropriate fields. Appropriately.
	struct node *new_node;
	struct city *new_city;
	new_node=malloc(sizeof(struct node));
	new_city=malloc(sizeof(struct city));
	new_node->data=new_city;
	new_node->next=NULL;
	return new_node;
}

int init(){
	sentinel=new();
	free(sentinel->data);
	//memory allocated for city structure by new 
	//will not be used, so free immediately
	sentinel->data=NULL;
	return 0;
}

int add(char *iname,double ilat,double ilon,int ipop){
	//Desc: recieve parsed data from newcity function
	//in ingest.c. Use this data to create a new node.
	//Then, sandwich that node.
	//For clarity, incoming variables prefixed with i
	struct node *temp,*new_node;
	temp=sentinel;
	if(search(iname,"np") == 0){
		//found a duplicate, skip
		return 0;
	}
	while(temp->next != NULL){
		if(ipop > temp->next->data->pop){
			//Decending order
			new_node=new();
			strcpy(new_node->data->name,iname);
			new_node->data->lat=ilat;
			new_node->data->lon=ilon;
			new_node->data->pop=ipop;
			new_node->next=temp->next;
			temp->next=new_node;
			//sandwich that new node
			return 0;
		}
		temp=temp->next;
	}
	//In case the of first node, or node with lowest data value
	new_node=new();
	strcpy(new_node->data->name,iname);
	new_node->data->lat=ilat;
	new_node->data->lon=ilon;
	new_node->data->pop=ipop;
	new_node->next=temp->next;
	temp->next=new_node;
	return 0;
}

int delete(char *cityname){
	//Desc: delete node specified in which_command() from ingest.c
	struct node *temp,*save;
	temp=sentinel;
	while(temp->next != NULL){
		if(strcmp(temp->next->data->name,cityname) == 0){
			//Found match
			save=temp->next;
			temp->next=temp->next->next;
			free(save->data);
			free(save);
			return 0;
			//skip over the node, free, then return
		}
		temp=temp->next;
	}
	//If delete() made it this far, there is no match to delete
	printf("Did not find <%s>, could not delete\n",cityname);
	return 1;
}

int search(char *cityname,char *mode){
	//Desc: search linked list, return 0 if match found
	//return 1 otherwise. Second argument indicates print
	//entry or not print entry.
	struct node *temp;
	temp=sentinel->next;
	while(temp != NULL){
		if(strcmp(temp->data->name,cityname) == 0){
			//Match found
			if(strcmp(mode,"p") == 0){
			//If function has print mode enabled, print entry as well as return
			printf("City: %s   Lat: %lf   Lon: %lf   Population: %d\n",temp->data->name,temp->data->lat,temp->data->lon,temp->data->pop);
			}
			return 0;
		}
		temp=temp->next;
	}
	//No match found
	if(strcmp(mode,"p") == 0){
		printf("[list.c: search()] no match to <%s> found\n",cityname);
	}
	return 1;
}

int release(){
	//Desc: free dynamic memory when finished using
	struct node *temp,*prev;
	temp=sentinel->next;
	prev=sentinel;
	while(temp != NULL){
		free(prev->data);
		free(prev);
		prev=temp;
		temp=temp->next;
	}
	//Reached the last node
	free(prev->data);
	free(prev);
	return 0;
}	

int print_all(){
	//Desc: print data contents of linked list
	struct node *temp;
	temp=sentinel->next;
	int i=0; //Optional counter
	while(temp != NULL){
		printf("City: %s   Lat: %lf   Lon: %lf   Population: %d\n",temp->data->name,temp->data->lat,temp->data->lon,temp->data->pop);
		temp=temp->next;
		i++;
	}
	return 0;
}

