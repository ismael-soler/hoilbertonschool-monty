#include "monty.h"

/**
 * exec_file - searches line by line of the given file and tries to execute.
 * @file: file directory
 */

void exec_file(FILE *file)
{
	int counter = 1;
	char *line = NULL, *line_aux = NULL, **array = NULL;
	/*void (*command_function)(stack_t **, unsigned int);*/

	line = malloc(1024);
	line_aux = line;
	line = fgets(line, 1024, file);
	for (; line;)
	{
		array = buff_to_array(line, " \t");
		if (get_func(array[0]) == NULL)
		{
			fprintf(stderr, "L%i: unknown instruction %s\n", counter, array[0]);
			free_array(array);
			exit(EXIT_FAILURE);
		}
		free_array(array);
		counter++;
		line = malloc(1024);
		line_aux = line;
		line = fgets(line, 1024, file);
	}
	free(line_aux);
	printf("cantidad de lineas: %i\n", counter);
}
