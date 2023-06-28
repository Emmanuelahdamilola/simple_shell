#include "main.h"
/**
 * custom_getline - reads input from users
 * @lineptr: pointer to the input
 * @n: bytes read
 * @stream: input
 * Return: input
 */
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[BUFFER_SIZE];
	static ssize_t buffer_pos, bytes_read;
	char *line = *lineptr, *new_line;
	size_t line_size = *n, line_length = 0, new_size;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	while (1)
	{
		if (buffer_pos >= bytes_read)
		{
			bytes_read = read(fileno(stream), buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (bytes_read <= 0)
				return (-1);
		}
		if (buffer[buffer_pos] == '\n')
		{
			buffer_pos++;
			if (line_size <= line_length + 1)
			{
				new_size = line_size + BUFFER_SIZE;
				new_line = realloc(line, new_size);
				if (new_line == NULL)
					return (-1);
				line = new_line;
				line_size = new_size;
			}
			line[line_length] = '\0';
			*lineptr = line;
			*n = line_size;
			return (line_length);
		}
		if (line_size <= line_length)
		{
			new_size = line_size + BUFFER_SIZE;
			new_line = realloc(line, new_size);
			if (new_line == NULL)
				return (-1);
			line = new_line;
			line_size = new_size;
		}
		line[line_length] = buffer[buffer_pos];
		buffer_pos++;
		line_length++;
	}
}
