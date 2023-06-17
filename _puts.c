#include "main.h"

/**
 * _puts - the function the prints character by character
 * @str: string to print
 *
 * Return: number of characters printed
 */

int _puts(const char *str)
{
	int count = 0;

	if (str == NULL)
		return (EOF);


	while (*str != '\0')
	{
		if (_putchar(*str) == EOF)
			return (EOF);

		count++;
		str++;
	}

	if (*str == EOF)
		return (EOF);

	count++;
	return (count);
}
