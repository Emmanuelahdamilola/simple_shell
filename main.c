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
				/*perror*/
				_puts("Terminating shell\n");
			else
			{
				/*perror*/
				_puts("Error\n");
			}
			free(lineptr);
			break;
		}
		parse_arguments(lineptr);
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

	(void)argc;
	(void)argv;

	command = argv[0];
	if (strcmp(command, "exit") == 0 && argc == 2)
	{
		location(command, argv);
		return (0);
	}
	read_execute_loop();
	return (0);
}
