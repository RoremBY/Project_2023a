#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "other_functions.h"
#include "pre_assembler.h"
#include "macro_table.h"
#define MAX_LINE_LENGTH 82 /* Plus 2 for \n\0 in book and forum said max 80 for line */
#define ON 1
#define OFF 0


char* concatenate_content(char* current_content, char* current_line)
{
    char *temp1, *temp2;
    int max_size;

    max_size = strlen(current_content) + strlen(current_line);
    temp1 = malloc(sizeof (char) * max_size);
    temp2 = malloc(sizeof (char)* strlen(current_line));
    strcpy(temp1, current_content);
    strcpy(temp2, current_line);
    strcat(temp1, temp2);
    return temp1;
}



char* pre_assembler(char* file)
{
    char *error = NULL;
    char *file_name, *pre_assembler_output_file;
    char *current_macro, *current_content;
    char *temp_macro, *temp_name, *temp_content;
    char *first_word_in_line, current_line[MAX_LINE_LENGTH], temp_line[MAX_LINE_LENGTH];
    int line_to_file, is_mcr = OFF;
    macro_list *head, *temp_node;

    FILE *input_file, *output_file;

    /* Add extension to files */
    file_name = add_extension(file, ".as");
    pre_assembler_output_file = add_extension(file, ".am");

    /* Open the files with the right modes */
    input_file = fopen(file_name, "r");
    output_file = fopen(pre_assembler_output_file, "w");

    /* Initialize the current content string */
    current_content = initialize_string(current_content, 10);

    head = create_empty_macro();
    if (input_file)
    {
        while((fgets(current_line, MAX_LINE_LENGTH + 2, input_file)))
        {
            line_to_file = 1;

            if(!strchr(current_line, '\n'))
                return "[ERROR] One of the lines in the file is bigger then 80! max size for line is 80!\n";
            if(current_line[0] == ';')
                line_to_file = 0; /* don't print comment lines to file */

            /* Create copy */
            strcpy(temp_line, current_line);

            if(is_mcr)
            {
                line_to_file = 0; /* Make sure doesn't print while macro is on */
                if(!strcmp(first_word_in_line, "endmcr\n"))
                {
                    is_mcr = OFF;
                    head = add_macro(head, current_macro, current_content);
                    current_content = initialize_string(current_content, 10);
                }
                else
                {
                    /* While is_mcr on and there hasn't been endmcr, store the macro in a string */
                    if(current_content)
                    {
                        current_content = concatenate_content(current_content, current_line);
                    }
                    else
                    {
                        current_content = malloc(sizeof(char) * strlen(temp_line));
                        strcpy(current_content, temp_line);
                    }
                }
            }

            /* Change the original line to get first word */
            first_word_in_line = strtok(current_line, " ");
            if(!strcmp(first_word_in_line, "mcr"))
            {
                is_mcr = ON;
                temp_macro = strtok(NULL, " "); /* Take only the name of the macro and store it, with \n */
                current_macro = malloc(sizeof (char)* strlen(temp_macro));
                strcpy(current_macro, temp_macro);
                line_to_file = 0;
            }

            temp_node = head;
            while(!is_macro_empty(temp_node)) /* Enter only if table isn't empty */
            {
                temp_name = get_name(temp_node);
                if(!strcmp(temp_name, first_word_in_line))
                {
                    temp_content = get_content(temp_node);
                    fputs(temp_content, output_file);
                    line_to_file = 0; /* Make sure doesn't print the name of the macro too */

                }
                if(temp_node->next != NULL)
                {
                    temp_node = temp_node->next;
                }
                else
                {
                    temp_node = create_empty_macro();
                }
            }

            /* Check if needed to write the current line to file or not! */
            if(line_to_file)
                fputs(temp_line, output_file);
        }
    }
    else
    {
        error = "[ERROR] Error in opening the file\n";
    }
    fclose(input_file);
    fclose(output_file);
    if (error)
        return error;
    return 0;
}
