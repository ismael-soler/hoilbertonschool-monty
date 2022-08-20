#include "monty.h"

/**
 * get_func - get function according to format
 * @command: format
 * Return: pointer to function or NULL
 */

void (*get_func(char *command))(stack_t **stack, unsigned int line_number)
{
	instruction_t array[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"nop", _nop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"mod", _mod},
		{"mul", _mul}
	};
	int i;

	for (i = 0; i < 11; i++)
		if (strcmp(array[i].opcode, command) == 0)
			return (array[i].f);
	return (NULL);
}
