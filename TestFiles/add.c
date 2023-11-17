#include "monty.h"
/**
 * _add - Func adds the top two elements
 * @head: Head
 * @line_number: Int line
 * Return: Null
 */
void _add(stack_t **head, unsigned int line_number)
{
    stack_t *val;
    int size = 0, auxiliary;

    val = *head;
    while (val)
    {
        val = val->next;
        size++;
    }
    if (size < 2)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        fclose(env.file);
        free(env.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    val = *head;
    auxiliary = val->n + val->next->n;
    val->next->n = auxiliary;
    *head = val->next;
    free(val);
}
