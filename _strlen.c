#include "main.h"

/**
 * _strlen - function to get the length of a string
 * @s: string to get its length
 * Return: length of string
 */

size_t _strlen(const char *s)
{
	int count = 0;

	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}
