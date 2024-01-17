#include <stdio.h>
#include <string.h>
#include "city_structure.h"
//structure defined in header with elements:
//	char name[50];
//	double lat, lon;
//	int pop;

void ingest_file(FILE *fp); //funtion to read and parse data from file

int main(void)
{ 
	struct CITY cities[50];
	FILE *fp;

}

void ingest_file(FILE *fp)
{
	char buffer[500]; //buffer to store individual lines from the file for parsing

	fp = fopen(filename,"/usr/local/bin/cities.dat");
	
	if(NULL == fopen(filename,"/usr/local/bin/cities.dat")
	{
		printf("Could not open the data file :(\n");
	}

	fclose(fp);
}
