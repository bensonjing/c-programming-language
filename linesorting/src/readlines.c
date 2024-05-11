#include <stdio.h> 
#include <string.h>
#include "../include/readlines.h"
#include "../include/memory.h"

int readline(char input[], int maxlen)
{
	int index, current; 

	for (index=0; index<maxlen && (current = getchar()) != EOF && current != '\n'; ++index) input[index] = current; 
	if (current == '\n') {
		input[index++] = current; 
	}
	input[index] = '\0';
	return index; 
}

int readlines(char *input[], int maxlines)
{
	char current[MAXLEN];
	char *line; 
	int index = 0;
	int len; 

	while ((len = readline(current, MAXLEN))) {
		if (index >= maxlines || !(line = alloc(len))) 
			return -1; 
		else {
			strcpy(current, line); 
			input[index++] = line; 	
		}
	}

	return index;
}
