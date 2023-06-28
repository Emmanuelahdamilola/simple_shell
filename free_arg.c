#include "main.h"

/**
 * free_argv - Free the allocated memory for the argument array.
 * @argv: The argument array.
 * @size: The size of the argument array.
 * Return: void
 */
void free_argv(char **argv, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		free(argv[i]);
	}
	free(argv);
}
