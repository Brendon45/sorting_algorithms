#include "sort.h"

/**
 * bubble_sort - Sorting an array of integers in ascending order Bubble sort
 * @array: Array used to sort
 * @size: Elements in an array
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t a, b;
	int swap;
	int temp;

	if (size < 2)
	return;
	/*Iterate through the array*/
	for (a = 0; a < size - 1; a++)
	{
	swap = 0;
	/* Compare and swap adjacent elements if they are in the wrong order */
	for (b = 0; b < size - a - 1; b++)
	{
	if (array[b] > array[b + 1])
	{
	/* Swap elements */
	temp = array[b];
	array[b] = array[b + 1];
	array[b + 1] = temp;

	swap = 1;
	/* Print the array after each swap for visualization */
	print_array(array, size);
	}
	}
	/*if swap is equal to 0, then break the code*/
	if (swap == 0)
	break;
	}
}
