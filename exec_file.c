#include "monty.h"

char **push_arg = NULL;

/**
 * exec_file - searches line by line of the given file and tries to execute
 * @file: file directory
 * Return: 0 on success
 */

int exec_file(FILE *file)
{
	unsigned int counter = 1;
	char *line = NULL, *line_aux = NULL, **array = NULL;
	char *aux;
	stack_t *stack = NULL;

	line = malloc(1024);
	if (line == NULL)
		return (2);
	for (line_aux = line, line = fgets(line, 1024, file); line;)
	{
		array = buff_to_array(line, " \t\n");
		if (array[0])
		{
			if (get_func(array[0]) == NULL)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", counter, array[0]);
				free_array(array);
				return (1);
			}
			push_arg = array;
			get_func(array[0])(&stack, counter);
			aux = push_arg[1];
			if (aux == NULL)
				handle_error(1, file, stack);
			if (stack == NULL)
				handle_error(2, file, stack);
			free_array(array);
		}
		counter++;
		line = malloc(1024);
		if (line == NULL)
			handle_error(2, file, stack);
		line_aux = line;
		line = fgets(line, 1024, file);
	}
	free(line_aux);
	free_stack(stack);
	return (0);
}
