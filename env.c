#include "main.h"

/**
* Description: function that  effectively print each environment variable
* followed by a newline character, replicating the
* behavior of the env command.
* Return: Null
*
 void env_vars(void)
{
	char **envptr;
	char *env_str;
	size_t len_str;

	envptr = environ;

	while (*envptr != NULL)
	{
		len_str = _strlen(*envptr) + 1;
		env_str = malloc(len_str);

		if (env_str != NULL)
		{
			len_str = _strlen(*envptr) + 1;
			write(STDOUT_FILENO, env_str, len_str);
		}
		envptr++;
	}
}
*/
