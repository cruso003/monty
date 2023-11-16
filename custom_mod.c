#include "monty.h"
/**
 * _mod - Func computes the division
 * @head: head
 * @line_number: line number
 * Return: Null
 */
void _mod(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int size, auxiliary;

	size = 0;

	h = *head;
	while (h)
	{
		h = h->next;
		size++;
	}
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(env.file);
		free(env.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(env.file);
		free(env.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	auxiliary = h->next->n % h->n;
	h->next->n = auxiliary;
	*head = h->next;
	free(h);
}
