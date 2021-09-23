#include "monty.h"

/**
 * push - adds to the beginning of the stack
 * @stack: top of stack
 * @linenum: line number for the passed token
 * Return: void
 */
void push(stack_t **stack, unsigned int linenum)
{
	stack_t *new;

	if (stack == NULL)
	{
		printf("L%d: unknown stack\n", linenum);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		free_stack(stack, linenum);
		exit(EXIT_FAILURE);
	}
	new->n = variables.holder;
	new->prev = NULL;
	new->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pall - function prints all of stack
 * @stack: top of stack
 * @linenum: line number
 * Return: void
 */
void pall(stack_t **stack, unsigned int linenum)
{
	stack_t *print;

	if (stack == NULL)
	{
		printf("L%d: invalid stack\n", linenum);
		exit(EXIT_FAILURE);
	}

	print = *stack;

	while (print != NULL)
	{
		printf("%d\n", print->n);
		print = print->next;
	}
}

/**
 * pop - function to pop the top of stack
 * @stack: top of stack
 * @linenum: line number
 * Return: void
 */
void pop(stack_t **stack, unsigned int linenum)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", linenum);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		variables.holder = (*stack)->n;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}

/**
 * pint - function prints the value at the top of the stack
 * @stack: stack
 * @linenum: line number
 * Return: void
 */
void pint(stack_t **stack, unsigned int linenum)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pint, stack empty\n", linenum);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}

/**
 * swap - swapping first two elements on top of stack
 * @stack: stack
 * @linenum: line number
 * Return: void
 */
void swap(stack_t **stack, unsigned int linenum)
{
	int temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", linenum);
		free_stack(stack, linenum);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
