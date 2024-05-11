#include <assert.h> 
#include <stdio.h>
#include <string.h>
#include "../include/memory.h" 
#include "../include/readlines.h"

void alloc_size_0(void);
void alloc_size_4(void); 
void alloc_size_10004(void);

void readline_hello(void);
void readline_empty_line(void);
void readlines_basic(void); 
void readlines_empty(void);

int main() 
{
	alloc_size_0(); 
	alloc_size_4();
	alloc_size_10004();
	readline_hello(); 
	readline_empty_line();
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

void readlines_basic(void)
{
	char *input[MAXLINE];
	assert(readlines(input, MAXLINE) == 5); 
	printf("[PASS] readlines_basic\n");
}

void readlines_empty(void)
{
	char *input[MAXLINE];
	assert(readlines(input, MAXLINE) == 0); 
	printf("[PASS] readlines_empty\n");
}
