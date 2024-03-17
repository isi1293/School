//Isaac Osorio Beltran
//CSE222 Prof. Nick Macias
//HW5 description: This program is a solution to a 0/1 knapsack problem.
//In main, the program takes the command line arguments, ingests the specified
//file and returns a list of struct items holding the ingested data. The
//program then sends this data, along with the specified bag capacity to 
//max_value where the mix of items that optimizes value is calculated
#include "knap.h"

int main(int argc, char *argv[]){
	//program expects 3 arguments 
	if(argc != 3){
		printf("ERROR: Invalid call to knapsack, expects 3 args\n");
		printf("Usage: [HW5] [int capacity] [char *filename]\n");
		return 1;
	}

	int capacity;
	char *filename;
	filename=malloc(strlen(argv[2]+1)); //+1 for null terminator

	//Some error checking...
	if(sscanf(argv[1],"%d",&capacity) != 1){
		printf("ERROR: Capacity is not an integer\n");
		printf("Usage: [HW5] [int capacity] [char *filename]\n");
		free(filename);
		return 1;
	}
	if(capacity>1024){
		printf("ERROR: Illegal capacity, should be between 1 and 1024\n");
		printf("Usage: [HW5] [int capacity] [char *filename]\n");
		free(filename);
		return 1;
	}
	
	strcpy(filename, argv[2]);

	//Hardcode for testing w/ gdb: 
	//int capacity=1000;
	//char filename[100]="knapsack.data";

	FILE *fp;

	fp=fopen(filename,"r");

	if(fp == NULL){
		printf("ERROR: Could not open file <%s>\n",filename);
		printf("Usage: [HW5] [int capacity] [char *filename]\n");
		free(filename);
		return 1;
	}

	//buffer for line from file
	char buffer[360];
	//Array to store the values from file
	struct item inventory[128]={0};
	//Inventory [0] will represent emptiness; nothingness; 0.
	strcpy(inventory[0].name,"nothing");

	//set count to 1 because 0 is represents nothing
	int count=1;

	while(fgets(buffer,sizeof(buffer),fp) != NULL){
		buffer[-1+strlen(buffer)]='\0';
		inventory[count]=ingest(buffer);
		count++;
	}

	//We're done with the file, time to cleanup
	free(filename);
	fclose(fp);

	//this structure will hold our solution
	//i.e. the loot  \($_$)/
	struct loot max=max_value(capacity,inventory,count);

// ----- Formatting and printing the output ------------- 
	printf("Weight	Value	Name\n");
	printf("------	-----	----\n");
	for(int i=1; i<count; i++){
		printf("%d	%d	%s\n",inventory[i].weight,inventory[i].value,inventory[i].name);
	}
	printf("----------------------\n");
	printf("Bag's Capacity= %d\n",capacity);
	//In the case, there is no solution
	if(max.largest==0) printf("No solution possible\n");
	else printf("Highest possible value= %d\n", max.largest);
	for(int i=1; i<count; i++){
		if(max.tally[i]!=0){
			printf("Item %d (%s): %d\n",i, inventory[i].name, max.tally[i]);
		}
	}

	return 0;
	//		    __
	//		  _/__\_
	//A job well done <(-.-)
	//		     |\
	//		     \\($) <--loot  
}



struct item ingest(char *buffer){
	//Ingest function takes a line from a file with data in the format
	//[Name] [Value] [Weight] and parses this line and stores the data
	//in it's appropriate struct item variable
	char name[32];
	int weight,value;
	struct item new_item;

	sscanf(buffer,"%s %d %d",name,&value,&weight);
	strcpy(new_item.name,name);
	new_item.value=value;
	new_item.weight=weight;
	return new_item;
}

//Our global cache to store the max value of capacity n
//This is used to prune the call tree during recursion 
struct loot cache[1024]={0};

struct loot max_value(int capacity, struct item *inventory,int count){
	//The max_value function uses the algorithm from the lecture video 
	//to find the mix of items that optimizes the value of the knapsack
	
	//The temp variable will hold the calculated value of each recursive 
	//call. Therefore, it can be initialized to 0 each time
	int temp=0;
	struct loot myloot={0};
	if(capacity<=0){
		//Our base case, maximum value of 0 items
		return cache[0];
	}
	//If the max_value of capacity n has been calculated before, we can 
	//retrieve if from the cache and prune the tree.
	if(cache[capacity].largest != 0){
		return cache[capacity];
	}
	//largest initialized to 0
	myloot.largest=0;
	//Tally of the items that make up the max value also intialized to 0.
	//memset initializes (sizeof(myloot.tally)) bytes to 0 starting at the
	//address of myloot.tally
	memset(myloot.tally, 0, sizeof(myloot.tally));
	for(int i=1;i<count;i++){
		if(inventory[i].weight<=capacity){
			struct loot tempLoot=max_value(capacity - inventory[i].weight, inventory, count);
			temp=inventory[i].value + tempLoot.largest;
			if(temp>myloot.largest){
				myloot.largest=temp;
				memcpy(myloot.tally, tempLoot.tally, sizeof(myloot.tally));
				//memcpy copies the tally array from tempLoot (subproblem)
				//to myloot(current problem) in order to keep a running
				//count of the items that make up the largest value thus 
				//far. The absence of this line would cause us to loose 
				//the item count with each recursive call.
				myloot.tally[i]++;
			}
		}
	}
	cache[capacity]=myloot;
	return myloot;
}
