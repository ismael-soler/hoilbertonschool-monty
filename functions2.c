#include "monty.h"

/**
 * _pop - deleted the item at the top of the stack
 * @stack: stack
 * @line_number: line of the working command
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *aux1, *aux2;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		handle_error(1, global_data->file, *stack);
	}

	aux1 = *stack;

	*stack = aux1->next;
	aux2 = aux1->next;
	free(aux1);
	if (aux2)
		aux2->prev = NULL;
}
