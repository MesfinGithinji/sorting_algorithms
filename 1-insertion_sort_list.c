#include "sort.h"

/**
 * node_swap - Swap the  nodes in the linked list.
 * @head: Pointer to the head of the list.
 * @node1: Pointer to the first node to be swapped.
 * @node2: Pointer to the  second node to be swapped.
 */
void node_swap(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: Pointer to the head of the linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *passes, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (passes = (*list)->next; passes != NULL; passes = temp)
	{
		temp = passes->next;
		insert = passes->prev;
		while (insert != NULL && passes->n < insert->n)
		{
			node_swap(list, &insert, passes);
			print_list((const listint_t *)*list);
		}
	}
}
