#include "monty.h"
/**
 * _push - add node to the stack
 * @head: stack head
 * @line_number: line number
 * Return: no return
 */
void _push(stack_t **head, unsigned int line_number)
{
	int n, j = 0, flag = 0;

	if (env.arg)
	{
		if (env.arg[0] == '-')
			j++;
		for (; env.arg[j] != '\0'; j++)
		{
			if (env.arg[j] > 57 || env.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(env.file);
			free(env.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(env.file);
		free(env.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(env.arg);
	if (env.lifi == 0)
		addNode(head, n);
	else
		addQueue(head, n);
}

