#include <stdio.h>

struct inventory{
	int length;
	int value;
};

int max_val(int n);
int inventory[9]={0,1,2,7,9,15,16,17,20};

int main(void){
	printf("%d\n",max_val(8));
	printf("%d\n",max_val(1));
	printf("%d\n",max_val(7));
	printf("%d\n",max_val(2));
}

int largest,temp;
int cache[1000]={0};
int max_val(int n){
	if(n==0){
		return 0;
	}
	if(cache[n] != 0){
		return cache[n];
	}
	largest=0;
	for(int i=1;i<=n;i++){
		if(i<=n){
			temp=inventory[i]+max_val(n-i);
			if(temp>largest) largest=temp;
		}
	}
	cache[n]=largest;
	return largest;
}

