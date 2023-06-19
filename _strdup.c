#include "main.h"

/**
 * string_dup - function that duplicate string
 * @string: string to be duplicated
 * Return: duplicated string
 */

char *string_dup(char *string)
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
