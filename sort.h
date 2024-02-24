#ifndef SORT_H
#define SORT_H

#include <stddef.h>


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

/*  print_array.c */
void print_array(const int *array, size_t size);

/* print_list.c  */
void print_list(const listint_t *list);

/* bubble_sort.c */
void bubble_sort(int *array, size_t size);
void _swap(int *array, int a, int b, size_t size);

/* 1-insertion_sort_list.c */
void insertion_sort_list(listint_t **list);
void insertion_sort(listint_t *srtd, listint_t *unsrtd, listint_t **l);
void _swap_nodes(listint_t *big_n, listint_t *small_n, listint_t **l);

/* 2-selection_sort.c */
void selection_sort(int *array, size_t size);

#endif
