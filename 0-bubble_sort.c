#include "sort.h"
/**
 *bubble_sort - Function that sorts an array of ints
 *
 *@array: array of ints
 *@size: size of array
 *
 */
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i, s;

	if (!array || !size)
		return;

	i = 0;
	while (i < size)
	{
		for (s = 0; s < size - 1; s++)
		{
			if (array[s] > array[s + 1])
			{
				tmp = array[s];
				array[s] = array[s + 1];
				array[s + 1] = tmp;
				print_array(array, size);
			}
		}
		i++;
	}
}
