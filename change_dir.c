#include "main.h"

/**
 * change_dir - change directory
 * @argv: directory path
 *
 * Return: diirctory
 */

void change_dir(char **argv)
{
	const char *home_dir;

	if (argv)
	{
		if (_strcmp(argv[0], "cd") == 0)
		{
			if (argv[1] == NULL)
			{
				home_dir = getenv("HOME");
				if (home_dir == NULL)
				{
					perror("No HOME environment");
					return;
				}
				if (chdir(home_dir) == -1)
				{
					perror("chdir error");
					return;
				}
			}
			else
			{
				if (chdir(argv[1]) == -1)
				{
					perror("chdir error");
					return;
				}
			}
		}
		else
			perror("No argument passed");
	}
}
