#include "list.h"
#include "hash.h"

int testing();

int main(int argc,char **argv){
	HASHENTRY *hashtable;
	//hashtable=inithash();
	testing();
}

int testing(){
	char *word="pineapple",*def="A nice fruit"; 
	struct node *sentinel_1;
	sentinel_1=init();
	add(sentinel_1,string1,string2);
	printlist(sentinel_1);
	return 0;
}

