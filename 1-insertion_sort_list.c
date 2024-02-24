#include "sort.h"

/**
 * insertion_sort_list - sorts double integer linked-list elements
 * @list: pointer to the pointer that points at the first element
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list, *next = (*list)->next;

	if (current != NULL)
		insertion_sort(current, next, list);
}

/**
 * insertion_sort - applies insertion sort on a list of integer
 * @srtd: the sorted part of the list or first element
 * @unsrtd: the unsorted part or right-hand side of the list
 * @l: pointer to the pointer that points at the first element
 */
void insertion_sort(listint_t *srtd, listint_t *unsrtd, listint_t **l)
{
	listint_t *current = unsrtd, *prev = srtd;
	listint_t *next_prev = NULL, *nx_current = NULL;

	while (current)
	{
		nx_current = current->next;
		while (prev)
		{
			if (prev->n > current->n)
			{
				next_prev = prev->prev;
				_swap_nodes(prev, current, l);
				prev = next_prev;
			}
			else
				break;
		}
		if (nx_current != NULL)
			prev = nx_current->prev;
		current = nx_current;
	}
}

/**
 * _swap_nodes - swaps any two given double-linked list nodes
 * @big_n: the node with bigger integer
 * @small_n: the node with smaller integer
 * @l: pointer to the pointer that points at the first element
 */
void _swap_nodes(listint_t *big_n, listint_t *small_n, listint_t **l)
{
	listint_t *big_n_next = big_n->next, *small_n_prev = small_n->prev;

	small_n->prev = big_n->prev;
	if (big_n->prev != NULL)
		big_n->prev->next = small_n;
	if (small_n->next != NULL)
		small_n->next->prev = big_n;
	big_n->next = small_n->next;
	if (big_n_next == small_n)
	{
		small_n->next = big_n;
		big_n->prev = small_n;
	}
	else
	{
		small_n->next = big_n_next;
		big_n->prev = small_n_prev;
		small_n_prev->next = big_n;
	}
	if (*l == big_n)
		*l = small_n;
	print_list(*l);
}
