#include "hdr.h"

char *dollar_builtins(int status, char *argv)
/* Check for built-in $VARS */
{
        if (argv[1] == '?') {
                free(argv);
                return int_to_str(status);
        }

        return argv;

}

char **dollar_vars(int status, char **argv, __attribute__((unused)) char **env)
/* Checks for $VARS in array */
{
        int i;
        for (i = 0; argv[i] != NULL; i++) {
                if (argv[i][0] == '$') {
                        argv[i] = dollar_builtins(status, argv[i]);
                        if (!argv[i])
                                return NULL;
                }
        }
        return argv;
}
