#include <stdio.h>

void writelines(char *lines[], int numlines) 
{
	while (numlines-- > 0) {
		printf("%s\n", *lines++);
	}
}
