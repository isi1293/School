#include "list.h"

int main(void){
	init();
	add(1);
	add(2);
	add(100);
	add(50);
	print_all();
	delete(100);
	search(100);
	search(50);
	print_all();
	release();
}
