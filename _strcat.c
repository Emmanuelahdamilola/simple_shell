#include "main.h"
/**
 * _strcat - function that concatenates two strings
 * @dest: destination after concatenating
 * @src: string to concatenate
 * Return: concatenated string
 */

char *_strcat(char *dest, const char *src)
{
	int dest_len = 0;
	int i = 0;
	
	if (src == NULL || dest == NULL)
		return (NULL);
	/* Find the length of the destination string */
	while (dest[dest_len] != '\0')
		dest_len++;

	/* Copy characters from src to dest, starting from the end of dest */
	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}

	/* Add the null terminator at the end */
	dest[dest_len + i] = '\0';

	return (dest);
}
