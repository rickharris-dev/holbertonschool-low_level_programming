#include "hdr.h"

void exit_shell(char *val, char **argv)
/* Exits the shell with the given value */
{
        int code;

        if (val) {
                code = str_to_int(val);
                free_array(argv);
                exit(code);
        }
        exit(0);
}
