//Isaac Osorio Beltran
//CSE222 Prof. Nick Macias
//Description: ingest.c holds functions that deal with processing user
//input such as the entry/parsing of the database, and commands thereafter.

#include "list.h"

int ingest(char *filename){
	FILE *fp;
	char buffer[500],savebuffer[500];
	int i=0; //counter for first while loop
	
	fp=fopen(filename,"r");
	if(fp == NULL){
		printf("Could not open file\n");
		return 1;
	}
	//process the file
	if(init() != 0){
		printf("Unsuccessful Initialization\n");
	}

	while(fgets(buffer,500,fp) != NULL){
		buffer[-1+strlen(buffer)]='\0';
		strcpy(savebuffer,buffer);
		//replace trailing newline with null terminator
		if(newcity(buffer,i) != 0){
			printf("[ingest.c: ingest] Could not ingest line [%d]: <%s>\n",i,savebuffer);
			i++;
			continue;
		}
		i++;
	}
	fclose(fp);
	//printf("Successfully ingested file!\n");
	return 0;
}

int newcity(char *citydat,int index){
	char saveline[100],buffer[50];
	//copy of citydat, and buffer for strtok return
	char *field,name[120];
	double lat,lon;
	int pop,flag=0;
	//variables for storage of strtok
	strcpy(saveline,citydat);//just in case I need this
	field=strtok(citydat,"|");
	while(field != NULL){
		if(flag==0){
			strcpy(name,field);
			flag++;
			field=strtok(NULL,"|");
			continue;
		}
		if(flag==1){
			if(sscanf(field,"%lf",&lat) != 1){
				printf("[ingest.c: newcity] Invalid lat field on line [%d]\n",index);
				return 1;
			}
			flag++;
			field=strtok(NULL,"|");
			continue;
		}
		if(flag==2){
			if(sscanf(field,"%lf",&lon) != 1){
				printf("[ingest.c: newcity] Invalid lon field on line [%d]\n",index);
				return 1;
			}
			flag++;
			field=strtok(NULL,"|");
			continue;
		}
		if(flag==3){
			if(sscanf(field,"%d",&pop) != 1){
				printf("[ingest.c: newcity] Invalid pop field on line [%d]\n",index);
				return 1;
			}
			flag++;
			field=strtok(NULL,"|");
			continue;
		}
		if(flag==4){
			printf("[ingest.c: newcity] Too many fields on line on line [%d]\n",index);
			return 1;
		}
	}
	if(flag!=4){
		printf("[ingest.c: newcity()] Not enough fields on line [%d]\n",index);
		return 1;
	}
	//Add parsed data to appropriate fields in node->data
	add(name,lat,lon,pop);
	return 0;
}

int which_command(char *input){
	char *field,copy[100];
	int help,remove,print_list;
	int flag=0;

	strcpy(copy,input);
	//This copy preserves orignal input before mutilation by strtok
	field=strtok(input," ");
	//Capture first field of input
	help=strcmp(field,"?");
	remove=strcmp(field,"*delete");
	print_list=strcmp(field,"*");
	//Series of strcmps to determine command
	while(field != NULL){
		if(help == 0){
			printf("Command summary:\n* -print all city data\n*delete city - delete city\ncityname - print that city's info\n? - print this help message\n^D - exit\n");
			return 0;
		}
		if(remove == 0){
			field=strtok(NULL,"~");
			if(field != NULL){
				delete(field);
			}
			return 0;
		}
		if(print_list == 0){
			print_all();
			return 0;
		}
		else{
			field=strtok(copy,"~");
			search(field,"p");
			return 0;
		}
	}
}


	




