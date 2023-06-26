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
		if (_strcmp(argv[0], "exit") == 0)
		{
			_puts("exit\n\n\n[Disconnected...]\n");
			exit(0);
		}
		command_path = location(argv[0], argv);
		if (command_path == NULL)
		{
			_puts("Command not found\n");
			return;
		}
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork error");
			return;
		}
		else if (child_pid == 0)
		{
			execve(command_path, argv, NULL);
			perror("Command execution error");
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
