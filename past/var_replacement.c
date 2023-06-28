#include "main.h"

/**
 * int_to_string - converts integer to string
 * @num: exit code
 * @str: string to be converted
 * Return: void
 */

void int_to_string(int num, char *str)
{
	int i = 0;
    int divisor = 1;

    if (num < 0)
    {
        str[i++] = '-';
        num = -num;
    }

    while (num / divisor >= 10)
        divisor *= 10;

    while (divisor != 0)
    {
        str[i++] = num / divisor + '0';
        num %= divisor;
        divisor /= 10;
    }

    str[i] = '\0';
}

void get_process_id(char *str)
{
    int pid = getpid();

    int_to_string(pid, str);
}

/**
 * replace_variables - replacing variable function
 * @command: input from user
 * Return: replaced variable
 */
char *replace_variables(char *command)
{
	const char *var = "$$";
    const char *var_replace = "pid";
    const char *cmd_ptr = command;
    size_t var_len = strlen(var);
    size_t var_replace_len = strlen(var_replace);
    size_t cmd_len = strlen(command);
    size_t result_len = cmd_len;
    size_t i, count;
    char *result;

    count = 0;
    while ((cmd_ptr = strstr(cmd_ptr, var)) != NULL)
    {
        count++;
        cmd_ptr += var_len;
    }

    result_len += count * (var_replace_len - var_len);
	result = (char *)malloc((result_len + 1) * sizeof(char));
    if (result == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    i = 0;
    cmd_ptr = command;
    while (*cmd_ptr)
    {
        if (strncmp(cmd_ptr, var, var_len) == 0)
        {
            strncpy(&result[i], var_replace, var_replace_len);
            i += var_replace_len;
            cmd_ptr += var_len;
        }
        else
        {
            result[i++] = *cmd_ptr++;
        }
    }

    result[i] = '\0';

    return result;
}

