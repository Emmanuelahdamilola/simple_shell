#include "main.h"
/**
 * _getenv - gets environment variable
 * @name: environment variable to get
 *
 * Return: environment variable
 */
char *_getenv(const char *name)
{
	char  *env_var;
	size_t name_len, env_var_len;
	int i;

	if (name == NULL || environ == NULL)
		return (NULL);
	name_len = _strlen(name);
	for (i = 0; environ[i] != NULL; i++)
	{
		env_var = environ[i];
		env_var_len = _strlen(env_var);

		if (env_var_len >= name_len)
		{
			if (_strncmp(env_var, name, name_len) == 0 && env_var[name_len] == '=')
				return (&env_var[name_len + 1]);
		}
	}
	return (NULL);
}
