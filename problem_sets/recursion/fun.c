#include <stdio.h>

void fun();
void fun2(int n);

int main(void){
	fun();
}

void fun(){
	fun2(10);
}
void fun2(int n){
	printf("Inside fun2, argument=%d\n",n);
	if(n>1) fun2(n-1);
}

