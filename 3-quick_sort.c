#include "sort.h"
/**
*swap - the positions of two elements into an array
*@array: array
*@i: array element
*@j: array element
*/
void swap(int *array, ssize_t i, ssize_t j)
{
	int tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}
/**
 *lomuto_partition - lomuto partition sorting scheme implementation
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: size array
 *Return: return the position of the last element sorted
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		swap(array, current, last);
		print_array(array, size);
	}
	return (current);
}
/**
 *quicksort - qucksort algorithm implementation
 *@array: array
 *@high: first array element
 *@low: last array element
 *@size: array size
 */
void quicksort(int *array, ssize_t high, ssize_t low, int size)
{
	ssize_t position = 0;


	if (high < low)
	{
		position = lomuto_partition(array, high, low, size);

		quicksort(array, high, position - 1, size);
		quicksort(array, position + 1, low, size);
	}
}
/**
 *quick_sort - prepare the terrain to quicksort algorithm
 *@array: array
 *@size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
