#include "lists.h"
#include <stdlib.h>

/**
* check_cycle - checks if a singly linked list
*               has a cycle in it.
* @list: singly linked list
* Return: 0 if there is no cycle, 1 if there is a cycle.
*/
int check_cycle(listint_t *list)
{
	listint_t *slow;
	listint_t *fast;

	if (list == NULL)
		return (0);
	slow = list;
	fast = list;
	while (list != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			return (1);
		}
		list = list->next;
	}
	return (0);
}