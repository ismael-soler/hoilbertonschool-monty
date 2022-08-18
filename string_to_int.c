#include "monty.h"

int push_arg = 0;

/**
 * string_to_int - converts content from a string
 * into a int, but only if the string contains numbers
 * @string: string
 * Return: 0 on succes, 1 if not
 */

int string_to_int(char *string)
{
	int i, flag;
	char number;

	for (i = 0; string[i]; i++)
	{
		for (flag = 0, number = 48; number < 58; number++)
		{
			if (number == string[i])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			return (1);
	}
	push_arg = atoi(string);
	return (0);
}
