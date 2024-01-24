#include "city_structure.h"

//This function prints the elements of city[num]

void pass_int(int num,struct CITY cities[50])
{
	printf("[%d] %s %lf %lf %d\n", num, cities[num].name, cities[num].lat, cities[num].lon, cities[num].pop);
	//printf("[%d] %s %lf %lf %d\n", num, cities[num+1].name, cities[num+1].lat, cities[num+1].lon, cities[num+1].pop);
}
