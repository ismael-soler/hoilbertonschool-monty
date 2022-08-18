#include "monty.h"

/**
 * main - reads a monty file
 * @av: argument value
 * @ac: argument count
 * Return: 0 on success
 */

int main(int ac, char *av[])
{
	(void) av;
	int error_code = 0;

	if (ac == 2)
	{
		error_code = check_argument(av[1]); /* funcion mandamos puntero a string*/
	}
	else
	{
		write(2, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	if (error_code != 0)
		handle_error(error_code);
	return (0);
}

/**
 * check_argument - checks arguments
 * @file_name: file name
 * Return: 0 on success
 */

int check_argument(char *file_name)
{
	int error_code = 0;
	struct stat st;

	if (stat(file_name, &st) == 0)
	{
		error_code = open_file(file_name);
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	return (error_code);
}
