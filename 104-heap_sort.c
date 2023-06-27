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
 * max_heap - Turns a binary tree into a binary heap.
 * @array: Array of integers representing a binary tree.
 * @size: Size of the array/tree.
 * @base: Index of the base row of the tree.
 * @root: Root node of the binary tree.
 */
void max_heap(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_num(array + root, array + large);
		print_array(array, size);
		max_heap(array, size, base, large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: Used sift-down heap sort
 * algorithm then Print the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heap(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_num(array, array + i);
		print_array(array, size);
		max_heap(array, size, i, 0);
	}
}
