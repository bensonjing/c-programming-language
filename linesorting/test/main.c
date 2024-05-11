#include <assert.h> 
#include <stdio.h>
#include "../include/memory.h" 

void alloc_size_0(void);
void alloc_size_4(void); 
void alloc_size_10004(void);

int main() 
{
	alloc_size_0(); 
	alloc_size_4();
	alloc_size_10004();

	return 0;
}

void alloc_size_0(void)
{
	char *first = alloc(0); 
	char *second = alloc(0); 
	assert(second-first == 0);
	printf("[PASS] alloc size 0\n");
}

void alloc_size_4(void)
{
	char *first = alloc(4); 
	char *second = alloc(4); 
	assert(second-first == 4);
	printf("[PASS] alloc size 4\n");
}

void alloc_size_10004(void)
{
	char *first = alloc(10004); 
	assert(first == 0);
	printf("[PASS] alloc size 10004\n");
}
