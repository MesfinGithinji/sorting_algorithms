#include "sort.h"

/**
 * swap_num - Swap two integers.
 * @x: First num to swap.
 * @y: Second num to swap.
 */
void swap_num(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: The array of integers.
 * @size: The size of the array.
 *
 * Description: Print the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min_val;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_val = array + i;
		for (j = i + 1; j < size; j++)
			min_val = (array[j] < *min_val) ? (array + j) : min_val;

		if ((array + i) != min_val)
		{
			swap_num(array + i, min_val);
			print_array(array, size);
		}
	}
}
