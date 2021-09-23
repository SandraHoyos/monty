#include "monty.h"

/**
 * pchar - function to print first char in the top of stack
 * @stack: stack
 * @linenum: line number
 * Return: void
 */
void pchar(stack_t **stack, unsigned int linenum)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", linenum);
		exit(EXIT_FAILURE);
	}
	if (isascii(variables.holder))
		printf("%c\n", variables.holder);
	else
	{
		printf("L%d: can't pchar, value out of range\n", linenum);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - prints string
 * @stack: stack
 * @linenum: unused
 * Return: void
 */
void pstr(stack_t **stack, __attribute__((unused)) unsigned int linenum)
{
	stack_t *str;

	if (stack == NULL || *stack == NULL || variables.holder == 0)
	{
		printf("\n");
		return;
	}

	str = *stack;

	while (str != NULL && str->n != 0 && isascii(str->n))
	{
		printf("%c", str->n);
		str = str->next;
	}
	printf("\n");

}

/**
 * rotl - rotates stack from top to bottom once
 * @stack: stack
 * @linenum: unused
 * Return: void
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int linenum)
{
	stack_t *new;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	new = *stack;

	while (new->next != NULL)
		new = new->next;

	new->next = *stack;
	(*stack)->prev = new;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	new->next->next = NULL;
}

/**
 * rotr - function to rotate bottom to the top once
 * @stack: stack
 * @linenum: unused
 * Return: void
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int linenum)
{
	stack_t *rev;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	rev = *stack;

	while (rev->next != NULL)
		rev = rev->next;
	rev->next = *stack;
	rev->prev->next = NULL;
	rev->prev = NULL;
	(*stack)->prev = rev;
	*stack = rev;
}
