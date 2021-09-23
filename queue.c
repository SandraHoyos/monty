#include "monty.h"

/**
 * _queue - FIFO
 * @stack: stack
 * @linenum: line number
 * Return: void
 */
void _queue(stack_t **stack, unsigned int linenum)
{
	stack_t *new = NULL;
	stack_t *old = NULL;

	if (stack == NULL)
		exit(EXIT_FAILURE);

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		free_stack(stack, linenum);
		exit(EXIT_FAILURE);
	}

	new->n = variables.holder;
	new->next = NULL;

	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
		return;
	}

	old = *stack;

	while (old->next != NULL)
		old = old->next;

	old->next = new;
	new->prev = old;
	variables.holder = (*stack)->n;
}
