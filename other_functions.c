#include <string.h>
#include <stdlib.h>


char* concatenate_strings(char* s1, char* s2)
{
    char *str = (char *)malloc(strlen(s1) + strlen(s2));
    strcpy(str, s1);
    strcat(str, s2);
    return str;
}

char* concatenate_strings_with_free(char* s1, char* s2)
{
    char *str = (char *)malloc(strlen(s1) + strlen(s2));
    strcpy(str, s1);
    strcat(str, s2);
    free(s1);
    return str;
}
