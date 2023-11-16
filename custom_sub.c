#include "monty.h"
/**
 *_sub- Func sustration
 *@head: Head
 *@line_number: Int line
 *Return: Null
 */
void _sub(stack_t **head, unsigned int line_number)
{
	stack_t *auxiliary;
	int u, nodes;

	auxiliary = *head;
	for (nodes = 0; auxiliary != NULL; nodes++)
		auxiliary = auxiliary->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(env.file);
		free(env.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	auxiliary = *head;
	u = auxiliary->next->n - auxiliary->n;
	auxiliary->next->n = u;
	*head = auxiliary->next;
	free(auxiliary);
}
