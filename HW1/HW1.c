//Isaac Osorio Beltran
//CSE 222, Prof. Nick Macias
//1/24/2024
//Description: This main file determines what kind of input the user 
//enters, then passes that data to it's respective function pass_int 
//or pass_string. Loops until the user exits. 

#include "city_structure.h" //Header file that includes all necessary 
			    //libraries, struct definition, prototypes,
			    //etc.


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
		printf(">");
		if(NULL == fgets(buffer,50,stdin)) 
		{
			printf("Goodbye!\n");
			break;
		}
		
		n = sscanf(buffer,"%d", &num); //Will only capture input with a single integer (ex. haha12 invalid)
	
		if(n == 1)
		{
			if(num<0 || num>=size) //Only accept integers within range of list
			{
				printf("Enter an integer in range 0 through %d, or enter '?' for help.\n", size-1);
			        continue;		
			}				 	//If main function determines the input as data type int
			else					//it calls function pass_int() which will print the city at the
			{					//element specified by the user
				pass_int(num,cities);
			}
		}
		else
		{
			n = sscanf(buffer,"%s",word);		//If not an int, checks for *char type
			if(n == 1)
			{	
				pass_string(size,word,cities);  //if main function determines the input as data type
				continue;			//*char, it calls function pass_string() which
			}					//will determine what kind of command ('cityname',
			else					//'?','*') has been inputted and deal with it 
			{					//appropriately
				printf("Not a valid entry. Enter '?' for help.\n");	
			}							
						       					
						       					
						       					
		}
	}

} 
