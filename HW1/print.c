#include <stdio.h>
#include "city_structure.h"

void print(int size, struct CITY *cities)
{
	for(int i=0;i<size;i++)
	{
		printf("%s, %lf, %lf, %d\n", cities[i].name, cities[i].lat, cities[i].lon, cities[i].pop);
	}
}
