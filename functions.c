#include "monty.h"

int push_arg;

/**
 * _push - pushes an integerer into the stack.
 * @stack: stack
 * @line_number: line_number of the file that's running
 */

void _push(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	printf("entramos en push: %i\n", push_arg);
}

/**
 * _pall - pushes an integerer into the stack
 * @stack: stack
 * @line_number: line_number of the file that's running
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	printf("entramos en pall\n");
}
