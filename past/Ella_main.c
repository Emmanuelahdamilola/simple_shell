#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TOKENS 100

int main(void) {
    char* full_command = NULL;
    char* copy_command = NULL;
    size_t n = 0;
    ssize_t nchars_read;
    char* token;
    const char* delim = " \n";
    char* argv[MAX_TOKENS];
    int i = 0;
    int num_tokens = 0;

    printf("$ ");

    nchars_read = getline(&full_command, &n, stdin);

    copy_command = malloc(sizeof(char) * nchars_read);

    if (copy_command == NULL) {
        perror("tsh: memory allocation error");
        return -1;
    }

    strcpy(copy_command, full_command);

    if (nchars_read == -1) {
        printf("Exiting shell....\n");
        return -1;
    }
    else {
        token = strtok(full_command, delim);

        while (token != NULL && num_tokens < MAX_TOKENS - 1) {
            argv[num_tokens] = malloc(sizeof(char) * (strlen(token) + 1));
            strcpy(argv[num_tokens], token);
            num_tokens++;
            token = strtok(NULL, delim);
        }
        argv[num_tokens] = NULL;

        /* execute the commands with execve */

        for (i = 0; i < num_tokens; i++) {
            free(argv[i]);
        }

        free(full_command);
        free(copy_command);
    }

    return 0;
}
