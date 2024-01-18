#include "sort.h"

/**
* shell_sort - A function that sorts an array of integers in ascending
* order using Shell sort algorithm with Knuth sequence
* @array: Array to be sorted
* @size: The number of elements in the array
*/

void shell_sort(int *array, size_t size)
{
	int tmp;
	size_t gape = 1, a, b;

	/* Check if the array is valid for sorting */
	if (array == NULL || size < 2)
	return;

	/* Calculate the initial gap using the Knuth sequence */
	while (gape < size / 3)
	gape = gape * 3 + 1;

	/* Iterate through the gaps and perform insertion sort within each gap */
	while (gape > 0)
	{
	for (a = gape; a < size; a++)
	{
		tmp = array[a];
		b = a;
	/* Perform insertion sort within the current gap */
	while (b >= gape && array[b - gape] > tmp)
	{
		array[b] = array[b - gape];
		b -= gape;
	}
	array[b] = tmp;
	}
	/* Print the array after each iteration for visualization */
	print_array(array, size);
	/* Update the gap using the decreasing Knuth sequence */
	gape = (gape - 1) / 3;
	}
}
