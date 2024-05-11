/* readlines.h
 * */

#define MAXLEN 1000
#define MAXLINE 500

/* readline: read a line from input into input[] and return its length 
 *
 * input: an array of char storing the content of the line 
 * maxlen: the maximum length of the line
 *
 * return: the length of the line
 * */
int readline(char input[], int maxlen);

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
