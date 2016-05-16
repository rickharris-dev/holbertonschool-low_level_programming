#include "my_header.h"

int print_env(char **env)
/* Prints each env value, one per line */
{
        int i;
        for (i = 0; env[i] != NULL; i++) {
                write_string(env[i]);
                print_char('\n');
        }
        return 1;
}
