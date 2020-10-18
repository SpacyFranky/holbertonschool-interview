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
	listint_t *tmp;
	listint_t *current;
	listint_t *prev;
	listint_t *next;
	int length, i, j;

	if (head == NULL)
		return (0);

	/* Length of the list */
	length = 0;
	while ((*head) != NULL)
	{
		length++;
		*head = (*head)->next;
	}

	tmp = *head;
	current = tmp;
	prev = NULL;
	next = NULL;

	/* Reversing the list */
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	tmp = prev;

	i = 1;
	if (length % 2 == 0)
		j = length / 2;
	else
		j = length / 2 + 1;
	while (i <= j)
	{
		if ((*head)->n != tmp->n)
			return (0);
		*head = (*head)->next;
		tmp = tmp->next;
		i++;
	}
	return (1);
}