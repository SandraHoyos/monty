#include "monty.h"

**
 * add - function to add top two elements on stack
 * @stack: stack
 * @linenum: line number
 * Return: void
 */

 void add(stack_t **stack, unsigned int linenum)
{
	int adding;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", linenum);
		free_stack(stack, linenum);
		exit(EXIT_FAILURE);
	}

	adding = variables.holder;
	pop(stack, linenum);
	adding += variables.holder;
	pop(stack, linenum);
	variables.holder = adding;
	push(stack, linenum);
}
