#include "main.h"
/**
 * location - get location path of command
 * @command: command from stdin
 * Return: file path
 */
char *location(char *command)
{
	struct stat buffer;
	char *path, *path_copy, *path_token, *file_path;
	size_t file_path_len;
	int command_found = 0;

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
		path_token = _strtok(path_copy, ":");
		while (path_token != NULL)
		{
			file_path_len = _strlen(path_token) + 1 + _strlen(command) + 1;
			file_path = malloc(file_path_len);
			_strcpy(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, command);
			if (access(file_path, X_OK) == 0)
			{
				command_found = 1;
				break;
			}
			free(file_path);
			path_token = _strtok(NULL, ":");
		}
		free(path_copy);
	}
	if (!command_found)
	{
		perror("Command not found");
		return (NULL);
	}
	return (file_path);
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
	char *env_str;
	size_t len_str;

	envptr = environ;
	env_count = 0;

	while (*envptr != NULL)
	{
		len_str = _strlen(*envptr) + 1;
		env_str = malloc(len_str);

		if (env_str != NULL)
		{
			_strcpy(env_str, *envptr);
			_strcat(env_str, "\n");
			write(STDOUT_FILENO, env_str, len_str);
			free(env_str);
		}
		envptr++;
		env_count++;
	}
}
