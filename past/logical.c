/**
 * void logical_operators(char *command)
{
        char *token, *operator;
        
        token = strtok(command, "&|");
        while (token != NULL)
        {
                operator = _strtok(token, " \t");
                if (operator != NULL && strlen(operator) > 0)
                {
                        parse_arguments(operator);
                }
                token = _strtok(NULL, "&|");
        }
}
*/
