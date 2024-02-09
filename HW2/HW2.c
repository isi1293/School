#include "list.h"

int main(int argc, char **argv){
	char command[120];
	
	init();
	ingest("/home/notisaac/Clark/CSE222/School/HW2/cities2.dat");
	//ingest("/home/notisaac/Clark/CSE222/School/HW2/cities2-bad.dat");

	while(1){
		printf(">");
		if(NULL == fgets(command,sizeof(command),stdin)){
			printf("Goodbye!\n");
			release();
			break;
		}
		else{
		which_command(command);
		}

	}
}

