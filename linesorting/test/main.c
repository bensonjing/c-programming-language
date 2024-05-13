#include <assert.h> 
#include <stdio.h>
#include <string.h>
#include "../include/memory.h" 
#include "../include/readlines.h"
#include "../include/writelines.h"

void alloc_size_0(void);
void alloc_size_4(void); 
void alloc_size_10004(void);

void readline_hello(void);
void readline_empty_line(void);
void writelines_hello_world(void);
void readlines_basic(void); 
void readlines_empty(void);

void swap_test(void);

int main() 
{
	// alloc_size_0(); 
	// alloc_size_4();
	// alloc_size_10004();
	// readline_hello(); 
	// readline_empty_line();
	writelines_hello_world();
	readlines_basic(); 
	readlines_empty();

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

void readline_hello(void)
{
	char input[MAXLEN]; 
	assert(readline(input, MAXLEN) == 6); 
	assert(strcmp(input, "hello"));
	printf("[PASS] readline_hello\n");
}

void readline_empty_line(void)
{
	printf("testing readline_empty_line\n");
	char input[MAXLEN]; 
	assert(readline(input, MAXLEN) == 1); 
	assert(strcmp(input, ""));
	printf("[PASS] readline_empty_line\n");
}

void writelines_hello_world(void) 
{
	char *first = "hello"; 
	char *second = "world"; 
	char *input[2] = {first, second};
	printf("writelines_hello_world: \n"); 
	writelines(input, 2);
}

void readlines_basic(void)
{
	char *lines[MAXLINE];
	int i;
	int numlines = readlines(lines, MAXLINE); 
	printf("numlines: %d\n", numlines);
	for (int i = 0; i < numlines; ++i) printf("line %d: %s\n", i, *lines[i]);
	printf("[PASS] readlines_basic\n");
}

void readlines_empty(void)
{
	char *input[MAXLINE];
	assert(readlines(input, MAXLINE) == 0); 
	printf("[PASS] readlines_empty\n");
}
