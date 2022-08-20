#include "monty.h"

/**
 * exec_file - searches line by line of the given file and tries to execute.
 * @file: file directory
 * Return: 0 on success
 */

int exec_file(FILE *file)
{
	unsigned int c = 1;
	char *line = NULL, *line_aux = NULL;
	stack_t *stack = NULL;

	global_data = malloc(sizeof(data_t));
	global_data->file = file;
	line = malloc(1024);
	if (line == NULL)
		return (2);
	for (line_aux = line, line = fgets(line, 1024, file); line; c++)
	{
		global_data->array = buff_to_array(line, " \t\n");
		if (global_data->array[0])
		{
			if (global_data->array[0][0] == 35)
			{
				free_array(global_data->array);
				global_data->array = NULL;
			}
			else if (get_func(global_data->array[0]) == NULL)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", c, global_data->array[0]);
				handle_error(1, file, stack);
			}
			else
				get_func(global_data->array[0])(&stack, c);
		}
		if (global_data->array)
			free_array(global_data->array);
		line = malloc(1024);
		if (line == NULL)
			handle_error(2, file, stack);
		line_aux = line;
		line = fgets(line, 1024, file);
	}
	free(line_aux);
	free(global_data);
	if (stack)
		free_stack(stack);
	return (0);
}
