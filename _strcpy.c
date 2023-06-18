#include "main.h"

/**
 * _strcpy - function that copies a string
 * @dest: pointer to the place the string will be copied to
 * @src: pointer to where the string will be copied from
 * Return: string copied
 */

char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
