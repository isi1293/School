//Isaac Osorio Beltran
//CSE222 Prof. Nick Macias
//Description: HW2.c is the central hub for the entire program. From here
//the program calls to ingest.c and list.c in order to produce desired
//program behavior.

#include "list.h"

int main(int argc,char **argv){
	char buffer[50];
	//buffer for user input
	
	
	if(argc != 2){
		//Program execution requires location to the database.
		//if the second field is missing, return error.
		printf("[HW2.c: main] Invalid call to main\n");
		return 1;
	}

//--------------------------Testing Tings---------------------------------------------
	//if(ingest("/home/notisaac/Clark/CSE222/School/HW2/cities2.dat") == 0){
	//if(ingest("/home/notisaac/Clark/CSE222/School/HW2/cities2-bad.dat") == 0){
	//if(ingest(argv[1]) == 0){
	//Hardcoded filename for debugging
//------------------------------------------------------------------------------------

	if((ingest(argv[1]) == 0)){
	//Successfully ingested file
		while(1){
			//Loop until user breaks with CTRL-D
			printf("> ");
			if(fgets(buffer,sizeof(buffer),stdin) == NULL){
				printf("Goodbye!\n");
				release();
				//free all memory before exit
				return 0;
			}
			else{
				//If not CTRL-D, send user input
				//to be processed, remove newline
				buffer[-1+strlen(buffer)]='\0';
				which_command(buffer);
			}
		}
	}
}
			


