#include "monty.h"
/**
 * _pall - Func prints stack info
 * @head: Head
 * @line_number: Int line
 * Return: Null
 */
void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *val;
	(void)line_number;

	val = *head;
	if (val == NULL)
	{
		/* Stack is empty, handle accordingly*/
		return;
	}

	/* Continue with the loop to print stack values*/
	while (val)
	{
		printf("%d\n", val->n);
		val = val->next;
	}
}
