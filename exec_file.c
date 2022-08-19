#include "monty.h"

/**
 * exec_file - searches line by line of the given file and tries to execute
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
	for (line_aux = line, line = fgets(line, 1024, file); line;)
	{
		global_data->array = buff_to_array(line, " \t\n");
		if (global_data->array[0])
		{
			if (get_func(global_data->array[0]) == NULL)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", c, global_data->array[0]);
				free_array(global_data->array);
				return (1);
			}
			get_func(global_data->array[0])(&stack, c);
			if (global_data->array[1] == NULL)
				handle_error(1, file, stack);
			if (stack == NULL)
				handle_error(2, file, stack);
			free_array(global_data->array);
		}
		c++;
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
