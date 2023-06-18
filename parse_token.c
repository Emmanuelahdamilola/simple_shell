#include "main.h"

/**
 * parse_arguments - Tokenize the input line and execute the command.
 * @line: The input line to be parsed
 */
void parse_arguments(char *line)
{
	char *token, **argv, *lineptr_copy = NULL;
	const char *delim = " \n";
	int i, count_tokens = 0;

	lineptr_copy = strdup(line);
	if (lineptr_copy == NULL)
	{
		perror("Memory allocation error");
		return;
	}
	token = strtok(line, delim);
	while (token != NULL)
	{
		count_tokens++;
		token = strtok(NULL, delim);
	}
	count_tokens++;
	argv = malloc(sizeof(char *) * count_tokens);
	if (argv == NULL)
	{
		perror("Memory allocation error");
		free(lineptr_copy);
		return;
	}
	token = strtok(lineptr_copy, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = strdup(token);
		if (argv[i] == NULL)
		{
			perror("Memory allocation error");
			free_argv(argv, i);
			free(lineptr_copy);
			return;
		}
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	execmd(argv);
	free_argv(argv, i);
	free(lineptr_copy);
}
