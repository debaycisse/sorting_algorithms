#include "sort.h"

/**
 * selection_sort - sorts an array using selection sort algorithm
 * @array: the array to be sorted
 * @size: the number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int temp = 0, s_val = 0, does_swap = 0, s_pos = 0;

	while (i < size)
	{
		does_swap = 0;
		s_val = array[i];
		s_pos = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < s_val)
			{
				s_val = array[j];
				s_pos = j;
			}
			j++;
		}
		if (s_val < array[i])
		{
			does_swap = 1;
			temp = array[i];
			array[i] = s_val;
			array[s_pos] = temp;
		}
		if (does_swap)
			print_array(array, size);
		i++;
	}
}
