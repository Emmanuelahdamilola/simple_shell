#include "main.h"

/**
 * read_buff - function reads data
 * @stream: where the data is read
 * @buffer: where data is been read into
 * @bytes_read: bytes read
 * Return: 0 upon succes, 1 upon failure
 */
int read_buff(FILE *stream, char *buffer, ssize_t *bytes_read)
{
	*bytes_read = read(fileno(stream), buffer, BUFFER_SIZE);
	return (*bytes_read > 0);
}

/**
 * _null_terminateline - function that appends a null character
 * @line_length: appends a null character at this position
 * @line: buffer
 * @line_size: size line
 * Return: 1 if the null termination was successful,
 *	or 0 if there was a memory allocation failure
 */
int null_terminateline(char **line, size_t line_size, size_t line_length)
{
	size_t newSize;
	char *newline;

	if (line_size <= line_length + 1)
	{
		newSize = line_size + BUFFER_SIZE;
		newline = realloc(*line, newSize);

		if (newline == NULL)
			return (0);
	*line = newline;
	line_size = newSize;
	}
	(*line)[line_length] = '\0';
	return (1);
}

/**
 * expand_line_buff - function that checks if the line buffer (line)
 * needs to be expanded to accommodate additional characters
 * @line: buffer
 * @line_size: line size
 * @line_length: length line
 * Return: 1 if the line buffer expansion was successful,
 *	or 0 if there was a memory allocation failure
 */
int expand_line_buffer(char **line, size_t *line_size, size_t line_length)
{
	size_t newSize;
	char *newline;

	if (*line_size <= line_length)
	{
		newSize = *line_size + BUFFER_SIZE;
		newline = realloc(*line, newSize);

		if (newline == NULL)
		{
			return (0);
		}
		*line = newline;
		*line_size = newSize;
	}
	return (1);
}

/**
 * custom_getline - function that gets input from user
 * @n: bytes gotten
 * @stream: stdin
 * @lineptr: pointer to input
 * Return: input
 */
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	static char buff[BUFFER_SIZE];
	static ssize_t buff_pos, bytes_read;
	char *line = *lineptr;
	size_t line_size = *n, line_length = 0;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	buff_pos = 0;
	bytes_read = 0;
	while (1)
	{
		if (buff_pos >= bytes_read && !read_buff(stream, buff, &bytes_read))
			return (-1);
		if (buff[buff_pos] == '\n')
		{
			buff_pos++;
			if (!null_terminateline(&line, line_size, line_length))
			{
				return (-1);
			}
			*lineptr = line;
			*n = line_size;
			return (line_length);
		}
		if (!expand_line_buffer(&line, &line_size, line_length))
			return (-1);
		line[line_length] = buff[buff_pos];
		buff_pos++;
		line_length++;
	}
}

