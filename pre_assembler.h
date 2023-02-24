#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
 * Function that process an assembly file and process it using pre assembler.
 * The function write the output to .am file.
 * Parameters:
 * file - name of the assembly file without an extension.
 * Returns:
 * The function returns an error if it has encountered one, if not, NULL is returned.
 */
char* pre_assembler(char* file);