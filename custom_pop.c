#include "monty.h"
/**
 * _pop - Func prints the top
 * @head: Head
 * @line_number: Int line
 * Return: Null
 */
void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *val;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(env.file);
		free(env.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	val = *head;
	*head = val->next;
	free(val);
}
