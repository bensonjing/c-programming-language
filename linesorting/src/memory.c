#include "../include/memory.h"

static char allocbuf[ALLOCSIZE]; 
static char *allocp = allocbuf; 

char *alloc(int size) 
{
	if (allocbuf + ALLOCSIZE - allocp >= size) {
		allocp += size; 
		return allocp - size;
	} else 
		return 0;
}
