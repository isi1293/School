#include "list.h"

int main(int argc,char **argv){
	HASHENTRY *hashtable;
	hashtabe=inithash();
	testing();
}

int testing(void){
	sentinel_1=init();
	add(sentinel_1,"cherry","A nice fruit");
	add(sentinel_1,"boat","Let me drive");
	add(sentinel_1,"mouse","Vermin");
	add(sentinel_1,"family","Dom torreto");
	printlist(sentinel_1);
	return 0;
}

