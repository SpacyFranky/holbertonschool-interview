#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
* is_palindrome - checks if a singly linked list is
* a palindrome.
* @head: singly linked list
* Return: 0 if it is not a palindrome, 1 if it is a palindrome
*/
int is_palindrome(listint_t **head)
{
	int list[sizeof(int) * 64];
	int i, length;
	listint_t *tmp;

	/* Getting linked list's length */
	tmp = *head;
	length = 0;
	while (tmp != NULL)
	{
		length++;
		tmp = tmp->next;
	}

	/* Setting the array */
	tmp = *head;
	i = 0;
	while (tmp != NULL)
	{
		list[i] = tmp->n;
		i++;
		tmp = tmp->next;
	}

	/* Checking list is palindrome or not */
	for (i = 0; i <= length / 2; i++)
	{
		if (list[i] != list[length - 1 - i])
			return (0);
	}

	return (1);
}
