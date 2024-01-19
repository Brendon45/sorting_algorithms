#include "sort.h"

/**
 * swap_nodes - A function that swaps two nodes in a doubly linked list.
 *
 * @list: A pointer to the doubly linked list
 * @node_a: The first node to swap
 * @node_b: The second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node_a, listint_t *node_b)
{
	listint_t *tmp_prev_a, *tmp_next_a;

	/* Store the previous and next nodes of the first node */
	tmp_prev_a = node_a->prev;
	tmp_next_a = node_a->next;

	/* Update the next pointer of the previous node of node_a or the list head */
	if (tmp_prev_a)
	tmp_prev_a->next = node_b;
	else
	*list = node_b;
	/* Update the previous and next pointers of node_b */
	node_b->prev = tmp_prev_a;
	node_b->next = node_a;
	/* Update the previous and next pointers of node_a */
	node_a->prev = node_b;
	node_a->next = node_b->next;

	/* Update the previous pointer of the next node of node_a */
	if (tmp_next_a)
	tmp_next_a->prev = node_a;
}
/**
 * cocktail_sort_list - A function that sorts a doubly linked list
 * using the Cocktail Shaker Sort algorithm.
 *
 * @list: A pointer to the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swap;
	listint_t *currnt;

	/* Check if the list is valid and has more than one element */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
	return;

	do {
	swap = 0;
	/* Iterate forward through the list, swapping nodes as needed */
	for (currnt = *list; currnt->next != NULL; currnt = currnt->next)
	{
		if (currnt->n > currnt->next->n)
		{
		swap_nodes(list, currnt, currnt->next);
		print_list(*list);
		swap = 1;
		}
	}
	/* If no swaps were made, the list is sorted, exit the loop */
	if (!swap)
		break;

	swap = 0;
	/* Iterate backward through the list, swapping nodes as needed */
	for (; currnt->prev != NULL; currnt = currnt->prev)
	{
		if (currnt->n < currnt->prev->n)
		{
		swap_nodes(list, currnt->prev, currnt);
		print_list(*list);
		swap = 1;
		}
	}
	} while (swap);
}
