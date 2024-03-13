#include <stdio.h>
#include <string.h>

void fib_iterative(int n);

int main(void){
	fib_iterative(51);
}


void fib_iterative(int n){
	long unsigned int fib50[n];
	memset(fib50, 0, sizeof(fib50));
	fib50[1]=1;
	for(int i = 0;i < n; i++){
		if(i >= 2){
			fib50[i]=fib50[i-1]+fib50[i-2];
		}
		printf("%lu ",fib50[i]);
	}
}




