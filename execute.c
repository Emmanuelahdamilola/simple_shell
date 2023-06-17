#include "main.h"
/**
 * execmd - execuute the command
 * @argv: The array of command arguments
 * Description: This function executes the specified command by forking a child
 * process and calling execve to replacethe childprocess withthedesired command
 * Return: void
 */
void execmd(char **argv)
{
	pid_t child_pid;
	int status;
	char *command_path;

	if (argv)
	{
		command_path = location(argv[0]);
		if (command_path == NULL)
		{
			perror("Command not found");
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
			/*printf("Executing command: %s\n", command_path);*/
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
		/**free(command_path);*/
	}
}
