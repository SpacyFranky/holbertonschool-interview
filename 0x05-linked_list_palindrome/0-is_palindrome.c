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
	listint_t *h;
	listint_t *tmp;
	listint_t *current;
	listint_t *prev;
	listint_t *next;

	if (*head == NULL || head == NULL)
		return (0);
	if ((*head)->next == *head)
		return (0);

	h = *head;

	tmp = NULL;
	while (*head != NULL)
	{
		add_nodeint_end(&tmp, (*head)->n);
		*head = (*head)->next;
	}
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

	while (h != NULL)
	{
		if (h->n != tmp->n)
			return (0);
		h = h->next;
		tmp = tmp->next;
	}
	return (1);
}
