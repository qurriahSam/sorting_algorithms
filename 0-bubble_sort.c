#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 * @array: pointer to int array
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int count = 0, temp;

	if (size < 2)
		return;
	for (j = 0; j < size; j++)
	{
		count = 0;
		for (i = 0; i < size - 1 - j; i++)
		{
			if (array[i + 1] < array[i])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				count++;
				print_array(array, size);
			}
		}
		if (count == 0)
			break;
	}
}
