#include "sort.h"
/**
 * quick_sort - quick_sort
 * @array: pointer to array
 * @size: size
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_2(array, size, array, size);
}
/**
 * quick_sort_2 - helping function
 * @array: array pointer
 * @size: size
 * @orig_array: pointer to the whole array
 * @orig_size: original size of whole array
 */
void quick_sort_2(int *array, size_t size, int *orig_array, size_t orig_size)
{
	int pivot, temp;
	size_t i, j;

	if (size < 2)
		return;
	pivot = array[size - 1];
	i = 0;
	for (j = 0; j < size; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(orig_array, orig_size);
			}
			i++;
		}
	}
	if (i != size - 1 && array[i] != pivot)
	{
		temp = array[i];
		array[i] = array[size - 1];
		array[size - 1] = temp;
		print_array(orig_array, orig_size);
	}
	quick_sort_2(array, i, orig_array, orig_size);
	quick_sort_2(array + i + 1, size - i - 1, orig_array, orig_size);
}
