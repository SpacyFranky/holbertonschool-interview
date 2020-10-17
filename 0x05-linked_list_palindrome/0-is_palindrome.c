#include "lists.h"
#include <stdlib.h>

/**
* is_palindrome - checks if a singly linked list is
* a palindrome.
* @head: singly linked list
* Return: 0 if it is not a palindrome, 1 if it is a palindrome
*/
int is_palindrome(listint_t **head)
{
	int *list;
	int i, j, length;
	listint_t *tmp;

	if (head == NULL)
		return (1);
	
	i = 0;
	tmp = *head;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	length = i + 1;

	list = malloc(sizeof(int) * length);
	if (list == NULL)
		return (0);

	i = 0;
	while (tmp != NULL)
	{
		list[i] = tmp->n;
		tmp = tmp->next;
	}
	j = length;
	for (i = 0; i <= j; i++)
	{
		if (list[i] != list[j])
			return (0);
		j--;
	}

	return (1);
}