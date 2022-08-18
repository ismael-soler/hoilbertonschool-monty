#include "monty.h"

/**
 * handle_error - reads error code ad acts in consecuence.
 * @error_code: error code
 */

void handle_error(int error_code)
{
	if (error_code == 1)
		exit(EXIT_FAILURE);
	else if (error_code == 2)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}
