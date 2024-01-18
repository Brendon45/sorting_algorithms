#include "sort.h"

/**
* swap - A function that swaps two integers in an array
* @i: A pointer to the first integer
* @j: A pointer to the second integer
*/

void swap(int *i, int *j)
{
	int tmp = *i;
	*i = *j;
	*j = tmp;
}

/**
* lomuto_partition - An Lomuto partition scheme for QuickSort
*
* @array: The array to be partitioned
* @low: A starting index of the partition
* @high: An ending index of the partition
* @size: The size of the array
* Return: Index of the pivot element when partition is made
*/
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t b;
	int pivot = array[high];
	ssize_t a = low - 1;

	for (b = low; b <= high - 1; b++)
	{
	if (array[b] <= pivot)
	{
		a++;
	if (a != b)
	{
		/* Swap the elements at indices i and j */
		swap(&array[a], &array[b]);
		print_array(array, size);
	}
		}
	}
	if ((a + 1) != high)
	{
	/* Swap the pivot element with the element at index i + 1 */
	swap(&array[a + 1], &array[high]);
	print_array(array, size);
	}
	return (a + 1);
}

/**
* quick_sort_recursive - Sorting an array by recursion
* @array: The array to be sorted
* @low: A starting index of the partition
* @high: An ending index of the partition
* @size: The size of the array
*/
void quick_sort_recursive(int *array, ssize_t low, ssize_t high, size_t size)
{
	if (low < high)
	{
	/* Get the index of the pivot element after partitioning */
	size_t pivot = lomuto_partition(array, low, high, size);

	/* Recursively sort the sub-arrays on both sides of the pivot */
	quick_sort_recursive(array, low, pivot - 1, size);
	quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
* quick_sort - A function that sorts an array of integers in ascending
* order using QuickSort algorithm
* @array: The array to be sorted
* @size: The size of the array
*/

void quick_sort(int *array, size_t size)
{
/* Check if the array is not NULL and has more than one element */
if (array && size > 1)
quick_sort_recursive(array, 0, size - 1, size);
}
