#ifndef MONTY_H
#define MONTY_H

#define MAX 100

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct MontyEnv - Environment for Monty interpreter
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag to change stack <-> queue
 * Description: Carries values through the program for Monty interpreter
 */
typedef struct MontyEnv
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} MontyEnv_t;

extern MontyEnv_t env;

void _push(stack_t **head, unsigned int line_number);
void _pall(stack_t **head, unsigned int line_number);
void _pint(stack_t **head, unsigned int line_number);
void _pop(stack_t **head, unsigned int line_number);
void _swap(stack_t **head, unsigned int line_number);
void _add(stack_t **head, unsigned int line_number);
void _nop(stack_t **head, unsigned int line_number);
void _sub(stack_t **head, unsigned int line_number);
void _div(stack_t **head, unsigned int line_number);
void _mul(stack_t **head, unsigned int line_number);
void _mod(stack_t **head, unsigned int line_number);
void _pchar(stack_t **head, unsigned int line_number);
void _pstr(stack_t **head, unsigned int line_number);
void _rotr(stack_t **head, __attribute__((unused)) unsigned int line_number);
void _rotl(stack_t **head, __attribute__((unused)) unsigned int line_number);
void _stack(stack_t **head, unsigned int line_number);
void _queue(stack_t **head, unsigned int line_number);
void addQueue(stack_t **head, int n);
int exec(char *content, stack_t **stack, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void addQueue(stack_t **head, int n);
void addNode(stack_t **head, int n);

#endif
