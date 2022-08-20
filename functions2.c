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

/**
 * _swap - swaps the top two elements of the stack
 * @stack: stack
 * @line_number: line of the working command
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	int aux_n_value = 0;
	stack_t *aux_stack = *stack;

	if (aux_stack == NULL || aux_stack->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		handle_error(1, global_data->file, *stack);
	}

	aux_n_value = aux_stack->next->n;
	aux_stack->next->n = aux_stack->n;
	aux_stack->n = aux_n_value;
}

/**
 * _add - add the top two elements of the stack
 * @stack: stack
 * @line_number: line of the working command
 */

void _add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *aux_stack = *stack;

	if (aux_stack == NULL || aux_stack->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		handle_error(1, global_data->file, *stack);
	}

	sum = aux_stack->n + aux_stack->next->n;
	aux_stack->next->n = sum;
	_pop(&(*stack), line_number);
}

/**
 * _sub - sub the top two elements of the stack
 * @stack: stack
 * @line_number: line of the working command
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *aux_stack = *stack;

	if (aux_stack == NULL || aux_stack->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		handle_error(1, global_data->file, *stack);
	}

	sum = aux_stack->n - aux_stack->next->n;
	aux_stack->next->n = sum;
	_pop(&(*stack), line_number);
}

/**
 * _div - div the top two elements of the stack
 * @stack: stack
 * @line_number: line of the working command
 */

void _div(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%u; division by zero\n", line_number);
		handle_error(1, global_data->file, *stack);
	}

	sum = aux_stack->next->n / aux_stack->n;
	aux_stack->next->n = sum;
	_pop(&(*stack), line_number);
}
