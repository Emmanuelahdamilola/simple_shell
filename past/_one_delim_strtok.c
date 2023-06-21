include <stdio.h>

char _strtok(char *str, const char *delim)
{
        char value;

        if (str == NULL)
                return ('\0');

        while (*str != '\0')
        {
                if (*str != delim)
                {
                        value = *str;
                        str++;
                }
                else
                {
                        str++;
                        break;
                }
        }
        return (value);
}
