#include <stdio.h>

void print(int *data,int len);

int main(void){
	int myarray[5]={1,2,3,4,5};
	print(myarray,5);
}

void print(int *data,int len){
	if(len ==0) return;
	else{
		printf("> %d \n",data[0]);
		print(&data[1],(len-1));
	}
}

