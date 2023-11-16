#include "monty.h"
/**
 * _pstr - Func prints the str from top
 * @head: Head
 * @line_number: Int line
 * Return: Null
*/
void _pstr(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
