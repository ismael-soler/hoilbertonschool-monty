#include "monty.h"

/**
 * handle_error - reads error code ad acts in consecuence.
 * @error_code: error code
 * @file: pointer to the working file so that it can be closed
 * @stack: pointer to the working stack so that it can be freed
 */

void handle_error(int error_code, FILE *file, stack_t *stack)
{
	if (file)
		fclose(file);
	if (stack)
		free_stack(stack);
	if (push_arg)
		free_array(push_arg);
	if (error_code == 1)
	{
		exit(EXIT_FAILURE);
	}
	else if (error_code == 2)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}
