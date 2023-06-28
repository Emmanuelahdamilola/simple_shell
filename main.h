#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdbool.h>

extern char **environ;
int read_buff(FILE *stream, char *buffer, ssize_t *bytes_read);
int null_terminateline(char **line, size_t line_size, size_t line_length);
int expand_line_buffer(char **line, size_t *line_size, size_t line_length);
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream);
int _puts(const char *str);
int _putchar(char c);
void _execute(char **argv);
char *location(char *command, char **argv);
void read_execute_loop(void);
void parse_arguments(char *line);
void free_argv(char **argv, int size);
size_t _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strdup(const char *string);
int _strcmp(const char *s1, const char *s2);
/*void env(void);*/
char *construct_filepath(char *directory, char *command);
char *search_file_path(char *command);
ssize_t _getline(char **lineptr, size_t *n, FILE *s);
char *_strchr(const char *s, int c);
char *_strtok(char *str, const char *delim);
char *_getenv(const char *name);
void change_dir(char **argv);
int _strncmp(const char *str1, const char *str2, size_t n);
void separator(char *line);
char *setenvCommand(char **argv);
char *unsetenvCommand(char **argv);
void _setenv(char *args[]);
void _unsetenv(char *args[]);

#endif
