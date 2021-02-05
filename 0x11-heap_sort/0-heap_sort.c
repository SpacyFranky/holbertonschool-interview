#include "sort.h"

/**
* heapify - puts the array elements in heap order
* @array: array of ints
* @size: size of array
* @i: index of array
* @completeSize: complete size of array
* Return: Nothing
*/
void heapify(int *array, size_t size, int i, size_t completeSize)
{
	int max, left, right, tmp;

	max = i;
	left = 2 * i + 1;
	right = 2 * i + 2;

	if (left < (int)size && array[left] > array[max])
		max = left;

	if (right < (int)size && array[right] > array[max])
		max = right;

	if (max != i)
	{
		/*swap(&array[i], &array[max]);*/
		tmp = array[i];
		array[i] = array[max];
		array[max] = tmp;
		print_array(array, (int)completeSize);
		heapify(array, (int)size, max, (int)completeSize);
	}
}

/**
* heap_sort - sorts an array of integers in ascending
* order using the Heap sort algorithm
* @array: an array of integers
* @size: size of the array
* Return: Nothing
*/
void heap_sort(int *array, size_t size)
{
	int i, tmp;

	if (size == 0)
		return;

	for (i = (int)size / 2 - 1; i >= 0; i--)
		heapify(array, (int)size, i, size);

	for (i = (int)size - 1; i >= 0; i--)
	{
		/*swap(&array[0], &array[i]);*/
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, (int)size);
		heapify(array, i, 0, size);
	}
}
