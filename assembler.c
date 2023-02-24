/* includes and defines */
#include "pre_assembler.h"
#include "other_functions.h"
#include "first_pass.h"


int main(int argc, char *argv[])
{
    int i;
    char* error;

    /* Errors checking */
    /* if(argc >= 2) - Doesn't need to check this, if no files were given, nothing happen. */

    for(i=1;i<argc;i++)
    {
        /*
        * The user gives the file without extension, you add "as"
        */
        error = pre_assembler(argv[i]);
        if(error)
        {
            printf("%s", "[ERROR] in file: ");
            printf("%s", argv[i]);
            printf("\n%s\n", error);
        }
        else
        {
            first_pass(argv[i]);
        }

    }
    return 0;
}
