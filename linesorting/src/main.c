#include <stdio.h>
#include "../include/memory.h"

#define MAXLEN 1000

/* readline: read a line from input into input[] and return its length 
 *
 * input: a pointer to an array of char storing the content of the line 
 * maxlen: the maximum length of the line
 * */
int readline(char input[], int maxlen);

/* readlines: read multiples line from input and return number of lines 
 *
 * input[]: an array of char pointers that point to each line 
 * maxlines: the maximum number of lines 
 * */
// int readlines(char *input[], int maxlines); 

int main()
{
	printf("linsorting\n");
	printf("%p\n", alloc(4));

	return 0;
}

int readline(char input[], int maxlen)
{
	int index, current; 

	for (index=0; index<maxlen && (current = getchar()) != EOF && current != '\n';\
		++index) input[index] = current; 
	if (current == '\n') {
		input[index++] = current; 
		input[index] = '\0';
		return index; 
	}
	return 0;
}
