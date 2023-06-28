#include "main.h"

ssize_t custom_getline() {
    static char buffer[BUFFER_SIZE];
    static ssize_t buffer_pos = 0;
    static ssize_t bytes_read = 0; 
    
    char *line = NULL;
    size_t line_size = 0;
    
    while (1) {
        if (buffer_pos >= bytes_read) {
            bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
            buffer_pos = 0;
            
            if (bytes_read <= 0) {
                if (line != NULL) {
                    free(line);
                }
                
                return NULL;
            }
        }
        
        if (buffer[buffer_pos] == '\n') {
            buffer_pos++;
            
            line[line_size] = '\0';
            return line;
        }
        
        if (line_size % BUFFER_SIZE == 0) {
            size_t new_size = line_size + BUFFER_SIZE;
            line = realloc(line, new_size);
            if (line == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }
        }
        
        line[line_size] = buffer[buffer_pos];
        buffer_pos++;
        line_size++;
    }
}

