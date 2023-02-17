#include "macro_table.h"
#include <stdlib.h>

macro create_macro(char* name, char* content)
{
    macro m = {name, content};
    return m;
}

void copy_macro(macro source, macro *destination)
{
    set_name(*destination, get_name(source));
    set_content(*destination, get_content(source));
}

int add_macro(macro* macro_array, macro m, int index, int current_size)
{
    int new_size = 0, i;
    macro temp_array[current_size];
    if(index < current_size)
    {
        macro_array[index] = m;
        new_size = current_size;
    }
    else
    {
        /* Copy the array to the temp one */
        for(i=0; i < current_size; i ++)
        {
            copy_macro(macro_array[i], &temp_array[i]);
        }

        /* Extend the array in 10 places */
        new_size = current_size + 10;
        macro_array = (macro *)malloc(new_size);

        /* Copy everything back */
        for(i=0; i < current_size; i ++)
        {
            copy_macro(temp_array[i], &macro_array[i]);
        }
        /* Add the new macro */
        macro_array[index] = m;
    }
    return new_size;
}




char* get_name(macro m)
{
    return m.name;
}

char* get_content(macro m)
{
    return m.content;
}

void set_name(macro m, char* name)
{
    m.name = name;
}
void set_content(macro m, char* content)
{
    m.content = content;
}