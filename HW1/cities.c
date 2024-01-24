//Isaac Osorio Beltran
//CSE 222, Prof. Nick Macias
//HW1, City Structure

#include "city_structure.h"


int main(void)
{ 
	struct CITY cities[50]; //Array of struct CITY, with 50 max elements
	FILE *fp;
	char buffer[50],word[50];//Buffer to store user input, word to store parsed data
	int num, n, size;

	size = ingest_file(fp, cities);//This function opens the data file for reading, 
				       //stores the data in an array of struct CITY, closes
				       //the file, and returns the size of the array (i.e.
				       //the number of lines in the file)
	
	while(1)
	{
		//Once file is read, capture user input and determine desired function.
		//Loop until user breaks with Ctrl-D
		if(NULL == fgets(buffer,50,stdin)) 
		{
			printf("Goodbye!\n");
			break;
		}
		
		n = sscanf(buffer,"%d", &num);
	
		if(n == 1)
		{
			pass_int(num,cities);	//If main function determines the input as data type int,
						//it calls function which will print the element at the 
					     	//location specified by the user
		}
		else
		{
			n = sscanf(buffer,"%s",word); 
			pass_string(size,word,cities);
							//if main function determines the input as data type
						       //string (array of chars), it calls function which 
						       //will determine what kind of command ('cityname',
						       //'?','*') has been inputted and deal with it 
						       //appropriately
		}
	}

} 
