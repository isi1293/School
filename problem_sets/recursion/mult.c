#include <stdio.h>

int mult(int a,int b);

int main(void){
	printf("> %d\n",mult(12,5));
}

int mult(int a, int b){
	if(b==1) return a;
	return a+mult(a,b-1);
}
