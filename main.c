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

	interactive_mode = isatty(STDIN_FILENO);
	while (1)
	{
		if (interactive_mode)
			_puts("($) ");
		while ((num_chars = getline(&lineptr, &n, stdin)) != -1)
		{
			if (num_chars > 0 && lineptr[num_chars - 1] == '\n')
				lineptr[num_chars - 1] = '\0';
			if (num_chars == EOF)
			{
				if (feof(stdin))
					_puts("Error reading input\n");
				else
					_puts("Error\n");
				break;
			}
			parse_arguments(lineptr);
			_puts("($) ");
		}
		if (!interactive_mode)
		{
			printf("herrr");
			break;
		}
		free(lineptr);
		lineptr = NULL;
		n = 0;
	}
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

	/*(void)argc;*/
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
