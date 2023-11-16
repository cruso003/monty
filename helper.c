#include "monty.h"

/**
 * addNode - Func adds node
 * @head: Head
 * @n: new value
 * Return: Null
 */
void addNode(stack_t **head, int n)
{
	stack_t *elem, *aux;

	aux = *head;
	elem = malloc(sizeof(stack_t));
	if (elem == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	if (aux)
		aux->prev = elem;

	elem->n = n;
	elem->next = *head;
	elem->prev = NULL;
	*head = elem;
}

/**
 * addQueue - Func add node to the bottom
 * @head: Head
 * @n: new value
 * Return: Null
 */
void addQueue(stack_t **head, int n)
{
	stack_t *elem, *aux;

	aux = *head;
	elem = malloc(sizeof(stack_t));
	if (elem == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	elem->n = n;
	elem->next = NULL;

	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}

	if (!aux)
	{
		*head = elem;
		elem->prev = NULL;
	}
	else
	{
		aux->next = elem;
		elem->prev = aux;
	}
}
