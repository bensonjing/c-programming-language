/* memory.h: memory manegement for pointers 
 * */

#define ALLOCSIZE 10000 

/* alloc: allocate memory of [size] and return the pointer to the beginning 
 *
 * size: the size of the memory need to allocate 
 * 
 * return: 
 *   1. the pointer to the beginning of this memory block 
 *   2. 0 if not enough memory 
 * */
char *alloc(int size);

