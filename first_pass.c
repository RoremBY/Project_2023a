#include "other_functions.h"
#include "first_pass.h"
#include "globals.h"

char* first_pass(char* file)
{
    char *error = NULL;
    char *file_name;
    char current_line[MAX_LINE_LENGTH];
    int is_label = OFF; /* Init at no label */
    int ic = 0, dc = 0; /* Init DC and IC to 0 */

    FILE *input_file;

    file_name = concatenate_strings(file, ".am"); /* Get the file after the pre assembler */

    /* Open the files with the right modes */
    input_file = fopen(file_name, "r");

    if (input_file)
    {
        while((fgets(current_line, MAX_LINE_LENGTH, input_file)))
        {


        }
    }
    else
    {
        error = "[ERROR] Error in opening the file\n";
    }

    /* Free memory */
    free(file_name);
    if (error)
        return error;
    return 0;
}
