#include "monty.h"
/**
  *_rotl- Func rotates stack
  *@head: Head
  *@line_number: Int line
  *Return: Null
 */
void _rotl(stack_t **head,  __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = *head, *auxiliary;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	auxiliary = (*head)->next;
	auxiliary->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = auxiliary;
}
