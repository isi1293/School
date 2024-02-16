//Isaac Osorio Beltran
//CSE222 Prof. Nick Macias
//Description: ingest.c holds functions that deal with processing user
//input such as the entry/parsing of the database, and commands thereafter.

#include "list.h"

int ingest(char *filename){
	FILE *fp;
	char buffer[500],savebuffer[500];
	int i=0; //counter for first while loop
	
	//open file for reading 
	fp=fopen(filename,"r");
	if(fp == NULL){
		printf("Could not open file\n");
		return 1;
	}
	//Call to initialize function, creates sentinel node
	//i.e.the foundation of the linked list
	if(init() != 0){
		printf("Unsuccessful Initialization\n");
	}
	
	//parse through data file until last line (NULL)
	while(fgets(buffer,500,fp) != NULL){
		buffer[-1+strlen(buffer)]='\0';
		//rm newline
		strcpy(savebuffer,buffer);
		//save buffer because it is altered in newcity function through strtok
		if(newcity(buffer,i) != 0){
			//newcity will return a specific error if it is unable to parse
			//Error is printed in conjunction with line below
			printf("[ingest.c: ingest()] Could not ingest line [%d]: <%s>\n",i,savebuffer);
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
	//Desc: takes 2 arguments, line of city data and the index
	//of that line. In short, newcity either populates a new node
	//or prints an error in the parsing process.
	
	char saveline[100],buffer[50];
	//copy of citydat, and buffer for strtok return
	char *field,name[120];
	double lat,lon;
	int pop,flag=0;

	//Variables for storage of strtok
	//Flag use: flag is used for case handling. Since city data
	//is mostly uniform, this flag is useful in capturing cases
	//where the data recieved is not what the program expects
	//(i.e four fields [name|lat|lon|pop]
	
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
				printf("[ingest.c: newcity()] Invalid lat field on line [%d]\n",index);
				return 1;
			}
			flag++;
			field=strtok(NULL,"|");
			continue;
		}
		if(flag==2){
			if(sscanf(field,"%lf",&lon) != 1){
				printf("[ingest.c: newcity()] Invalid lon field on line [%d]\n",index);
				return 1;
			}
			flag++;
			field=strtok(NULL,"|");
			continue;
		}
		if(flag==3){
			if(sscanf(field,"%d",&pop) != 1){
				printf("[ingest.c: newcity()] Invalid pop field on line [%d]\n",index);
				return 1;
			}
			flag++;
			field=strtok(NULL,"|");
			continue;
		}
		if(flag==4){
			printf("[ingest.c: newcity()] Too many fields on line on line [%d]\n",index);
			return 1;
		}
	}
	if(flag!=4){
		printf("[ingest.c: newcity()] Not enough fields on line [%d]\n",index);
		return 1;
	}
	//If data is uniform, create a new node and add parsed data to appropriate fields in node->data
	add(name,lat,lon,pop);
	return 0;
}

int which_command(char *input){
	//Desc: This command takes user input and 
	//determines the desired command/behavior
	char *field,copy[100];
	int help,remove,print_list;
	//variables to store strcmp return for clarity

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


	




