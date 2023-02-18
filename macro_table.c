#include "macro_table.h"
#include <stdlib.h>
#include <string.h>

macro_list* create_empty_macro()
{
    macro_list* temp = malloc(sizeof(struct macro_list)); /* Create empty node */
    return temp;
}

macro_list* create_macro(char* name, char* content)
{
    macro_list* temp = malloc(sizeof(struct macro_list)); /* Create empty node */

    temp->name = name;
    temp->content = content;
//    temp.name = malloc(sizeof(char) * (strlen(name) + 1));
//    temp.content = malloc(sizeof(char) * (strlen(content) + 1));
//    strcpy(temp.name, name);
//    strcpy(temp.content, content);
    return temp;
}


/*
 * Returns 1 if empty
 * 0 if not empty.
 */
is_macro_empty(macro_list* node)
{
    if(node->name && node->content)
        return 0;
    return 1;
}

macro_list* add_macro(macro_list* head, char* name, char* content)
{
    macro_list *temp, *p;// declare two nodes temp and p
    temp = create_macro(name, content);//createNode will return a new node with data = value and next pointing to NULL.
    if (is_macro_empty(head))
    {
        head = temp;     //when linked list is empty
    }
    else
    {
        p = head;//assign head to p
        while (p->next != NULL)
            p = p->next;//traverse the list until p is the last node.The last node always points to NULL.
        p->next = temp;//Point the previous last node to the new node created.
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