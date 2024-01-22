#include "sort.h"

/**
 * bitonic_sort_recursive - A function that recursively sorts a bitonic
 * sequence in the given order
 * @array: An array to be sorted
 * @low: Index of the subarray to be sorted
 * @count: The umber of elements in the subarray
 * @dir: The sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir)
{
	size_t b = count / 2;

	/* If there is more than one element in the subarray */
	if (count > 1)
	{
	printf("Merging [%lu/%lu] (UP):\n", low, low + count - 1);
	print_array(array + low, count);
	/* Recursively sort the first half in ascending order */
	bitonic_sort_recursive(array, low, b, 1);

	printf("Merging [%lu/%lu] (DOWN):\n", low + b, low + count - 1);
	print_array(array + low + b, count - b);
	/* Recursively sort the second half in descending order */
	bitonic_sort_recursive(array, low + b, b, 0);
	/* Merge the two halves in the specified order */
	bitonic_merge(array, low, count, dir);
	}
}
/**
 * bitonic_merge - A function that merge two subarrays of the given array
 * @array: An array to be sorted
 * @low: Index of the first subarray
 * @count: Number of elements in each subarray
 * @dir: A sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
	/* If there is more than one element in each subarray */
	if (count > 1)
	{
		size_t b = count / 2;
		size_t a;

	/* Iterate over the elements of the first subarray */
	for (a = low; a < low + b; ++a)
	{
	/* Compare and swap elements based on the specified order */
	if ((array[a] > array[a + b]) == dir)
	{
		int temp = array[a];

		array[a] = array[a + b];
		array[a + b] = temp;
		}
	}
	/* Recursively merge the two halves */
	bitonic_merge(array, low, b, dir);
	bitonic_merge(array, low + b, b, dir);
	}
}
/**
 * bitonic_sort - A function that sorts an array of integers
 * in ascending order using Bitonic sort algorithm.
 * @array: An array to be sorted
 * @size: A number of elements in the array (must be a power of 2)
 */
void bitonic_sort(int *array, size_t size)
{
	/* Check for valid input */
	if (array && size > 1 && ((size & (size - 1)) == 0))
	{
	/* Start the recursive sorting process */
	bitonic_sort_recursive(array, 0, size, 1);
	}
}
