#include "main.h"
/**
 * parse_arguments - Tokenize(split) the input line and execute the command
 * @line: The input line to be parsed
 */
void parse_arguments(char *line)
{
	char *token, **argv, *lineptr_copy = NULL;
	const char *delim = " \n;";
	int i, count_tokens = 0;

	lineptr_copy = _strdup(line);
	if (lineptr_copy == NULL)
	{
		perror("Memory allocation error");
		return;
	}
	token = _strtok(line, delim);
	while (token != NULL)
	{
		count_tokens++;
		token = _strtok(NULL, delim);
	}
	count_tokens++;
	argv = malloc(sizeof(char *) * count_tokens);
	if (argv == NULL)
	{
		perror("Memory allocation error");
		free(lineptr_copy);
		return;
	}
	token = _strtok(lineptr_copy, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = _strdup(token);
		if (argv[i] == NULL)
		{
			perror("Memory allocation error"); /*free_argv(argv, i);*/
			free(lineptr_copy);
			return;
		}
		token = _strtok(NULL, delim);
	}
	argv[i] = NULL;
	_execute(argv);
	free_argv(argv, i);
	free(lineptr_copy);
}
