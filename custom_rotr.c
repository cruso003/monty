#include "monty.h"
/**
  *_rotr- Func rotate stack
  *@head: Head
  *@line_number: Int num
  *Return: Null
 */
void _rotr(stack_t **head, __attribute__((unused)) unsigned int line_number)
{
	stack_t *dup;

	dup = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (dup->next)
	{
		dup = dup->next;
	}
	dup->next = *head;
	dup->prev->next = NULL;
	dup->prev = NULL;
	(*head)->prev = dup;
	(*head) = dup;
}
