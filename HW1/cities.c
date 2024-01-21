#include <stdio.h>
#include <string.h>
#include "city_structure.h"
//structure defined in header with elements:
//	char name[50];
//	double lat, lon;
//	int pop;

void ingest_file(FILE *fp); //funtion to read and parse data from file

void print(int size, struct CIITY *cities);

int main(void)
{ 
	struct CITY cities[50];
	FILE *fp;
	buffer[50];
	char word[50];
	int num, n;

	printf("Hello! Enter the name of a city or a number to begin, '?' for help.\n")
	fgets(buffer,50,stdin);
	n = sscanf(buffer,"%d%s",num,entry);
	
	if(n == 1)
	{

	//BETA
	
	if(entry == "?")
	{
		printf("Help message, mention structure of data, commands, etc\n");
	}	

	if(entry == "*")
	{
		print(cities);
	}

	if(type(entry) == int)
	{
		Access_array(cities);
	}

} 

int ingest_file(FILE *fp)
{
	int size;

	char buffer[500]; //buffer to store individual lines from the file for parsing

	fp = fopen(filename,"/usr/local/bin/cities.dat");
	
	if(NULL == fopen(filename,"/usr/local/bin/cities.dat")
	{
		printf("Could not open the data file :(\n");
	}

	fclose(fp);
	return size;
}


