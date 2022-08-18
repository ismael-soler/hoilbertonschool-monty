#include "monty.h"

/**
 * exec_file - searches line by line of the given file and tries to execute
 * @file: file directory
 * Return: 0 on success
 */

int exec_file(FILE *file)
{
	int counter = 1;
	char *line = NULL, *line_aux = NULL, **array = NULL;
	stack_t *stack = NULL;

	line = malloc(1024);
	if (line == NULL)
		return (2);
	line_aux = line;
	line = fgets(line, 1024, file);
	for (; line;)
	{
		array = buff_to_array(line, " \t\n");
		if (get_func(array[0]) == NULL)
		{
			fprintf(stderr, "L%i: unknown instruction %s\n", counter, array[0]);
			free_array(array);
			return (1);
		}
		if (array[1])
		{
			string_to_int(array[1]);
		}
		get_func(array[0])(&stack, counter);
		free_array(array);
		counter++;
		line = malloc(1024);
		if (line == NULL)
			return (2);
		line_aux = line;
		line = fgets(line, 1024, file);
	}
	free(line_aux);
	printf("cantidad de lineas: %i\n", counter);
	return (0);
}
