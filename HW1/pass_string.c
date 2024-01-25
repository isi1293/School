//Isaac Osorio Beltran
//CSE 222, Prof. Nick Macias
//1/24/2024
//Description: The pass_string.c function is called only in the case the user enters a single string
//it then determines if the user entered the name of a city in the list, a '*' or a '?'. It handles
//each case differently and prints the appropriate response.

#include "city_structure.h"

void closest_city(int index, struct CITY *cities, int size); //Function to determine the closest city using pythagorean formula

void pass_string(int size, char *word, struct CITY *cities) //Pass_string makes sense of the string entered to the program and 
{							   //prints out the appropriate response
	int result; //Variable to hold result of strcmp

	for(int i=0; i<size; i++) //Loops through entire city list, looking for an exact match with cities name
	{
		result=strcmp(word,cities[i].name);
		if(0 == result)
		{
			printf("Name: %s\nLatitude: %.4lf\nLongitude: %.4lf\nPopulation: %d\n", cities[i].name, cities[i].lat, cities[i].lon, cities[i].pop);
			closest_city(i,cities,size);
		}
	}
	
	//If user input is not the name of a city, determine what they want displayed.

	int help_message, print_all;

	help_message = strcmp(word, "?");
	print_all = strcmp(word, "*");

	if(help_message == 0)
	{
		printf("Command summary:\n* - print all city data\ninteger - print that city's info\ncityname - print that city's info, along with the name of the closest city\n? - print this help message\n^D - exit\n\n");
	}
	if(print_all == 0)
	{
		for(int i=0; i<size; i++)
		{
			printf("(%d) Name: %s\nLatitude: %.4lf\nLongitude: %.4lf\nPopulation: %d\n\n", i, cities[i].name, cities[i].lat, cities[i].lon, cities[i].pop);
		}

	}
	else
	{
		printf("No city matching '%s' found. Enter '?' for help\n", word);
	}
}

void closest_city(int city_index, struct CITY *cities, int size) //Function prints closest city when the name of a city is given
								 //to executable. City_index is the index of the city specified by
								 //the user. *cities is the entire city list. size is the size of said list
{
	double a,b; //These variable hold the difference between lat and lon of the city specified by
		    //the user and the one that the for loop is comparing it to. Think of these variables
		    //as the opposite and adjacent sides of a triangle, which enables us to use the 
		    //Pythagorean theorem 

	int closest_index; //Index of the current closest city

	double temp,distance=999.999;	//I initialized distance to a large, obscure, number so that the conditional if satement
					//in the for loop can not be accessed except for on the first pass. 
	for(int i=0; i<size; i++)
	{

		if(city_index!=i) //Don't compare the city to itself, otherwise the closest city will be itself
		{

			a=(cities[city_index].lon-cities[i].lon);
			b=(cities[city_index].lat-cities[i].lat);

			if(distance==999.999) //This conditional statement 'initializes' distance once again on the first pass
			{
				distance=sqrt(pow(a,2)+pow(b,2));
				temp=distance; //Temp stores the current smallest distance
				closest_index=i;//Similarly, closest_index stores the index of the
						//city that produced the smallest distance 
				continue;
			}
				
			distance=sqrt(pow(a,2)+pow(b,2)); //A squared plus B squared equals C squared \(O.O)/
			if(distance<temp) //If the function finds a distance smaller than all previous distances 
			{		  //it sets temp and closest_index to those new values
				temp=distance;
				closest_index=i;
			}
		}
		else
		{
		continue;
		}		

	}
	printf("Closest City is %s\n\n", cities[closest_index].name);

}

