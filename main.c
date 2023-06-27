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
	int interactive_mode;
	int lineptr_freed = 0;

	interactive_mode = isatty(STDIN_FILENO);
	while (1)
	{
		if (interactive_mode)
			_puts("($) ");
		num_chars = getline(&lineptr, &n, stdin);
		if (num_chars <= 0)
		{
			if (num_chars == -1)
			{
				if (feof(stdin))
					/*perror*/
					_puts("Error reading input\n");
			}
			else if (num_chars == 0)
			{
				/*perror*/
				_puts("Terminating shell\n");
			}
			if (!lineptr_freed)
			{
				free(lineptr);
				lineptr_freed = 1;
			}
			break;
		}
		parse_arguments(lineptr);
		if (interactive_mode)
			_putchar('\n');
		if (!interactive_mode)
			break;
	}
	if (!lineptr_freed)
		free(lineptr);

	free(lineptr);
}

/**
 * main - Building shell to imitate bash.
 * @argc: Count of arguments.
 * @argv: Arguments.
 * Return: 0, success.
 */
int main(int argc, char **argv)
{
	char *command;

	(void)argc;
	(void)argv;

	command = argv[0];
	if (_strcmp(command, "exit") == 0 && argc == 2)
	{
		location(command, argv);
		return (0);
	}
	read_execute_loop();
	return (0);
}
