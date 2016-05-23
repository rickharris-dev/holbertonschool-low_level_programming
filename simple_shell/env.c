#include "hdr.h"

int print_env(struct Stringlist *env)
/* Prints each env value, one per line */
{
        while (env != NULL) {
                write_string(env->str);
                print_char('\n');
                env = env->next;
        }
        return 1;
}



int set_env(char **argv, struct Stringlist *env)
{
        char *str;
        struct Stringlist *new;

        while (env->next != NULL) {
                env = env->next;
        }

        new = malloc(sizeof(struct Stringlist));
        if (new == NULL) {
                perror("malloc");
                return -1;
        }
        env->next = new;
        str = concat_strings(argv[1], argv[2], '=');
        new->str = str;
        new->next = NULL;
        return 1;
}

int unset_env(char **argv, struct Stringlist *env)
{
        int i;
        int len;
        struct Stringlist *store;

        i = 0;
        len = str_len(argv[1]);
        while (env != NULL) {
                if (strn_compare(argv[1], env->str, len)) {
                        if (i == 0) {
                                free(env->str);
                                store = env->next;
                                env->str = store->str;
                                env->next = store->next;
                                free(store);
                        } else {
                                store->next = env->next;
                                free(env->str);
                                free(env);
                        }
                        return 1;
                }
                store = env;
                env = env->next;
                i++;
        }
        return -1;
}
