#include "hdr.h"

int cd_no_input(struct Stringlist *env)
/* Handles cd cmd with no input to return to home dir */
{
        int stat;
        char *tmp;
        char *new;

        stat = 0;
        tmp = malloc_str("$HOME");
        new = get_env_value(tmp, env);
        stat = chdir(new);
        free(new);
        return stat;
}

int change_directory(char **argv, struct Stringlist *env)
/* Updates argv for change directory requests */
{
        if (argv[1] == NULL || str_compare(argv[1], "~")) {
                if (cd_no_input(env)) {
                        perror("cd");
                        return -1;
                }
                return 1;
        } else if (argv[1][0] == '~') {
                convert_tilde(argv, env);
                if (chdir(argv[1])) {
                        perror("cd");
                        return -1;
                }
                return 1;
        } else {
                if (chdir(argv[1])) {
                        perror("cd");
                        return -1;
                }
                return 1;
        }
        return 0;
}

void convert_env_value(char *val, int len)
/* Converts $VAR to VAR= */
{
        int i;

        for (i = 0; i < len; i++) {
                if (i != len - 1)
                        val[i] = val[i + 1];
                else
                        val[i] = '=';
        }
}

void convert_tilde(char **argv, struct Stringlist *env)
/* Convert tilde to home path and concat strings */
{
        char *tmp;
        char *path;
        char *path2;

        tmp = malloc_str("$HOME");
        path = get_env_value(tmp, env);
        path2 = trim_left(argv[1], 1);
        free(argv[1]);
        argv[1] = concat_strings(path, path2, 0);
        free(path);
        free(path2);
}

char *get_env_value(char *val, struct Stringlist *env)
/* Returns the home path */
{
        int len;

        len = str_len(val);
        convert_env_value(val, len);
        while (env != NULL) {
                if (strn_compare(val, env->str, len)) {
                        free(val);
                        return trim_left(env->str, len);
                }
                env = env->next;
        }
        return malloc_str("");
}
