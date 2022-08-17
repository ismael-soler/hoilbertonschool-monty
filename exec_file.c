#include "monty.h"

/**
 * exec_file - searches line by line of the given file and tries to execute
 * @file: file directory
 */

void exec_file(FILE *file)
{
	int counter = 1;
	char *line = NULL, *line_aux = NULL;

	line = malloc(1024);
	line = fgets(line, 1024, file);
	for (; line;)
	{
		printf("%s\n", line);
		counter++;
		free(line);
		line = malloc(1024);
		line_aux = line;
		line = fgets(line, 1024, file);
	}
	free(line_aux);
	printf("cantidad de lineas: %i\n", counter);
}
