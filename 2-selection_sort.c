#include "sort.h"
/**
 * selection_sort - selection sort
 * @array: array to be sorted
 * @size: its size
 */
void selection_sort(int *array, size_t size)
{
	int min, temp, flag = 0;
	size_t i, j, minIndex;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		minIndex = i;
		flag = 0;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				minIndex = j;
				flag = 1;
			}
		}
		if (flag == 1)
		{
			temp = array[i];
			array[i] = min;
			array[minIndex] = temp;
			print_array(array, size);
		}
	}
}
