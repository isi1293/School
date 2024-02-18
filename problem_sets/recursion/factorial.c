#include <stdio.h>

#define FACT 4

int fact(int n);

int main(void){
	printf("Factorial(%d): %d\n",FACT,fact(FACT));
}

int fact(int n){
	if(n==1) return 1;
	return n*fact(n-1);
}
