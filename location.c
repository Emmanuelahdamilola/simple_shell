#include "main.h"
/**
 * location - get file path
 * @command: command from stdin
 * Return: file pth
 */
char *location(char *command)
{
	struct stat buffer;
	char *path, *path_copy, *path_token, *file_path;
	size_t file_path_len;

	if (_strcmp(command, "env") == 0)
	{
		env();
		return (NULL);
	}

	if (stat(command, &buffer) == 0)
		return (command);
	path = getenv("PATH");
	if (path != NULL)
	{
		path_copy = _strdup(path);
		path_token = strtok(path_copy, ":");

		while (path_token != NULL)
		{
			file_path_len = _strlen(path_token) + 1 + _strlen(command) + 1;
			file_path = malloc(file_path_len);
			_strcpy(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, command);

			if (access(file_path, X_OK) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			free(file_path);
			path_token = strtok(NULL, ":");
		}
		free(path_copy);
	}
	return (NULL);
}

/**
 * env - function that print environment variables and their value
 * Description: function that  effectively print each environment variable
 * followed by a newline character, replicating the
 * behavior of the env command.
 * Return: Null
 */

void env(void)
{
	char **envptr;
	int env_count;
	char *env_string;
	size_t len_str;

	envptr = environ;
	env_count = 0;

	while (*envptr != NULL)
	{
		len_str = _strlen(*envptr) + 1; /* give space for the null terminator*/
		env_string = malloc(len_str);   /*allocate memory dynamically*/

		if (env_string != NULL)
		{
			_strcpy(env_string, *envptr);
			_strcat(env_string, "\n");
			write(STDOUT_FILENO, env_string, len_str);
			free(env_string); /*free the allocated memory*/
		}
		envptr++;
		env_count++;
	}
}
