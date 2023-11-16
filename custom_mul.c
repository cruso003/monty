#include "monty.h"
/**
 * _mul - Func multiply the top two elem.
 * @head: Head
 * @line_number: Int line
 * Return: Null
 */
void _mul(stack_t **head, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(env.file);
		free(env.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	auxiliary = h->next->n * h->n;
	h->next->n = auxiliary;
	*head = h->next;
	free(h);
}
