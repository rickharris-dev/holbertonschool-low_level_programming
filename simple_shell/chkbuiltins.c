#include "hdr.h"

int check_builtins(char *cmd, char **argv, char **env)
/* Checks if cmd matches a built-in func and executes func */
{
        if (str_compare(cmd, "exit")) {
                int code;
                if (argv[1])
                        code = str_to_int(argv[1]);
                else
                        code = 0;
                free_array(argv);
                exit(code);
        } else if (str_compare(cmd, "env")) {
                return print_env(env);
        } else if (str_compare(cmd, "cd")) {
                return change_directory(argv, env);
        }
        return 0;
}
