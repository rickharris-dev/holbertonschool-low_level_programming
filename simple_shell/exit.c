#include "my_header.h"

int str_to_int(char *str)
/* Convert string to integer */
{
        int i;
        int val;
        int sign;

        sign = 1;
        val = 0;
        for (i = 0; str[i] != '\0'; i++) {
                if (str[i] == '-' && !val)
                        sign = sign * -1;
                else if (str[i] == '+' && !val)
                        sign = sign;
                else if (str[i] > '9' || str[i] < '0')
                        return 0;
                else
                        val = (val * 10) + (str[i] - '0');
        }
        return val * sign;
}

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
