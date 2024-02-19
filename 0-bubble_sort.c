#include "sort.h"

/**
 * bubble_sort - sorts out an array in an ascending order
 * @array: the array whose elements are to be sorted
 * @size: the number of the elements in the given array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, a, b;

	if (size >= 2)
	{
		for (i = 1; i < size; ++i)
		{
			a = 0;
			b = 1;
			for (j = 1; j < size; ++j)
			{
				if (array[a] > array[b])
					_swap(array, a, b, size);
				a++;
				b++;
			}
		}
	}
}


/**
 * _swap - swaps two given elements of an array
 * @a: the index of the first element
 * @b: the index of the second element
 * @size: the number of elements in the array
 */
void _swap(int *array, int a, int b, size_t size)
{
	int temp = 0;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
	print_array((const int *)array, size);
}
