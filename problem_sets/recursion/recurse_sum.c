#include <stdio.h>

int sum(int n); //return product of first n integers (n!)

#define NUM 10

int main(void){
	printf("> %d\n",sum(NUM));
}

int sum(int n){
	if(n==1) return 1;
	return n+sum(n-1);
}
