/* includes and defines */
#include "pre_assembler.h"
#include "other_functions.h"


int main(int argc, char *argv[])
{
    int i;
    char* error;

    /* Errors checking */
    if(argc >= 2)
    {

        for(i=1;i<argc;i++)
        {
            /*
             * The user gives the file without extension, you add "as"
             */
            printf("%s\n", argv[i]);
            error = pre_assembler(argv[i]);
            if(error)
            {
                printf("%s\n", error);
            }

        }

    }


    return 0;
}
