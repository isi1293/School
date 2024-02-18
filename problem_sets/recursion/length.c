#include <stdio.h>

int len(char *s);

int main(void){
	char string[]="This the one";
	printf("Length of string: %d\n",len(string));
}

int len(char *s){
	if(s[0] == '\0') return 0;
	return 1+len(&s[1]);
}

