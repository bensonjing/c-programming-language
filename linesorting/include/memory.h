/* memory.h: memory manegement for pointers 
 * */

#define ALLOCSIZE 10000 

/* alloc: allocate memory of [size] and return the pointer to the beginning 
 *
 * size: the size of the memory need to allocate 
 * 
 * return: the pointer to the beginning of this memory block 
 * */
char *alloc(int size);

