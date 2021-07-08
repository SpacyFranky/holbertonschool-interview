#include <stdlib.h>
#include "sort.h"


/**
* get_max - finds the largest number in the array
* @array: array of integers
* @size: size of the array
* Return: largest number in the array
*/
int get_max(int *array, int size)
{

	int i;
	int max = array[0];

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	return (max);
}

/**
* counting_sort - uses counting sort to sort the elements
* in the basis of significant places
* @array: array of integers
* @size: size of the array
* @pos: position in the array
*/
void counting_sort(int *array, int size, int pos)
{

	int i;
	int max = (array[0] / pos) % 10;
	int *result, *count;

	result = malloc((sizeof(int) * size) + 1);
	if (result == NULL)
		return;

	count = malloc((sizeof(int) * max) + 1);
	if (count == NULL)
		return;

	for (i = 1; i < size; i++)
	{
		if (((array[i] / pos) % 10) > max)
			max = array[i];
	}

	for (i = 0; i < max; ++i)
		count[i] = 0;


	for (i = 0; i < size; i++)
		count[(array[i] / pos) % 10]++;


	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];


	for (i = size - 1; i >= 0; i--)
	{
		result[count[(array[i] / pos) % 10] - 1] = array[i];
		count[(array[i] / pos) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = result[i];
	free(result);
}


/**
* radix_sort -  sorts an array of integers in ascending order
* using the Radix sort algorithm
* @array: array of integers
* @size: size of array
*/
void radix_sort(int *array, size_t size)
{

	int pos, max;

	max = get_max(array, size);
	for (pos = 1; max / pos > 0; pos *= 10)
	{
		counting_sort(array, size, pos);
		print_array(array, size);
	}

}
