#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

int _puts(const char *str);
int _putchar(char c);
void execmd(char **argv);
char *location(char *command);
void read_execute_loop(void);
void parse_arguments(char *line);
void free_argv(char **argv, int size);


#endif
