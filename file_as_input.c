#include "main.h"
#define MAX_COMMAND_LENGTH 1024

/**
 * execute_commands_file - function that takes a filename as an
 * argument and reads commands from that file.
 * @filename:an argument to execute the commands in the file.
 */

void execute_commands_file(const char *filename)
{
	int file;
	ssize_t index = 0;
	char command[MAX_COMMAND_LENGTH];
	ssize_t nbytes_read;

	file = open(filename, O_RDONLY);
	if (file == -1)
	{
		perror("Error");
		exit(1);
	}

	while ((nbytes_read = read(file, command, MAX_COMMAND_LENGTH)) > 0)
	{
		for (; index < nbytes_read; index++)
		{
			if (command[index] == '\n')
			{
				command[index] = '\0';
				if (_strlen(command) > 0)
				{
					system(command);
				}
				command[index] = '\n';
			}
		}
	}
	close(file);
}

/**
 * main_file - entry point of the program
 * @argv: argument vector
 * @argc: argument count
 * Return: 0
 */
int main_file(int argc, char *argv[])
{
	const char *error_msg;
	char *file_name;
	struct stat file_info;
	char error_buff[100];

	if (argc != 2)
	{
		error_msg = "Usage: ./simple_shell [filename]\n";
		write(2, error_msg, _strlen(error_msg));
		exit(1);
	}

	file_name = _strdup(argv[1]);
	file_name[_strlen(argv[1])] = '\0';
	if (stat(file_name, &file_info) != 0)
	{
		_strcpy(error_buff, "Error: Can't open '");
		_strcat(error_buff, file_name);
		_strcat(error_buff, "'\n");
		write(2, error_buff, _strlen(error_buff));
		exit(1);
	}

	execute_commands_file(argv[1]);

	return (0);
}

