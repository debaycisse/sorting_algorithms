#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list, *next = NULL;
	listint_t *sorted = NULL, *unsorted = NULL;

	next = current->next;

	if (current->n > next->n)
	{
		_swap_list(list);
		insertion_sort(current, next->next, *list);
	}
	else
	{
		sorted = next;
		unsorted = next->next;
		

	}
	insertion_sort(sorted, unsorted, *list);
}


void insertion_sort(listint_t *srt, listint_t *unsorted, listint_t *l)
{
	listint_t *current = unsorted, *prev = srt;

	while (current)
	{
		while (prev)
		{
			if (prev->n > current->n)
				_swap_nodes(prev, current, l);
			prev = prev->prev;
		}
		current = current->next;
	}
}


void _swap_nodes(listint_t *big_n, listint_t *small_n, listint_t *l)
{
	listint_t *grt_next = big_n->next;
	
	small_n->prev = big_n->prev;
	if (big_n->prev != NULL)
		big_n->prev->next = small_n;
	if (small_n->next != NULL)
		small_n->next->prev = big_n;
	big_n->next = small_n->next;
	if (grt_next == small_n)
		small_n->next = big_n;
	else
		small_n->next = grt_next;
	if (l == big_n)
		l = small_n;
	print_list(l);
}


void _swap_list(listint_t **list)
{
	listint_t *current = *list, *next = (*list)->next, *temp = NULL;

	next->prev = NULL;
	temp = next->next;
	next->next = current;
	current->prev = next;
	current->next = temp;
	*list = next;
	print_list(*list);
}
