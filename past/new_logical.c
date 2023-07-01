#include "main.h"

/**
 * logical - Tokenize(split) the input line and execute the command
 * @line: The input line to be parsed
 */

/**
 * char *logical(char *line)
{
	char *token;

	token = strtok(line, ";");
	while (token != NULL)
	{
		token = strtok(NULL, ";");
		parse_arguments(token);
	}
	return (token);
}

void logical(char *line)
{
	char *token;
	token = strtok(line, ";");
	parse_arguments(token);
}
*/

/**
 * char* logical(char* line)
{
    char* token;
    char* saveptr;
    char* modified_line = malloc(_strlen(line) + 1);
    char* result = modified_line;

    if (modified_line == NULL)
    {
        write(STDERR_FILENO, "Memory allocation error\n", 24);
        return (NULL);
    }

    token = strtok_r(line, ";", &saveptr);
    while (token != NULL)
    {
        printf("%s\n", token);

        _strcpy(modified_line, token);
        modified_line += _strlen(token);
        *modified_line++ = ' ';

        token = strtok_r(NULL, ";", &saveptr);
    }
    *--modified_line = '\0';

    return (result);
}
*/
