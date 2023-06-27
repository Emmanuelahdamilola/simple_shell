#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

char *lineptr = NULL;

void sigint_handler(int signum)
{
    if (signum == SIGINT)
    {
        free(lineptr);
        exit(0);
    }
}

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
    size_t bufsize = 1024;
    size_t position = 0;
    char *buffer = (char *)malloc(bufsize);
    ssize_t num_chars;
    char *new_buffer;

    if (buffer == NULL) {
        perror("Memory allocation error");
        return -1;
    }

    while (1) {
        num_chars = read(fileno(stream), buffer + position, 1);
        if (num_chars == -1) {
            perror("Read error");
            free(buffer);
            return -1;
        }
        if (num_chars == 0) {
            if (position == 0) {
                free(buffer);
                return -1;
            } else {
                break;
            }
        }
        position++;

        if (position >= bufsize - 1) {
            bufsize += 1024;
            new_buffer = (char *)realloc(buffer, bufsize);
            if (new_buffer == NULL) {
                perror("Memory reallocation error");
                free(buffer);
                return -1;
            }
            buffer = new_buffer;
        }

        if (buffer[position - 1] == '\n')
            break;
    }

    buffer[position] = '\0';
    *lineptr = buffer;
    *n = position;

    return position;
}

void read_execute_loop(void)
{
        char *lineptr = NULL;
        size_t n = 0;
        ssize_t num_chars;
        int interactive_mode;

        interactive_mode = isatty(STDIN_FILENO);
        while (1)
        {
                if (interactive_mode)
                	puts("($) ");
		free(lineptr);
                num_chars = my_getline(&lineptr, &n, stdin);
                if (num_chars == -1)
                {
                        if (feof(stdin))
                                /*perror*/
                                puts("Terminating shell\n");
                        else
                        {
                                /*perror*/
                                puts("Error\n");
                        }
                        break;
                }
               /* parse_arguments(lineptr);*/
                if (interactive_mode)
                        continue;
                else
                        break;
        }
 	free(lineptr);
}

int main(int argc, char **argv)
{
        char *command;

        (void)argc;
        (void)argv;

        command = strdup(argv[0]);
        if (strcmp(command, "exit") == 0 && argc == 2)
        {
               /* location(command, argv); */
                free(command);
		return (0);
        }
	signal(SIGINT, sigint_handler);
        read_execute_loop();
	
	free(lineptr);
	free(command);
        return (0);
}
