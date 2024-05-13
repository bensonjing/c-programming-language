#include <stdio.h>
#include "../include/readlines.h"
#include "../include/writelines.h"
#include "../include/quicksort.h"

int main(void)
{
	char *input[MAXLINE]; 
	int numlines = readlines(input, MAXLINE); 
	writelines(input, numlines);

	return 0;
}
