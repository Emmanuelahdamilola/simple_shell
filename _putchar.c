#include "main.h"

/**
 * _putchar - the function that prints character
 * @c: character to be printed
 *
 * Return: EOF (End of File)
 */

int _putchar(char c)
{
	if (write(1, &c, 1) == 1)
	{
		return ((unsigned char) c);
	}
	/*EIO, which is a predefined value indicating an input/output error*/
	errno = EIO;

	return (EOF);
}
