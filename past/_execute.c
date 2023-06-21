#include "main.h"

void _execute(char **argv)
{
    pid_t child_pid;
    int exit_status = atoi(argv[1]), status;
    char *command_path;

    if (argv)
    {
        if (_strcmp(argv[0], "exit") == 0)
        {
            if (argv[1] != NULL)
            {
                if (exit_status >= 0 && exit_status <= 255)
                {
                    exit(exit_status);
                    return;  /* Exit the function after calling exit()*/
                }
                else
                {
                    perror("Invalid exit status");
                    return;
                }
            }
            else
            {
                _puts("exiting shell...\n\n\n\n[exit]\n");
                exit(0);
                return;  /*Exit the function after calling exit()*/
            }
        }

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
