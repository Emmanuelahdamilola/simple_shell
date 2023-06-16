#include "shell.h"

/**
 * main - prints a prompt
 * @argc: argument count
 * @argv: strings
 *
 * Return: 0 (success)
 */

int main(int argc, char **argv)
{
	char *getline_ptr;
	size_t n = 0;
	ssize_t num_char;

	(void)argc;
	(void)argv;

	while (1)
	{
		_puts("$ ");
		num_char = getline(&getline_ptr, &n, stdin);
		if (num_char == -1)
		{
			_puts("<<<Can't be found>>>");
			return (-1);
		}
		_puts(getline_ptr);
		_puts("\n");
		free(getline_ptr);
	}
	return (0);
}
