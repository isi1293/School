#include "list.h"
#include "hash.h"

int main(int argc,char **argv){
	/*if(argc != 2){
		if(argc>2) printf("[HW3.c][main()] Invalid call to program, too many arguments\n");
		if(argc<2) printf("[HW3.c][main()] Invalid call to program, not enough arguments\n");
		return 1;
	}*/

	char buffer[120];
	HASHENTRY *hashtable;
	hashtable=inithash();
	
	if(ingest(hashtable,"/home/notisaac/Clark/CSE222/School/HW3/dictionary.txt"));
	if(ingest(hashtable,argv[1])==0){
		while(1){
			printf("> ");
			if(fgets(buffer,sizeof(buffer),stdin) == NULL){
				printf("Goodbye\n");
				freehash(hashtable);
				return 0;
			}
			else{
				buffer[-1+strlen(buffer)]='\0';
				//which_command(buffer);
			}
		}
	}
}
