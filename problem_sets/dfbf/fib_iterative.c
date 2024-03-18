#include <stdio.h>
#include <string.h>
#include <time.h>

void fib_iterative(int n);
long unsigned int fib_recursive(int n);

int count;
time_t start,end;
double time_elapsed;

int main(void){
	/*
	 * printf("----fib_iterative()----\n");
	fib_iterative(51);
	printf("----fib_recursive()----\n");
	fib_recursive(50);
	*
	*/
	fib_iterative(51);
	for(int n=0;n<51;n++){
		double elapsed_time;
		count=0;
		start=time(NULL);
		long unsigned int result=fib_recursive(n);
		end=time(NULL);
		time_elapsed = difftime(end, start);
		printf("fib(%d)=%lu; # of calls=%d\n",n,result,count);
		printf("Elapsed time (s):%.2f\n",(time_elapsed));
	}
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
	printf("\n");
}

long unsigned int fib_recursive(int n){
	count++;
	if(n<=2) return 1;
	else return fib_recursive(n-1) + fib_recursive(n-2);
}
