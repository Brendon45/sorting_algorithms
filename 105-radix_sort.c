#include "sort.h"
void apparent(void);

/**
 * getMax - A function to get the maximum element in an array
 *
 * @array: An array to find the maximum element
 * @size: Number of elements in @array
 * Return: The maximum element in the array
 */
int getMax(int *array, size_t size)
{
	int maximum = array[0];
	size_t a;

	/*It will iterate through the array to find the maximum element */
	for (a = 1; a < size; a++)
	{
	if (array[a] > maximum)
	{
		maximum = array[a];
	}
	}
	return (maximum);
}
/**
 * countSort -A function helper to perform counting sort based on a digit
 *
 * @array: An array to be sorted
 * @size: Number of elements in @array
 * @exp: The current digit's place value
 */
void countSort(int *array, size_t size, int exp)
{
	const int base = 10;
	int *result = malloc(size * sizeof(int));
	int *count = malloc(base * sizeof(int));
	size_t a;
	int b;

	/* Check for memory allocation failure */
	if (result == NULL || count == NULL)
	{
	/*Memory allocation failure*/
	free(result);
	free(count);
	return;
	}
	for (b = 0; b < base; b++)
	{
	count[b] = 0;
	}
	/* occurrences of digits at the current place value */
	for (a = 0; a < size; a++)
	{
		count[(array[a] / exp) % base]++;
	}
	/* Count to store the position of each digit in the output array */
	for (b = 1; b < base; b++)
	{
		count[b] += count[b - 1];
	}
	/* Output array in reverse order */
	for (a = size - 1; a < SIZE_MAX; a--)
	{
	result[count[(array[a] / exp) % base] - 1] = array[a];
	count[(array[a] / exp) % base]--;
	}
	for (a = 0; a < size; a++)
	{
	array[a] = result[a];
	}
	/* Free memory */
	free(result);
	free(count);
}
/**
 * radix_sort - A function that sorts an array of integers
 * in ascending order using Radix sort algorithm
 *
 * @array: An array to be sorted
 * @size: Number of elements in @array
 */
void radix_sort(int *array, size_t size)
{
	int maximum = getMax(array, size);
	size_t expr;

	for (expr = 1; maximum / expr > 0; expr *= 10)
	{
	countSort(array, size, expr);
	print_array(array, size);
	}
}
