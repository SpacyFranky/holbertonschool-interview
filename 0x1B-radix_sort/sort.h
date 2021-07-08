#ifndef _RADIX_
#define _RADIX_

#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);
int get_max(int *array, int size);
void counting_sort(int *array, int size, int pos);


#endif /* _RADIX_ */
