/* readlines.h
 * */

#define MAXLEN 1000
#define MAXLINE 500

/* readlines: read multiples line from input and return number of lines 
 *
 * input: an array of pointers that point to beginning of each line 
 * maxlines: the maximum number of lines 
 *
 * return: 
 *   1. the number of lines or
 *   2. -1 if input exceed maxlines or not enough memory to allocate
 * */
int readlines(char *input[], int maxlines); 
