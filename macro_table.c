#include "macro_table.h"
#include <stdlib.h>
#include <string.h>


macro_list* create_macro(char* name, char* content)
{
    macro_list* temp = malloc(sizeof(struct macro_list));
    temp->name = name;
    temp->content = content;
    return temp;
}

macro_list* add_macro(macro_list* head, char* name, char* content)
{
    macro_list *temp, *p;
    temp = create_macro(name, content);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        p = head;
        while (p->next != NULL)
            p = p->next;
        p->next = temp;
    }
    return head;
}

char* get_name(macro_list* node)
{
    return node->name;
}

char* get_content(macro_list* node)
{
    return node->content;
}