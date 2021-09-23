#include "monty.h"

/**
 * free_stack - function to free stack
 * @stack: stack
 * @linenum: line number
 * Return: void
 */
void free_stack(stack_t **stack, unsigned int linenum)
{
	if (stack == NULL)
		return;
	while (*stack != NULL)
		pop(stack, linenum);
}
