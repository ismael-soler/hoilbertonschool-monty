#include "monty.h"

/**
 * open_file - opens file
 * @file_name: file name
 * Return: 0 on success
 */

int open_file(char *file_name)
{
	FILE *file = NULL;

	file = fopen(file_name, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	exec_file(file);
	fclose(file);
	return (0);
}

