#include "monty.h"


/**
 * _push - pushes an integerer into the stack.
 * @stack: stack
 * @line_number: line_number of the file that's running
 */

void _push(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *new_node = NULL;
	int push_arg_value = 0;

	if (push_arg)
		push_arg_value = string_to_int(push_arg);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free_stack(*stack);
		return;
	}

	new_node->prev = NULL;
	new_node->n = push_arg_value;
	if (*stack)
	{
		(*stack)->prev = new_node;
		new_node->next = *stack;
	}
	else
		new_node->next = NULL;
	*stack = new_node;
}

/**
 * _pall - pushes an integerer into the stack
 * @stack: stack
 * @line_number: line_number of the file that's running
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *stack_aux = *stack;

	if (stack_aux == NULL)
		return;
	for (; stack_aux; stack_aux = stack_aux->next)
		printf("%d\n", stack_aux->n);
}
