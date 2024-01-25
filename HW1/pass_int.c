#include "city_structure.h"

//This function prints the elements of city[num]

void pass_int(int num,struct CITY cities[50])
{
	printf("Name: %s\nLatitude: %.4lf\nLongitude: %.4lf\nPopulation: %d\n\n", cities[num].name, cities[num].lat, cities[num].lon, cities[num].pop);
}
