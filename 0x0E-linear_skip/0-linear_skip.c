#include <stdio.h>
#include <stdlib.h>
#include "search.h"


/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: skip list
 * @value: value to search for
 * Return: a pointer on the first node where value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node, *prev, *tmp;

	node = list;
	prev = list;
	for (node = list->express; node; node = node->express)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
		if (value <= node->n)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
				prev->index, node->index);
			tmp = prev;
			while (tmp->next != node->next)
			{
				printf("Value checked at index [%lu] = [%d]\n", tmp->index, tmp->n);
				if (value == tmp->n)
					return (tmp);
				tmp = tmp->next;
			}
		}
		prev = prev->express;
	}
	if (prev->n < value)
	{
		tmp = prev;
		while (tmp->next)
			tmp = tmp->next;
		printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, tmp->index);
		while (prev)
		{
			printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
			if (value == prev->n)
				return (prev);
			prev = prev->next;
		}
	}
	return (node);
}
