#include "hdr.h"

int check_builtins(char *cmd, char **argv, struct Stringlist *env)
/* Checks if cmd matches a built-in func and executes func */
{
        if (str_compare(cmd, "exit")) {
                free_strlist(env);
                exit_shell(argv[1], argv);
        } else if (str_compare(cmd, "env")) {
                return print_env(env);
        } else if (str_compare(cmd, "cd")) {
                return change_directory(argv, env);
        } else if (str_compare(cmd, "setenv")) {
                return set_env(argv, env);
        } else if (str_compare(cmd, "unsetenv")) {
                return unset_env(argv, env);
        }
        return 0;
}
