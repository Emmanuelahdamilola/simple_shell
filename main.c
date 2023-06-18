#include "main.h"
/**
 * read_execute_loop - Read input and execute commands in a loop
 * Return: void
 */
void read_execute_loop(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t num_chars;

	while (1)
	{
		_puts("$ ");
		num_chars = getline(&lineptr, &n, stdin);
		if (num_chars == EOF)
		{
			if (feof(stdin))
				perror("Terminating shell");
			else
				perror("Error");
			break;
		}
		parse_arguments(lineptr);
	}
	free(lineptr);
}

/**
 * free_argv - Free the allocated memory for the argument array.
 * @argv: The argument array.
 * @size: The size of the argument array.
 * Return: void
 */
void free_argv(char **argv, int size)
{
	int i;

	for (i = 0; i < size; i++)
		free(argv[i]);

	free(argv);
}

/**
 * main - Building shell to imitate bash.
 * @ac: Count of arguments.
 * @argv: Arguments.
 * Return: 0, success.
 */
int main(int ac, char **argv)
{
	(void)ac;
	(void)argv;

	read_execute_loop();

	return (0);
}
