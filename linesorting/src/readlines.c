#include <stdio.h> 
#include "../include/readlines.h"
#include "../include/memory.h"

/* stringcopy: copy the string from source to destination
 * */ 
static void strcopy(char *destination, char *source); 

/* readline: read a line from input into input[] and return its length 
 *
 * input: an array of char storing the content of the line 
 * maxlen: the maximum length of the line
 *
 * return: the length of the line
 * */
static int readline(char input[], int maxlen);

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
			current[len-1] = '\0';
			strcopy(line, current);
			input[index++] = line; 	
		}
	}

	return index;
}

void strcopy(char *destination, char *source)
{
	while ((*destination++ = *source++)); 
}
