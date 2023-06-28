#include "main.h"

/**
 * read_buffer - function reads data
 * @stream: where the data is read
 * @buffer: where data is been read into
 * @bytes_read: bytes read
 * Return: 0 upon succes, 1 upon failure
 */
int read_buffer(FILE *stream, char *buffer, ssize_t *bytes_read)
{
	*bytes_read = read(fileno(stream), buffer, BUFFER_SIZE);
	return (*bytes_read > 0);
}

/**
 * null_terminate_line - appends a null character
 * @line_length: appends a null character at this position
 * @line: buffer
 * @line_size: size line
 * Return: 1 if the null termination was successful,
 *	or 0 if there was a memory allocation failure
 */
int null_terminate_line(char **line, size_t line_size, size_t line_length)
{
	if (line_size <= line_length + 1)
	{
		size_t new_size = line_size + BUFFER_SIZE;
		char *new_line = realloc(*line, new_size);

		if (new_line == NULL)
			return (0);
	*line = new_line;
	line_size = new_size;
	}
	(*line)[line_length] = '\0';
	return (1);
}

/**
 * expand_line_buffer - function checks if the line buffer (line)
 * needs to be expanded to accommodate additional characters
 * @line: buffer
 * @line_size: line size
 * @line_length: length line
 * Return: 1 if the line buffer expansion was successful,
 *	or 0 if there was a memory allocation failure
 */
int expand_line_buffer(char **line, size_t *line_size, size_t line_length)
{
	if (*line_size <= line_length)
	{
		size_t new_size = *line_size + BUFFER_SIZE;
		char *new_line = realloc(*line, new_size);

		if (new_line == NULL)
		{
			return (0);
		}
		*line = new_line;
		*line_size = new_size;
	}
	return (1);
}

/**
 * custom_getline - gets input from user
 * @n: bytes gotten
 * @stream: stdin
 * @lineptr: pointer to input
 * Return: input
 */
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[BUFFER_SIZE];
	static ssize_t buffer_pos, bytes_read;
	char *line = *lineptr;
	size_t line_size = *n, line_length = 0;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	buffer_pos = 0;
	bytes_read = 0;
	while (1)
	{
		if (buffer_pos >= bytes_read && !read_buffer(stream, buffer, &bytes_read))
			return (-1);
		if (buffer[buffer_pos] == '\n')
		{
			buffer_pos++;
			if (!null_terminate_line(&line, line_size, line_length))
			{
				return (-1);
			}
			*lineptr = line;
			*n = line_size;
			return (line_length);
		}
		if (!expand_line_buffer(&line, &line_size, line_length))
			return (-1);
		line[line_length] = buffer[buffer_pos];
		buffer_pos++;
		line_length++;
	}
}

