#include <string.h>
#include <stdlib.h>

char* add_extension(char* file, char* extension)
{
    char *str = (char *)malloc(strlen(file) + strlen(extension) + 1);
    strcpy(str, file);
    strcat(str, extension);

    return str;
}

char* initialize_string(char* buffer, int min_length)
{
    buffer = (char*)malloc( (min_length+1) * sizeof(char *));
    return buffer;
}