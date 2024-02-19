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
	add(sentinel_1,word,def);
	add(sentinel_1,"bomboclat","many things");
	add(sentinel_1,"bop lore","F in the chat");
	printlist(sentinel_1);
	find(sentinel_1,"bomboclat");
	find(sentinel_1,"this one");
	delete(sentinel_1,"bomboclat");
	printf("List length:%d\n",listlen(sentinel_1));
	printlist(sentinel_1);
	freelist(sentinel_1);
	return 0;
}

