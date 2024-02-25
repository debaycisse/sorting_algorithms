#include "sort.h"

/**
 */
void quick_sort(int *array, size_t size)
{
	size_t h = 0, *current_index = NULL;
	size_t first_index = 0;
	int *pvt = NULL;

	current_index = &first_index;
	pvt = pivot(array, size, pvt);
	while (h < size)
	{
		lomuto(array, size, current_index, pvt);
		h++;
	}
}

/**
 */
void lomuto(int *array, size_t size, size_t *cur, int *pvt)
{
	size_t i = *cur;

	while (i < size)
	{
		if (array[i] <= *pvt)
		{
			_swap2(array, (int)(*cur), (int)i, size);
			(*cur)++;
			pvt = pivot(array, size, pvt);
		}
		i++;
	}
}

/**
 */
int *pivot(int *array, size_t size, int *prev_pvt)
{
	int i, *new_pivot = NULL;

	if (prev_pvt == NULL)
	{
		new_pivot = &(array[size - 1]);
		return (new_pivot);
	}
	i = 1;
	while ((*prev_pvt) != array[size - i])
		i++;
	new_pivot = &(array[size - (++i)]);
	return (new_pivot);
}

/**
 */
void _swap2(int *array, int a, int b, size_t size)
{
	int temp = 0;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
	print_array((const int *)array, size);
}
