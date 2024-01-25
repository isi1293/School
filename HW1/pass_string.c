#include "city_structure.h"
#include <math.h>

void closest_city(int index, struct CITY *cities, int size);

void pass_string(int size, char *word, struct CITY cities[50])
{
	for(int i=0; i<size; i++)
	{
		if(0 == strcmp(word, cities[i].name))
		{
			printf("[%d] %s %lf %lf %d\n", i, cities[i].name, cities[i].lat, cities[i].lon, cities[i].pop);
			closest_city(i,cities,size);
		}
	}
	
	//If user input is not the name of a city, determine what they want displayed.

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

void closest_city(int city_index, struct CITY *cities, int size)
{
	double temp,a,b;
	int distance=0; //Need to initialize to 0 to access and "re-initialize" on first pass of for loop
	int closest_index;

	for(int i=0; i<size; i++)
	{

		if(city_index!=i)
		{

			a=cities[city_index].lon-cities[i].lon;
			b=cities[city_index].lat-cities[i].lat;

			if(distance==0);
			{
				distance=sqrt(pow(a,2)+pow(b,2));
				temp=distance;
				closest_index=i;
				continue;
			}
				
			distance=sqrt(pow(a,2)+pow(b,2));
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
	a=cities[city_index].lon-cities[closest_index].lon;
	b=cities[city_index].lat-cities[closest_index].lat;
	distance=sqrt(pow(a,2)+pow(b,2));
	printf("\n\na= %lf, b= %lf, distance: %d\n\n",a,b,distance);
	printf(">>Closest City<<\nName: %s\nLat: %lf\nLon:%lf\nPop:%d\n",cities[closest_index].name,cities[closest_index].lat,cities[closest_index].lon,cities[closest_index].pop);

}

