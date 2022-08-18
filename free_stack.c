#include "monty.h"

/**
 * free_stack - frees all memory of a stack and it's content
 * @stack: stack
 */

void free_stack(stack_t *stack)
{
	stack_t *stack_aux;

	if (stack == NULL)
	{
		free(stack);
		return;
	}
	for (stack_aux = stack; stack_aux; stack_aux = stack_aux->next)
		free(stack_aux);
}
