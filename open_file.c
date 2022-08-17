#include "monty.h"

/**
 * open_file - opens file
 * @file_name: file name
 * Return: 0 on success
 */

int open_file(char *file_name)
{
	FILE *file = NULL;
	int error_code = 0;

	file = fopen(file_name, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		error_code = 1;
		return (error_code);
	}
	error_code = exec_file(file)
	fclose(file);
	return (error_code);
}

