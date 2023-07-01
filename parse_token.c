#include "main.h"

/**
 * ignore_comments - function ignore comments
 * @line: command passed
 * Return: void
 */

void ignore_comments(char *line)
{
    char *comment_pos = strchr(line, '#');

    if (comment_pos != NULL)
    {
        if (comment_pos == line && (*(comment_pos - 1) == ' ' || *(comment_pos - 1) == '\t'))
        {
            *comment_pos = '\0';
        }
        else if (*(comment_pos - 1) == ' ' || *(comment_pos - 1) == '\t' || *(comment_pos - 1) == '\0')
        {
            *comment_pos = '\0';
        }
    }
}


/**
 * void ignore_comments(char *line)
{
	char *comment_pos = _strchr(line, '#');
	
	if (comment_pos != NULL)
	{
		if (comment_pos == line && *(comment_pos - 1) == ' ')
			*comment_pos = '\0';
		else if (comment_pos == line && *comment_pos == '\0' && *(comment_pos - 1) == ' ')
			*comment_pos = '\0';
	}
}*/

/**
 * void ignore_comments(char *line)
{
	char *comment_pos = strchr(line, '#');
	char *non_whitespace_pos;

	if (comment_pos != NULL)
	{
		non_whitespace_pos = line;
		while (*non_whitespace_pos == ' ' || *non_whitespace_pos == '\t')
		{
			non_whitespace_pos++;
		}
		if (non_whitespace_pos == comment_pos)
		{
			*comment_pos = '\0';
		}
	}
}
*/

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
