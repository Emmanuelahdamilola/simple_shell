#include "main.h"

/**
 * _execute - execuute the command
 * @argv: The array of command arguments
 * Description: This function executes the specified command by forking a child
 * process and calling execve to replacethe childprocess withthedesired command
 * Return: void
 */
void _execute(char **argv)
{
	pid_t child_pid;
	int status;
	char *final_command = NULL;
	char exit_code[10];
	char *command_path;

	if (argv)
	{
		command_path = location(argv[0], argv);
		if (command_path == NULL)
		{
			/*write(STDERR_FILENO, "Command not found\n", 18);*/
			return;
		
		}
		else
		{
			_variables(argv);
			final_command = command_path;
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Fork error");
				exit(EXIT_FAILURE);
			}
			if (child_pid == 0)
			{
				if (execve(final_command, argv, NULL) == -1)
				{
					perror("Command execution error");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				wait(&status);
				_itoa_alt(WEXITSTATUS(status), exit_code, sizeof(exit_code));
				setenv("?", exit_code, 1);
				free(final_command);
			}
		}
	}
}
