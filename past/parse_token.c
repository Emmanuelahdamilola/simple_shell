#include "main.h"

void parse_operators(char *command)
{
	char *token;
	const char *delim = "&&||";
	
	token = _strtok(command, delim);
	while (token != NULL)
	{
		_execute(&command);
		token = _strtok(NULL, delim);
	}
}

/**
 * ignore_comments - function ignore comments
 * @line: command passed
 * Return: void
 */
void ignore_comments(char *line)
{
	char *comment_pos = _strchr(line, '#');

	if (comment_pos != NULL)
		*comment_pos = '\0';
}

/**
 * parse_arguments - Tokenize(split) the input line and execute the command
 * @line: The input line to be parsed
 */
void parse_arguments(char *line)
{
	char *token, **argv, *lineptr_copy = NULL;
	const char *delim = " \n;";
	int i, count_tokens = 0;

	ignore_comments(line);
	lineptr_copy = _strdup(line);
	if (lineptr_copy == NULL)
		return;
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
		free(argv);
		return;
	}
	token = _strtok(lineptr_copy, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = _strdup(token);
		if (argv[i] == NULL)
		{
			perror("Memory allocation error"); /*free_argv(argv, i);*/
			free_argv(argv, i);
			free(lineptr_copy);
			return;
		}
		token = _strtok(NULL, delim);
	}
	for (i = 0; i < count_tokens; i++)
		parse_operators(argv[i]);
	free_argv(argv, i);
	free(lineptr_copy);
}
