#include <stdio.h>
/**
 * _getline - reads input from user
 * @lineptr: stores the address from stream
 * @n: number of bytes allocated
 * stream: reads from input
 * Return: returns input from user
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[BUFFER_SIZE];
	static size_t buffer_index;
	ssize_t bytes_read = 0, total_bytes = 0;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		*n = BUFFER_SIZE;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	while (1)
	{
		if (buffer_index >= bytes_read)
		{
			bytes_read = read(fileno(stream), buffer, BUFFER_SIZE);
			if (bytes_read <= 0)
				break;
			buffer_index = 0;
		}
		while (buffer_index < bytes_read)
		{
			if (total_bytes >= *n - 1)
				return (-1);
			if (buffer[buffer_index] == '\n')
			{
				(*lineptr)[total_bytes] = '\0';
				buffer_index++;
				return (total_bytes);
			}
			else
			{
				(*lineptr)[total_bytes] = buffer[buffer_index];
				buffer_index++;
				total_bytes++;
			}
		}
	}
	if (total_bytes > 0)
	{
		(*lineptr)[total_bytes] = '\0';
		return (total_bytes);
	}
	return (-1);
}
