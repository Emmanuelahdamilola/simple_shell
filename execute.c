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
	char *command_path;

	if (argv)
	{
		command_path = location(argv[0], argv);
		if (command_path == NULL)
		{
			/*write(STDERR_FILENO, "Command not found\n", 18);*/
			return;
		}
		child_pid = fork();
		if (child_pid == -1)
		{
			write(STDERR_FILENO, "fork error\n", 19);
			return;
		}
		else if (child_pid == 0)
		{
			execve(command_path, argv, NULL);
			write(STDERR_FILENO, "Command execution error\n", 24);
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(child_pid, &status, 0);
			if (WIFEXITED(status))
				WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				WTERMSIG(status);
		}
	}
}
