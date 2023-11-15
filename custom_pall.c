#include "monty.h"
/**
 * _pall - prints out the stack datas
 * @head: head
 * @line_number: void
 * Return: nothing
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
