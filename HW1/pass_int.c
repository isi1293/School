//Isaac Osorio Beltran
//CSE 222, Prof. Nick Macias
//1/24/2024
//Description: The pass_int.c function is called only in the case the user enters a single
//integer. It then takes that integer and prints the element of the struct city array specified
//by the integer entered.

#include "city_structure.h"

//This function prints the elements of city[num]

void pass_int(int num,struct CITY cities[50])
{
	printf("Name: %s\nLatitude: %.4lf\nLongitude: %.4lf\nPopulation: %d\n\n", cities[num].name, cities[num].lat, cities[num].lon, cities[num].pop);
}
