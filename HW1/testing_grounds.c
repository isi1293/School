#include <stdio.h>

int main(void)
{
	char buffer[50], entry[50];
	int size, num, n;
	char entry_2[50];
	int num_2;

	fgets(buffer,50,stdin);
	n = sscanf(buffer, "%d", &num_2);
	n = sscanf(buffer, "%s", entry_2);
	
	num = num_2 + 5;
	printf("Number Variable: %d\n", num);
	printf("String Variable: %s\n", entry_2);
	/*if((num_2 + 1) != NULL)
	{
		printf("This is a number\n");
	}
	else
	{
		printf("This is not a number\n");
	}*/


	return 1;

}
