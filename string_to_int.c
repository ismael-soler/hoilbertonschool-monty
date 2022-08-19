#include "monty.h"

/**
 * string_to_int - converts content from a string
 * into a int, but only if the string contains numbers
 * @string: string
 * Return: 0 on succes, 1 if not
 */

int string_to_int(char *string)
{
	int i, flag, flag2 = 0;
	char number;
	int push_arg_value = 0;


	for (i = 0; string[i]; i++)
	{
		if (string[i] == '-')
		{
			i++;
			flag2 = 1;
		}
		for (flag = 0, number = 48; number < 58; number++)
		{
			if (number == string[i])
			{
				flag = 1;
			}
		}
		if (flag == 0)
		{
			free(global_data->array[1]);
			global_data->array[1] = NULL;
			return (push_arg_value);
		}
	}
	if (flag2 == 1)
		string++;
	push_arg_value = atoi(string);
	if (flag2 == 1)
		push_arg_value *= -1;
	return (push_arg_value);
}
