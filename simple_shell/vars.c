#include "my_header.h"

int int_len(int n)
{
        int i;

        for (i = 0; n <= -1; i++) {
                n = n / 10;
        }
        return i;
}

char *int_to_str(int n)
{
        int i;
        int len;
        int neg;
        char *str;
        if (n == 0) {
                str = malloc(sizeof(char) * 2);
                if (str == NULL)
                        return NULL;
                str[0] = '0';
                str[1] = '\0';
                return str;
        } else if (n < 0) {
                neg = 1;
        } else {
                neg = 0;
                n = n * -1;
        }
        len = int_len(n);
        str = malloc(sizeof(char) * (len + neg + 1));
        if (str == NULL)
                return NULL;
        str[len + neg] = '\0';
        for (i = 1; i <= len; i++) {
                str[len + neg - i] = '0' + (n % 10 * -1);
                n = n / 10;
        }
        if (neg)
                str[0] = '-';
        return str;
}

char *dollar_builtins(int status, char *argv)
{
        if (argv[1] == '?') {
                free(argv);
                return int_to_str(status);
        }

        return argv;

}

char **dollar_vars(int status, char **argv, __attribute__((unused)) char **env)
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
