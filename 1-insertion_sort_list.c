#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list, next* = NULL, *prev = NULL;
	listint_t *sorted = NULL, *unsorted = NULL, *temp = NULL;

	next = current->next;
	prev = current->prev;

	if (sorted == NULL)
	{
		if (current->n > next->n)
			_swap_list(list);
		else
		{
			next->next = NULL;
			sorted = current;
		}
		next = next->next;
	}
	else
		insertion_sort(sorted, unsorted);
}


void insertion_sort(listint_t *sorted, listint_t *unsorted)
{
	while (unsorted)
	{

	}
}


void _swap_list(listint_t **list)
{
	listint_t *current = *list, *next = *list->next, *temp = NULL;

	next->prev = NULL;
	temp = next->next;
	next->next = current;
	current->prev = next;
	current->next = temp;
	*list = next;
	print_list(*list);
}
