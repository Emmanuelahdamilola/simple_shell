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
		write(STDERR_FILENO, "Error: Failed to set environment variable\n", 42);
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
		write(STDERR_FILENO, "Error: Failed to unset environment variable\n", 44);
}
