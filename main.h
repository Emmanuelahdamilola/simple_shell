#ifndef MAIN_H
#define MAIN_H

#define BUFFER 2048

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;

int _puts(const char *str);
int _putchar(char c);
void _execute(char **argv);
char *location(char *command);
void read_execute_loop(void);
void parse_arguments(char *line);
void free_argv(char **argv, int size);
size_t _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strdup(const char *string);
int _strcmp(const char *s1, const char *s2);
void env(void);
ssize_t _getline(char **lineptr, size_t *n, FILE *s);

#endif
