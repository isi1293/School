#include <stdio.h>
#include "city_structure.h"

int ingest_file(FILE *fp,struct CITY cities[50])
{
	int size;
	char filename[]="/home/notisaac/Clark/CSE222/School/HW1/cities.dat";
		//For server use:"/usr/local/data/cities.dat";
	char buffer[200];//buffer to store individual lines from the file for parsing
	
	fp = fopen(filename, "r");
	if(NULL == fp) //If opening file is unsuccessful
	{
		printf("Could not open the data file :(\n");
	}
	
	size=0;
	while(NULL != fgets(buffer,200,fp)) //If successful, iterate through the file
					    //with fgets, appending each field of each 
					    //line into appropriate elements of stuct 
					    //CITY array
	{
		sscanf(buffer,"%s %lf %lf %d", cities[size].name, &cities[size].lat, &cities[size].lon, &cities[size].pop);
		size++;
	}

	fclose(fp);
	return size;
}
