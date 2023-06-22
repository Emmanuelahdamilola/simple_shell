#include "main.h"

/**
 * _getenv - gets environment variable
 * @name: environment variable to get
 *
 * Return: environment variable
 */

char *_getenv(const char *name)
{
	char **env = environ;
	char *equal;
	size_t length;

	while (*env != NULL)
	{
		equal = _strchr(*env, '=');

		if (equal != NULL)
		{
			length = equal - *env;

			if (length == _strlen(name) && _strcmp(name, *env) == 0)
				return (equal + 1);
		}
		env++;
		/*printf("%s", *env);*/
	}
	return (NULL);
}
