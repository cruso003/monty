#include "monty.h"

/**
 * handle_error - Helper function to handle errors
 * @line_number: Int line
 * @head: Head
 */
void handle_error(unsigned int line_number, stack_t **head)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	fclose(env.file);
	free(env.content);
	if (*head != NULL)
	{
		free_stack(*head);
	}

	exit(EXIT_FAILURE);
}

/**
 * _push - Func add node
 * @head: Head
 * @line_number: Int line
 */
void _push(stack_t **head, unsigned int line_number)
{
	size_t j;
	int y;

	if (!env.arg || !*env.arg)
	{
		if (*head == NULL)
		{
			return;
		}

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
