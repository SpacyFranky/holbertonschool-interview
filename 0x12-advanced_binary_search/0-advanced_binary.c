#include "search_algos.h"
#include <stdio.h>

/**
* print_array - prints array
* @array: array of integers
* @start: start of array
* @end: end of array
*/
void print_array(int *array, size_t start, size_t end)
{
	size_t i = start;

	printf("Searching in array: ");
	while (i <= end)
	{
		printf("%d", array[i]);
		if (i != end)
			printf(", ");
		i++;
	}
	printf("\n");
}

/**
* binary_search - searches for a value in a sorted array
* of integers
* @array: sorted array
* @start: start of array
* @end: end of array
* @value: searched value
* Return: index where value is located, or -1 if it's not present
*/
int binary_search(int *array, size_t start, size_t end, int value)
{
	size_t mid;

	print_array(array, start, end);

	mid = (start + end) / 2;

	if (mid >= end)
		return (-1);

	else if (value == array[start])
		return (start);

	else if (value <= array[mid - 1])
		return (binary_search(array, start, mid, value));

	else if (value >= array[mid + 1])
		return (binary_search(array, mid + 1, end, value));

	return (-1);
}


/**
* advanced_binary - calls the binary search function
* of integers
* @array: sorted array
* @size: size of array
* @value: searched value
* Return: index where value is located, or -1 if it's not present
*/
int advanced_binary(int *array, size_t size, int value)
{
	if (size == 0)
		return (-1);
	return (binary_search(array, 0, size - 1, value));
}
