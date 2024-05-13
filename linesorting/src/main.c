#include <stdio.h>
#include "../include/readlines.h"
#include "../include/writelines.h"
#include "../include/quicksort.h"

int main(void)
{
	char *input[MAXLINE]; 
	int numlines = readlines(input, MAXLINE); 
	writelines(input, numlines);

	printf("compare 0, 1 %d", strcompare(input[0], input[1]));

	return 0;
}
