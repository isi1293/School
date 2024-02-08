#include <stdio.h>
#include <string.h>

int init();

int main(void){
	init();
}

int init(){
	FILE *fp;
	char *filename;
	char buffer[500];
	
	//Eventually this will be given by the usr
	//filename=input;
	filename="/home/notisaac/Clark/CSE222/School/HW2/cities2.dat";
	fp=fopen(filename, "r");
	if(fp == NULL){
		printf("Could not open file");
		return 1;
	}
	while(fgets(buffer,500,fp) != NULL){
		printf("%s", buffer);
		}
	return 0;
}
