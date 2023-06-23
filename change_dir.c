#include "main.h"

void change_dir(char **argv)
{
	char cd_path[256];

	if (argv)
	{
		if (_strcmp(argv[0], "cd") == 0)
		{
			strncpy(cd_path, argv[1], sizeof(cd_path) - 1);
			cd_path[sizeof(cd_path) - 1] = '\0';

			if (chdir(cd_path) == 0)
			{
				return;
			}
			else
			{
				perror("chdir error");
				exit(errno);
			}
		}
	}
}
