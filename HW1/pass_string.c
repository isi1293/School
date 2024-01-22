#include <stdio.h>
#include <string.h>
#include "city_structure.h"

void pass_string(int size, char *word, struct CITY cities[50])
{
	for(int i=0; i<size; i++)
	{
		if(0 == strcmp(word, cities[i].name))
		{
			printf("[%d] %s %lf %lf %d\n", i, cities[i].name, cities[i].lat, cities[i].lon, cities[i].pop);
		}
	}

	int help_message, print_all;

	help_message = strcmp(word, "?");
	print_all = strcmp(word, "*");

	if(help_message == 0)
	{
		printf("Enter an integer or name to see information of specific\ncity, as well as information on the nearest city.\n\nEnter '*' to display every city in the array\n");
	}
	if(print_all == 0)
	{
		for(int i=0; i<size; i++)
		{
			printf("[%d] %s %lf %lf %d\n", i, cities[i].name, cities[i].lat, cities[i].lon, cities[i].pop);
		}

	}
}	
