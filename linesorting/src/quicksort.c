#include "../include/quicksort.h" 

/* partition: split the array into two sub-array based on the pivot 
 *
 * explanation
 * ===========
 * 1. select the middle element in the array as the pivot 
 * 2. all elements smaller than pivot goto left of the pivot 
 * 3. all elements larger than pivot goto right of the pivot 
 *
 * parameters
 * =========
 * array: the array to be sorted 
 * left:  the position of the first element 
 * right: the position of the last element
 *
 * return: the position of the pivot
 * */
static int partition(char *array[], int left, int right); 

/* swap: swap the position of source and destination in the array
 * */
static void swap(char *array[], int source, int destination);

/* strcompare: compare the length of two string 
 *
 * return: -1 if first < second 
 *          0 if first = second 
 *          1 if first > second
 * */
static int strcompare(char *first, char *second);

void quicksort(char *array[], int left, int right) 
{
	if (left < right) {
		int pivot = partition(array, left, right); 
		quicksort(array, left, pivot-1); 
		quicksort(array, left, pivot-1); 
	}
}

int partition(char *array[], int left, int right)
{
	int pivot = (left + right) / 2; 
	swap(array, right, pivot);

	while (left <= right) {
	}
}

void swap(char *array[], int source, int destination)
{
	char *temp; 

	temp = array[source]; 
	array[source] = array[destination]; 
	array[destination] = temp;
}

int strcompare(char *first, char *second)
{
	while (*first && *second) {
		first++; 
		second++;
	}
	if (*first == '\0' && *second != '\0') return -1; 
	else if (*second == '\0' && *first != '\0') return 1; 
	return 0;
}
