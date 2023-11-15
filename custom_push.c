#include "monty.h"

/**
 * handle_error - Helper function to handle errors
 * @line_number: Line number
 * @head: Stack head
 */
void handle_error(unsigned int line_number, stack_t **head)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	fclose(env.file);
	free(env.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
}

/**
 * _push - Add node to the stack
 * @head: Stack head
 * @line_number: Line number
 */
void _push(stack_t **head, unsigned int line_number)
{
	size_t j;
	int y;

	if (!env.arg || !*env.arg)
	{
		handle_error(line_number, head);
	}

	for (j = (env.arg[0] == '-'); env.arg[j]; ++j)
	{
		if (!isdigit(env.arg[j]))
		{
			handle_error(line_number, head);
		}
	}

	y = atoi(env.arg);

	if (env.lifi == 0)
	{
		addNode(head, y);
	}
	else
	{
		addQueue(head, y);
	}
}

