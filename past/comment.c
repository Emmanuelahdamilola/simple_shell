void ignore_comments(char *line)
{
    char *comment_pos = strchr(line, '#');

    if (comment_pos != NULL)
    {
        if (comment_pos == line && (*(comment_pos - 1) == ' ' || *(comment_pos - 1) == '\t'))
        {
            *comment_pos = '\0';
        }
        else if (*(comment_pos - 1) == ' ' || *(comment_pos - 1) == '\t' || *(comment_pos - 1) == '\0')
        {
            *comment_pos = '\0';
        }
    }
}
