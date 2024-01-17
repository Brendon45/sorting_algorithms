#include "sort.h"

/**
 * insertion_sort_list - A function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 *
 * @list: A pointer to the pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *currnt = (*list)->next;
	listint_t *temp;

	/* Check if the list is empty or contains only one element */
	if (list == NULL || *list == NULL)
	{
		return;
	}
	/* Iterate through the list starting from the second node */
	while (currnt != NULL)
	{
	temp = currnt;
	/* Inner loop to swap the nodes and insert into the sorted part */
	while (temp->prev != NULL && temp->n < temp->prev->n)
	{
	/* Adjust the next pointer of the previous node */
	temp->prev->next = temp->next;
	if (temp->next != NULL)
	{
		temp->next->prev = temp->prev;
	}

	temp->next = temp->prev;
	temp->prev = temp->prev->prev;

	if (temp->prev != NULL)
		temp->prev->next = temp;
	if (temp->prev == NULL)
	{
		*list = temp;
	}
	/*Adjust the previous pointer of the next node*/
	temp->next->prev = temp;
	print_list(*list);
	}
	currnt = currnt->next;
	}
}
