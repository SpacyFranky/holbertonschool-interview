#ifndef _HEAP_SORT_
#define _HEAP_SORT_

#include <stdlib.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size, int i, size_t completeSize);

#endif /* _HEAP_SORT_  */
