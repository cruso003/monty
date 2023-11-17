#include "monty.h"

/**
 * _add - Adds the top two elements of the stack
 * @head: head
 * @line_number: Int Line
 */
void _add(stack_t **head, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;
	int sum;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(env.file);
		free(env.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	first = *head;
	second = first->next;
	sum = first->n + second->n;

	second->n = sum;
	*head = second;
	free(first);
}
