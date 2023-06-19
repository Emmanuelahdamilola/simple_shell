#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: string one
 * @s2: string two
 * Return: 0, success
 *	-1 and 1 upon failure
 */

int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] < s2[i])
			return (-1);
		else if (s1[i] > s2[i])
			return (1);
		i++;
	}

	/*Check if both strings have reached the end simultaneously*/
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);

	/*One string is shorter than the other*/
	return ((s1[i] == '\0') ? -1 : 1);
}
