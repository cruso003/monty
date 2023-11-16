#include "monty.h"
/**
 * free_stack - Func frees list
 * @head: Head
 */
void free_stack(stack_t *head)
{
	stack_t *auxiliary;

	auxiliary = head;
	while (head)
	{
		auxiliary = head->next;
		free(head);
		head = auxiliary;
	}
}
