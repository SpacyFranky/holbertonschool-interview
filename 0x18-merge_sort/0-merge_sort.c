#include <stdlib.h>
#include "sort.h"


/**
* copy_array - copies an array to another empty array
* @array: first array
* @first: first index of array
* @last: last index of array
* @t: second array
*/
void copy_array(int *array, int first, int last, int *t)
{
	int k;

	for (k = first; k < last; k++)
		t[k] = array[k];
}


/**
* top_down_merge - putting elements in the newly created array
* @array: original array
* @first: first index of array
* @mid: middle index of array
* @last: last index of array
* @t: sorted array
*/
void top_down_merge(int *array, int first, int mid, int last, int *t)
{
	int i = first;
	int j = mid;
	int k;

	for (k = first; k < last; k++)
	{
		if (i < mid && (j >= last || array[i] <= array[j]))
		{
			t[k] = array[i];
			i = i + 1;
		}
		else
		{
			t[k] = array[j];
			j = j + 1;
		}
	}
}


/**
* top_down_split_merge - splitting array in halfs
* @t: sorted array
* @first: first index of array
* @last: last index of array
* @array: original array
*/
void top_down_split_merge(int *t, int first, int last, int *array)
{
	int mid;

	if (last - first <= 1)
		return;
	mid = (last + first) / 2;

	top_down_split_merge(array, first, mid, t);

	top_down_split_merge(array, mid, last, t);

	top_down_merge(t, first, mid, last, array);
}

/**
* top_down_merge_sort - using top down method
* @array: original array
* @t: sorted array
* @size: size of original array
*/
void top_down_merge_sort(int *array, int *t, int size)
{
	copy_array(array, 0, size, t);
	top_down_split_merge(t, 0, size, array);
}


/**
* merge_sort - sorts an array of integers in ascending order using
* the Merge Sort algorithm
* @array: array of integers
* @size: size of array
*/
void merge_sort(int *array, size_t size)
{
	int *t;

	if (array == NULL)
		return;

	t = malloc(sizeof(int) * size);

	top_down_merge_sort(array, t, size);
}
