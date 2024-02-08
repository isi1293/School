#include "list.h"

int main(int argc, char **argv){
	char command[120];
	

	//TESTING: char filename[]=
	/*
	//buffer for input from stdin
	if(argc == 2){
		init();
		ingest(argv[1]);
	}
	*/
	init();
	//ingest("/home/notisaac/Clark/CSE222/School/HW2/cities2.dat");
	ingest("/home/notisaac/Clark/CSE222/School/HW2/cities2-bad.dat");

	while(1){
		printf(">");
		if(NULL == fgets(command,sizeof(command),stdin)){
			printf("Goodbye!\n");
			release();
			break;
		}

		which_command(command);
		}


}

