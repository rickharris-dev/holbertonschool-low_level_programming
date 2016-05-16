#include "hdr.h"

int int_len(int n)
/* Returns the number of digits in integer */
{
        int i;

        for (i = 0; n <= -1; i++) {
                n = n / 10;
        }
        return i;
}

char *int_to_str(int n)
/* Converts integer to string */
{
        int i;
        int len;
        int neg;
        char *str;
        if (n == 0) {
                return malloc_str("0");
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

int str_to_int(char *str)
/* Converts string to integer */
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
                        sign = sign * 1;
                else if (str[i] > '9' || str[i] < '0')
                        return 0;
                else
                        val = (val * 10) + (str[i] - '0');
        }
        return val * sign;
}
