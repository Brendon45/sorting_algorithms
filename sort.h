#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdint.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*Printing functions for Data Structures*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/*Prototypes for Sorting algorithms & Big O*/

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap(int *i, int *j);
void quick_sort_recursive(int *array, ssize_t low, ssize_t high, size_t size);
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *node_a, listint_t *node_b);
void counting_sort(int *array, size_t size);
int getMax(int *array, size_t size);
void countSort(int *array, size_t size, int exp);
void radix_sort(int *array, size_t size);
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir);
void bitonic_merge(int *array, size_t low, size_t count, int dir);
void bitonic_sort(int *array, size_t size);

#endif /*Sorting algorithms*/
