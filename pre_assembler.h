#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_LINE_LENGTH 82 /* Plus 2 for \n\0 in book and forum said max 80 for line */
#define ON 1              /* ON - is mcr on */
#define OFF 0             /* OFF - is mcr off */

/*
 * Function that process an assembly file and process it using pre assembler.
 * The function write the output to .am file.
 * Parameters:
 * file - name of the assembly file without an extension.
 * Returns:
 * The function returns an error if it has encountered one, if not, NULL is returned.
 */
char* pre_assembler(char* file);