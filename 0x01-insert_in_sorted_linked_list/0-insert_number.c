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

	current = *head;
	if (new->n < current->n)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	temp = *head;
	while (temp != NULL && new->n > temp->next->n)
		temp = temp->next;
	new->next = temp->next;
	temp->next = new;

	return (new);
}
