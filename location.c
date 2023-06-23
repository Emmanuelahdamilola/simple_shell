#include "main.h"

/**
 * location - get file path
 * @command: command from stdin
 * @argv: argument vector
 * Return: file path
 */
char *location(char *command, char **argv)
{
	struct stat buffer;
	char *file_path;

	if (stat(command, &buffer) == 0)
		return (command);

	if (_strcmp(command, "exit") == 0 && argv[1] != NULL)
	{
		int status;

		status = atoi(argv[1]);
		exit(status);
	}
	if (_strcmp(command, "env") == 0)
	{
		char **envptr;

		envptr = environ;
		while (*envptr != NULL)
		{
			write(STDOUT_FILENO, *envptr, _strlen(*envptr));
			write(STDOUT_FILENO, "\n", 1);
			envptr++;
		}
	}

	file_path = search_file_path(command);
	return (file_path);
}

/**
 * search_file_path - function that searches for the file
 * in the PATH environment variable
 * @command: command to search for
 * Return: file path if found, otherwise NULL
 */
char *search_file_path(char *command)
{
	char *path;
	char *path_copy, *path_token;
	char *file_path;

	path = getenv("PATH");
	if (path == NULL)
		return (NULL);

	path_copy = _strdup(path);
	path_token = strtok(path_copy, ":");
	while (path_token != NULL)
	{
		file_path = construct_filepath(path_token, command);
		if (access(file_path, X_OK) == 0)
		{
			free(path_copy);
			return (file_path);
		}
		free(file_path);
		path_token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

/**
 * construct_filepath - function that construct the file path
 * by combining directory and command
 * @directory: directory from the PATH
 * @command: command to append to the directory
 * Return: constructed file path
 */
char *construct_filepath(char *directory, char *command)
{
	size_t file_path_len;
	char *file_path;

	file_path_len = _strlen(directory) + 1 + _strlen(command) + 1;
	file_path = malloc(file_path_len);

	if (file_path == NULL)
		return (NULL);

	_strcpy(file_path, directory);
	_strcat(file_path, "/");
	_strcat(file_path, command);
	return (file_path);
}

