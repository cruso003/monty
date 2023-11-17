#include "monty.h"
/**
 * _swap - Func adds the top two elem.
 * @head: Head
 * @line_number: Int line
 * Return: Null
 */
void _swap(stack_t **head, unsigned int line_number)
{
	stack_t *first, *second;
	int temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(env.file);
		free(env.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	first = *head;
	second = first->next;
	temp = first->n;

	first->n = second->n;
	second->n = temp;
}
