#include "main.h"
/**
 * _getline - reads input from user
 * @lineptr: pointer to the address of the input
 * @n: number of bytes read
 * @s: input from user
 *
 * Return: character read
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *s)
{
	static char buf[BUFFER];
	static ssize_t i; /* i = index */
	ssize_t bytr = 0, total_bytes = 0; /** bytr = bytes_read*/

	if (lineptr == NULL || n == NULL || s == NULL)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		*n = BUFFER;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	while (i < bytr || (bytr = read(fileno(s), buf, BUFFER)) > 0)
	{
		i = i % bytr;
		if ((size_t)total_bytes >= *n - 1)
			return (-1);
		if (buf[i] == '\n')
		{
			(*lineptr)[total_bytes] = '\0';
			i++;
			return (total_bytes);
		}
		else
			(*lineptr)[total_bytes++] = buf[i++];
	}
	if (total_bytes > 0)
	{
		(*lineptr)[total_bytes] = '\0';
		return (total_bytes);
	}
	if (bytr == 0)
		return (-1);
	return (-1);
}
