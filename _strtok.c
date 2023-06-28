#include "main.h"
/**
 * _strchr - finds a character
 * @s: string from which character is found
 * @c: character to be found
 * Return: pointer to the matched character
 */
char *_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

/**
 * _strtok - breaks strings based on deliminating character
 * @str: string to be passed
 * @delim: deliminating character
 * Return: strings broken down
 */
char *_strtok(char *str, const char *delim)
{
	static char *token_next;
	char *token_start;

	if (str == NULL)
		str = token_next;

	if (str == NULL)
		return (NULL);

	while (*str && _strchr(delim, *str))
		str++;

	if (*str == '\0')
		return (NULL);

	token_start = str;
	while (*str && !_strchr(delim, *str))
		str++;

	if (*str == '\0')
		token_next = NULL;
	else
	{
		*str = '\0';
		token_next = str + 1;
	}
	return (token_start);
}
