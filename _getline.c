#include "main.h"

/**
 * get_line - function that reads a line from stdin
 *
 * Return: pointer that points to a str with line content
 */
char *get_line(void)
{
	static char line[BUFFER_SIZE];
	static ssize_t line_length;
	ssize_t read_len, index = 0;
	char *res;

	if (line_length == 0)
	{
		printf("($) ");
		fflush(stdout);
		read_len = read(STDIN_FILENO, line, BUFFER_SIZE);
		if (read_len == -1)
		{
			perror("error while reading the line from stdin");
			exit(EXIT_FAILURE);
		}
		else if (read_len == 0)
		{
			exit(EXIT_SUCCESS);
		}
		line_length = read_len;
	}

	res = malloc(line_length + 1);
	if (res == NULL)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	for (; index < line_length; index++)
	{
		res[index] = line[index];
	}
	res[line_length] = '\0';

	line_length = 0;

	return (res);
}
