#include <assert.h>
#include "../src/memory.h" 

extern char *alloc(int);

int main()
{
	char *first, *second; 
	first = second = alloc(4); 
	second = alloc(4);
	assert(second-first != 4);

	return 0;
}
