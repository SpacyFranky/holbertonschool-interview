#include <stdlib.h>
#include "lists.h"

/**
* insert_node - inserts a number into a sorted singly linked list
* @head: linked list
* @number: the inserted number
* Return: the updated linkedlist.
*/

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *current, *temp;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	current = *head;
	if (new->n <= current->n)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	temp = *head;
	while (temp->next != NULL && new->n > temp->next->n)
		temp = temp->next;
	if (temp->next == NULL)
	{
		temp->next = new;
		return (new);
	}
	new->next = temp->next;
	temp->next = new;

	return (new);
}
