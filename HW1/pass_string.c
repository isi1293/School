#include "city_structure.h"
#include <math.h>

void closest_city(int index, struct CITY *cities, int size, struct CITY city);

void pass_string(int size, char *word, struct CITY cities[50])
{
	for(int i=0; i<size; i++)
	{
		if(0 == strcmp(word, cities[i].name))
		{
			printf("[%d] %s %lf %lf %d\n", i, cities[i].name, cities[i].lat, cities[i].lon, cities[i].pop);
			closest_city(i,cities,size,cities[i]);
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

void closest_city(int city_index, struct CITY *cities, int size, struct CITY city)
{
	double temp;
	int distance=0; //Need to initialize to 0 to access and "re-initialize" on first pass of for loop
	int closest_index;

	for(int i=0; i<size; i++)
	{
		if(city_index!=i)
		{
			if(distance==0)
			{
				distance=sqrt((pow((city.lon-cities[i].lon),2))+(pow((city.lat-cities[i].lat),2)));
				temp=distance;
				continue;
			}
			
			distance=sqrt(pow((city.lon-cities[i].lon),2)+pow((city.lat-cities[i].lat),2));
			if(distance<temp)
			{
				temp=distance;
				closest_index=i;
			}
		}
		else
		{
		continue;
		}		

	}
	printf(">>Closest City<<\nName: %s\nLat: %lf\nLon:%lf\nPop:%d\n",cities[closest_index].name,cities[closest_index].lat,cities[closest_index].lon,cities[closest_index].pop);

}

