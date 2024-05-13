/* linesort: sort input lines based on length and output 
 * 
 * the program consist three steps 
 * 1. read lines from the command line (see readlines.h)
 * 2. sort input lines based on their length using quick sort (see quicksort.h)
 * 3. write sorted lines to the screen (see writelines.h) 
 * */ 

#include "../include/readlines.h"
#include "../include/writelines.h"
#include "../include/quicksort.h"

int main(void)
{
	char *input[MAXLINE];
	int numlines = readlines(input, MAXLINE); 
	quicksort(input, 0, numlines-1); 
	writelines(input, numlines);

	return 0;
}
