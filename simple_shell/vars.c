#include "hdr.h"

char *dollar_builtins(int status, char *argv, struct Stringlist *env)
/* Check for built-in $VARS */
{
        if (argv[1] == '?') {
                free(argv);
                return int_to_str(status);
        }

        return env_vars(argv, env);

}

int dollar_vars(int status, char **argv, struct Stringlist *env)
/* Checks for $VARS in array */
{
        int i;
        for (i = 0; argv[i] != NULL; i++) {
                if (argv[i][0] == '$') {
                        argv[i] = dollar_builtins(status, argv[i], env);
                        if (!argv[i]) {
                                return 1;
                        }
                }
        }
        return 0;
}

char *env_vars(char *argv, struct Stringlist *env)
/* Prints environment variables in env */
{
        int i;
        int len;

        len = str_len(argv);
        for (i = 0; i < len; i++) {
                if (i != len - 1)
                        argv[i] = argv[i + 1];
                else
                        argv[i] = '=';
        }
        while (env != NULL) {
                if (strn_compare(argv, env->str, len)) {
                        free(argv);
                        return trim_left(env->str, len);
                }
                env = env->next;
        }
        free(argv);
        return malloc_str("");
}
