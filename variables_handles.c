#include "main.h"

/**
 * _itoa_alt - Convert an integer to a string
 * @num:  integer to convert
 * @str:  buffer to store the resulting string
 * @size:  size of the buffer
 * Description: this is a custom implementation of itoa to convert
 * an integer to a string.
 * Return: void
 */
void _itoa_alt(int num, char *str, int size)
{
	int remainder, end;
	char temp;
	int i = 0, start = 0;
	int negative = 0;

	if (num == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return;
	}
	if (num < 0)
	{
		negative = 1;
		num = -num;
	}
	while (num != 0 && i < size - 1)
	{
		remainder = num % 10;
		str[i++] = remainder + '0';
		num = num / 10;
	}
	if (negative && i < size - 1)
	{
		str[i++] = '-';
	}
	str[i] = '\0';

    /* Reverse the string*/
	end = i - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

/**
 * _variables - function that subsitutes variables with their values
 * @argv: array of varibles of commands
 * Description: Replace the varibales with actual commands
 * Return: void
 */

void _variables(char **argv)
{
	int i;
	char process_string[10];
	char *env_value;

	for (i = 0; argv[i] != NULL; i++)
	{
		if (argv[i][0] == '$')
		{
			if (_strcmp(argv[i], "$$") == 0)
			{
				_itoa_alt(getpid(), process_string, sizeof(process_string));
				free(argv[i]);
				argv[i] = _strdup(process_string);
			}
			else if (_strcmp(argv[i], "$?") == 0)
			{
				env_value = _getenv("?");
				free(argv[i]);

				if (env_value != NULL)
				{
					argv[i] = _strdup(env_value);
				}
				else
				{
					argv[i] = _strdup("");
				}
			}
			else
			{

			}
		}
	}
}
