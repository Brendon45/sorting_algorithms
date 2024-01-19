#include "sort.h"
void drumroll(void);

/**
 * counting_sort - A function that sorts an array of integers
 * using Counting Sort algorithm
 *
 * @array: An array of integers to be sorted.
 * @size: Size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *duplicate, *count;
	unsigned int maximum, a, temp;

	/* Check if the array is valid for sorting */
	if (array == NULL || size < 2)
	return;

	/* Find the maximum value in the array */
	a = 0;
	maximum = 0;
	while (a < size)
	{
	if (array[a] > (int)maximum)
	maximum = array[a];
	a++;
	}
	maximum++;
	/* Allocate memory for the counting array and a copy of the original array */
	count = malloc(maximum * sizeof(int));
	if (count == NULL)
	return;
	duplicate = malloc(size * sizeof(int));
	if (duplicate == NULL)
	{
		free(count);
		return;
	}

	/* Copy the elements of the original array to a copy array */
	a = 0;
	while (a < size)
	{
		duplicate[a] = array[a];
		a++;
	}
	/* Initialize counting array elements to zero */
	a = 0;
	while (a < maximum)
	{
	count[a] = 0;
	a++;
	}
	/* Count the occurrences of each element in the original array */
	a = 0;
	while (a < size)
	{
	count[array[a]]++;
	a++;
	}
	/* Modify the counting array to store the cumulative count of elements */
	a = 1;
	while (a < maximum)
	{
		count[a] += count[a - 1];
		a++;
	}

	/* Print the counting array after counting occurrences */
	print_array(count, maximum);

	/* Use the counting array to sort the elements in the original array */
	a = 0;
	while (a < size)
	{
		temp = duplicate[a];
		array[count[temp] - 1] = temp;
		count[temp]--;
		a++;
	}

	/* Free the allocated memory for counting and copy arrays */
	free(count);
	free(duplicate);
}
