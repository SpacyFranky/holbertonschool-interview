#ifndef _MERGE_SORT_
#define _MERGE_SORT_

#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void copy_array(int *array, int first, int last, int *t);
void top_down_merge(int *array, int first, int mid, int last, int *t);
void top_down_split_merge(int *t, int first, int last, int *array);
void top_down_merge_sort(int *array, int *t, int size);
void merge_sort(int *array, size_t size);

#endif /* _MERGE_SORT_ */
