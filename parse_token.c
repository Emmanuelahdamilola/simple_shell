#include "main.h"

/**
 * ignore_comments - function ignore comments
 * @line: command passed
 * Return: void
 */
void ignore_comments(char *line)
{
	char *com = strchr(line, '#');

	if (com != NULL)
	{
		if (com == line && (*(com - 1) == ' ' || *(com - 1) == '\t'))
		{
			*com = '\0';
		}
		else if (*(com - 1) == ' ' || *(com - 1) == '\t' || *(com - 1) == '\0')
		{
			*com = '\0';
		}
	}
}

/**
 * filter_parse_arguments - Tokenize the input line and execute the command
 * @line: The input line to be parsed
 */
void filter_parse_arguments(char *line)
{
	char *token, **argv, *lineptr_copy = NULL;
	const char *delim = " \n";
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
		write(STDERR_FILENO, "Memory allocation error\n", 24);
		free(lineptr_copy);
		return;
	}
	token = _strtok(lineptr_copy, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = _strdup(token);
		if (argv[i] == NULL)
		{
			write(STDERR_FILENO, "Memory allocation error\n", 24);
			free_argv(argv, i);
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

/**
 * parse_arguments - Tokenize(split) the input line and execute the command
 * @line: The input line to be parsed
 */

void parse_arguments(char *line)
{
	char *token;

	if (line == NULL)
		return;

	if (_strchr(line, ';') != NULL)
	{
		token = strtok(line, ";");
		while (token != NULL)
		{
			filter_parse_arguments(token);
			token = strtok(NULL, ";");
		}
	}
	else
	{
		filter_parse_arguments(line);
	}
	/*return;*/
}
