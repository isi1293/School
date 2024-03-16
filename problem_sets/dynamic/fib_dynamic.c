#include <stdio.h>
#include <string.h>
#include <time.h>

void fib_iterative(int n);
long long unsigned int fib_recursive(int n);

int count;
time_t start,end;
double time_elapsed;
long long unsigned int cache[1000];

int main(void){
	memset(cache,0,sizeof(cache));
	/*
	 * printf("----fib_iterative()----\n");
	fib_iterative(51);
	printf("----fib_recursive()----\n");
	fib_recursive(50);
	*
	*/
	fib_iterative(101);
	for(int n=1;n<101;n++){
		double elapsed_time;
		count=0;
		start=time(NULL);
		long long unsigned int result=fib_recursive(n);
		end=time(NULL);
		time_elapsed = difftime(end, start);
		printf("fib(%d)=%llu; # of calls=%d\n",n,result,count);
		printf("Elapsed time (s):%.2f\n",(time_elapsed));
	}
}

void fib_iterative(int n){
	long long unsigned int fib100[n];
	memset(fib100, 0, sizeof(fib100));
	fib100[1]=1;
	for(int i = 0;i < n; i++){
		if(i >= 2){
			fib100[i]=fib100[i-1]+fib100[i-2];
		}
		printf("%llu ",fib100[i]);
	}
	printf("\n");
}

long long unsigned int fib_result=0;

long long unsigned int fib_recursive(int n){
	count++;
	if(cache[n] != 0) return cache[n];
	if(n<=2) return 1;
	else{
		fib_result=fib_recursive(n-1) + fib_recursive(n-2);
		cache[n]=fib_result;
		return fib_result;
	}
}
