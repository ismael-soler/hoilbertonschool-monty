#include "monty.h"

/**
 * exec_file - searches line by line of the given file and tries to execute.
 * @file: file directory
 */

void exec_file(FILE *file)
{
	int counter = 0;
	char *line = NULL, *line_aux = NULL, **line_array = NULL;

	line = malloc(1024);
	line = fgets(line, 1024, file);
	for (; line;)
	{
		line_array = buff_to_array(line, " \t");
		printf("%s\n", line_array[0]);
		free_array(line_array);
		counter++;
		line = malloc(1024);
		line_aux = line;
		line = fgets(line, 1024, file);
	}
	free(line_aux);
	printf("cantidad de lineas: %i\n", counter);
}
