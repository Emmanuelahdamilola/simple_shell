#include "main.h"
#include "main.h"

/**
 * _setenv - function that initializes a new environment
 * variable or modifies an existing one based on the
 * command syntax: setenv VARIABLE VALUE.
 * @args: arguments
 *
 * Return: nothing
 */
void _setenv(char *args[])
{
    if (args[1] == NULL || args[2] == NULL)
    {
        write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n", 29);
        return;
    }
    if (setenv(args[1], args[2], 1) == -1)
    {
        write(STDERR_FILENO, "Error: Failed to set environment variable\n", 42);
    }
}

/**
 * _unsetenv - function that removes an environment variable
 * based on the command syntax: unsetenv VARIABLE.
 * @args: arguments
 *
 * Return: nothing
 */
void _unsetenv(char *args[])
{
    if (args[1] == NULL)
    {
        write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 25);
        return;
    }
    if (unsetenv(args[1]) == -1)
    {
        write(STDERR_FILENO, "Error: Failed to unset environment variable\n", 44);
    }
}

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
	if (_strcmp(command, "setenv") == 0)
		return (setenvCommand(argv));

	if (_strcmp(command, "unsetenv") == 0)
		return (unsetenvCommand(argv));

	file_path = search_file_path(command);
	return (file_path);
}
/**
 * setenvCommand - function that handles the setenv command
 * @argv: argument vector
 * Return: NULL
 */
char *setenvCommand(char **argv)
{
	if (argv[1] && argv[2])
	{
		if (setenv(argv[1], argv[2], 1) == -1)
		{
			perror("Erro:");
		}
	}
	else
	{
		write(STDERR_FILENO, "Syntax: setenv VARIABLE VALUE\n", 30);
	}
	return (NULL);
}
/**
 * unsetenvCommand - function that handles the unsetenv command
 * @argv: argument vector
 * Return: NULL
 */
char *unsetenvCommand(char **argv)
{
	if (argv[1])
	{
		if (unsetenv(argv[1]) == -1)
		{
			perror("Error:");
		}
	}
	else
	{
		write(STDERR_FILENO, "Syntax: unsetenv VARIABLE\n", 27);
	}
	return (NULL);
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
	int command_found = 0;

	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);

	path_copy = _strdup(path);
	path_token = strtok(path_copy, ":");
	while (path_token != NULL)
	{
		file_path = construct_filepath(path_token, command);
		if (access(file_path, X_OK) == 0)
		{
			command_found = 1;
			break;
		}
		free(file_path);
		path_token = strtok(NULL, ":");
	}
	free(path_copy);
	if (!command_found)
	{
		perror("Command not found");
		return (NULL);
	}
	return (file_path);
	/*return (NULL);*/
}

/**
 * construct_filepath - function that construct the file path
 * by combining directory and command
 * @dir: directory from the PATH
 * @command: command to append to the directory
 * Return: constructed file path
 */
char *construct_filepath(char *dir, char *command)
{
	size_t file_path_len;
	char *file_path;

	file_path_len = _strlen(dir) + 1 + _strlen(command) + 1;
	file_path = malloc(file_path_len);

	if (file_path == NULL)
		return (NULL);

	_strcpy(file_path, dir);
	_strcat(file_path, "/");
	_strcat(file_path, command);
	return (file_path);
}
