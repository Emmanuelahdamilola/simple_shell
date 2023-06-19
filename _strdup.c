#include "main.h"

/**
 *_strdup - function that duplicate string
 * @string: string to be duplicated
 * Return: duplicated string
 */

char *_strdup(const char *string)
{
	char *newString;

	newString = malloc(strlen(string) + 1);

	/*check if the string is NULL*/
	if (newString == NULL)
	{
		return NULL;
	}
	strcpy(newString, string);

	return (newString);
} 
