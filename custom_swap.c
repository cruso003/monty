#include "monty.h"
/**
 * _swap - adds the top two elements of the stack.
 * @head: head
 * @line_number: line number
 * Return: nothing
 */
void _swap(stack_t **head, unsigned int line_number)
{
	stack_t *val;
	int length = 0, auxiliary;

	val = *head;
	while (val)
	{
		val = val->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(env.file);
		free(env.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	val = *head;
	auxiliary = val->n;
	val->n = val->next->n;
	val->next->n = auxiliary;
}
