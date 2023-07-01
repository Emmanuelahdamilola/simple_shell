#include "main.c"

/**
 * _strspn - calculates the length of the initial segment of a string that
 * consists of only the characters present in another string
 * @str: A pointer to the null-terminated string to be examined
 * @accept: A pointer to the null-terminated string containing the set
 * of characters to match
 * Return: length of the initial segment of str
 */
size_t _strspn(const char *str, const char *accept)
{
	const char *p;
	const char *a;
	size_t count = 0;

	for (p = str; *p != '\0'; p++)
	{
		for (a = accept; *a != '\0'; a++)
		{
			if (*p == *a)
			{
				count++;
				break;
			}
		}
		if (*a == '\0')
		{
			break;
		}
	}
	return (count);
}

/**
 * _strpbrk - searches a string for any of a set of specified characters
 * @str: A pointer to the null-terminated string to be searched
 * @accept: A pointer to the tring containing the set ofcharacters tosearchfor
 * Return: pointer to the first occurrence of the matching character in str
 *	f no match is found, the function returns NULL
 */
char *_strpbrk(const char *str, const char *accept)
{
	const char *s;
	const char *a;

	for (s = str; *s != '\0'; s++)
	{
		for (a = accept; *a != '\0'; a++)
		{
			if (*s == *a)
			{
				return ((char *)s);
			}
		}
	}
	return (NULL);
}

/**
 * _strtok_r - function is used to tokenize a string into a sequence of tokens
 * @str: A pointer to the null-terminated string to be tokenized
 * @delim: A pointer to the string containing the delimiter characters
 * @saveptr: A pointer to a char* variable that is used to store the
 * context pointer for subsequent calls
 * Return: a pointer to the next token in the string str
 */
char *_strtok_r(char *str, const char *delim, char **saveptr)
{
	char *token;

	if (str == NULL) 
	{
		str = *saveptr;
	}
	str += _strspn(str, delim);

	if (*str == '\0')
	{
		*saveptr = str;
		return (NULL);
	}
	token = str;
	str = _strpbrk(token, delim);

	if (str == NULL)
	{
		*saveptr = _strchr(token, '\0');
	}
	else
	{
		*str = '\0';
		*saveptr = str + 1;
	}
	return (token);
}

void execute_logical_operators(char *line)
{
	char *command;
	char *saveptr;
	int status = 0, previous_result = 1;
	int is_and_operator, is_or_operator;

	/*command = _strtok_r(line, "&&||", &saveptr);*/

	while (command != NULL)
	{
		is_and_operator = _strcmp(command, "&&") == 0;
		is_or_operator = _strcmp(command, "||") == 0;

		command = _strtok_r(NULL, "&&||", &saveptr);

		if (is_and_operator)
		{
			if (previous_result == 0)
			{
				continue;
			}
		}
		else if (is_or_operator)
		{
			if (previous_result != 0)
			{
				continue;
			}
		}
		if (command != NULL)
		{
			parse_arguments(command);
			/**
			 * status = get_command_status();
			previous_result = status == 0 ? 1 : 0;
			*/
		}
	}
}

void execute_commands(char *line)
{
	char *command;
	char *saveptr;

	command = _strtok_r(line, ";", &saveptr);

	while (command != NULL)
	{
		parse_arguments(command);
		command = _strtok_r(NULL, ";", &saveptr);
	}
}

