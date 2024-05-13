/* quicksort: recursively sort the array 
 * 
 * explanation
 * ==========
 * base case:      left > right, return 
 * recursive case: left < right 
 * recursive step: partition the array based on pivot and quicksort each sub-array
 *
 * parameters
 * =========
 * array: the array to be sorted 
 * left:  the position of the first element 
 * right: the position of the last element
 * */
void quicksort(char *array[], int left, int right);
