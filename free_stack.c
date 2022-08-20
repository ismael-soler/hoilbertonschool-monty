#include "monty.h"

/**
 * free_stack - frees all memory of a stack and it's content
 * @stack: stack
 */

void free_stack(stack_t *stack)
{

	if (stack == NULL)
	{
		free(stack);
		return;
	}
	if (stack)
	{
		for (stack = stack; stack; stack = stack->next)
		{
			if (stack)
				free(stack);
		}
	}
}
