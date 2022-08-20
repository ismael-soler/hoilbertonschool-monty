#include "monty.h"

/**
 * _mul - multiplies the top two elements of the stack
 * @stack: stack
 * @line_number: line of the working command
 */

void _mul(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *aux_stack = *stack;

	if (aux_stack == NULL || aux_stack->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		handle_error(1, global_data->file, *stack);
	}

	sum = aux_stack->n * aux_stack->next->n;
	aux_stack->next->n = sum;
	_pop(&(*stack), line_number);
}

/**
 * _mod - computes the rest of a
 * division between the top two elements of the stack
 * @stack: stack
 * @line_number: line of the working command
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *aux_stack = *stack;

	if (aux_stack == NULL || aux_stack->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		handle_error(1, global_data->file, *stack);
	}

	if (aux_stack->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		handle_error(1, global_data->file, *stack);
	}

	sum = aux_stack->next->n % aux_stack->n;
	aux_stack->next->n = sum;
	_pop(&(*stack), line_number);
}
