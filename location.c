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
