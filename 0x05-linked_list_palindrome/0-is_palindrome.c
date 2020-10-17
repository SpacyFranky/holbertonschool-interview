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

	if (head == NULL)
		return (0);
	
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

	while ((*head)->next != NULL)
	{
		if ((*head)->n != tmp->n)
			return (0);
		*head = (*head)->next;
		tmp = tmp->next;
	}
	return (1);
}