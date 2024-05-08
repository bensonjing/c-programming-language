#include <stdio.h> 

#define BUFSIZE 100 

static char buffer[BUFSIZE]; 
static int bufferPointer = 0; 

int getChar(void)
{
	return (bufferPointer > 0) ? buffer[--bufferPointer] : getchar(); 
}

void ungetChar(int c) 
{
	if (bufferPointer >= BUFSIZE)
		printf("error: too many character in buffer");
	else 
		buffer[bufferPointer++] = c;
}
