#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//This structure holds our data from the specified file
struct item{
	char name[32];
	int value;
	int weight;
};

//This structure is used to hold the data we return through the max_value
//function. The tally array keeps count of the number of items that make up
//the max value in a solution. The largest variable holds said max value.
struct loot{
	int tally[128];
	int largest;
};

//This function returns a newly populated struct item
struct item ingest(char *buffer);

//This function calculated the max value for a given bag capacity
struct loot max_value(int capacity, struct item *inventory,int count);
