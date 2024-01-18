#include "sort.h"

/**
 * selection_sort - A function sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: Array to be sorted
 * @size: The size of the array
*/
void selection_sort(int *array, size_t size)
{
	/*Initialisation*/
	size_t a, b, minimum;
	int temp;

	/* Iterate through the array */
	for (a = 0; a < size - 1; a++)
	{
	minimum = a; /* Assume the current index is the minimum */

	 /* Find the index of the minimum element in the unsorted part of the array */
	for (b = a + 1; b < size; b++)
	{
		if (array[b] < array[minimum])
			minimum = b;
	}
	/* If the minimum element is not at the current index, swap them */
	if (minimum != a)
	{
		/* Swap the elements at indices i and min */
		temp = array[a];
		array[a] = array[minimum];
		array[minimum] = temp;
		/* Print the array after each swap for visualization */
		print_array(array, size);
	}
	}
}
