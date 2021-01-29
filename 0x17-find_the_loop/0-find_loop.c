#include "lists.h"



/**
* find_listint_loop - finds the loop in a linked list
* @head: start of the linked list
* Return: the address of the node where the loop starts, or NULL if there is no loop
*/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *fast, *slow;

	if(head == NULL || head->next == NULL)
		return (NULL);

	fast = head;
	slow = head;

	slow = slow->next;
	fast = fast->next->next;
	while(fast && fast->next)
	{
		if(slow == fast)
			break;
		slow = slow->next;
		fast = fast->next->next;
	}

	if(slow != fast)
		return (NULL);

	slow = head;
	while(slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return (slow);
}