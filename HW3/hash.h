#define SIZE 100

typedef struct node *HASHENTRY;

int hash(char *word);
//return hash value for given word
HASHENTRY *inithash();
//create array of 100 pointers to sent
//nodes. Return arary.
void addhash(HASHENTRY *hashtable, char *word, char *def);
//add given word/def parit to hashtable
char *findhash(HASHENTRY *hashtable,char *word);
//search hashtable for word, return 1 on success, 
//0 otherwise
int deletehash(HASHENTRY *hashtable,char *word);
//delete word from hashtable, return 1 on success,
//0 otherwise

//If done right, three prev functions can be implemented
//in one line

void freehash(HASHENTRY *hashtable);
//release ALL mem associated with hash table. This means
//all 100 linked lists and array itself that was created 
//in inithash. Keep to 3 lines or less
void printhash(HASHENTRY *hashtable);
//print all data in hash table. Function called with "*"
//command. Keep to 2 lines
void printload(HASHENTRY *hashtable);
//print length of each linked list in the hash table.
//Keep to 2 lines of code


//--list.c prototypes--


int ingest(HASHENTRY *hashtable,char *filename);


