#include "main.h"

/**
 * _strncmp - compares two strings in n bytes
 * @str1: first string
 * @str2: second string
 * @n: bytes
 *
 * Return: 0, success
 */

int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;
	
	if (str1 == NULL || str2 == NULL)
		return (0);
	for (i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
		{
			if (str1[i] < str2[i])
				return (-1);
			else
				return (1);
		}
	}
	if (i == n || str1[i] == '\0')
		return (0);
	return (0);
}

