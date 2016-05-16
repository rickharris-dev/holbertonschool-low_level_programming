#include "hdr.h"

char *concat_strings(char *first, char *second, char sep)
/* Combines strings into one new string with separator */
{
        int i;
        int len_one;
        int len_two;
        int sep_exists;
        char *str;

        len_one = str_len(first);
        len_two = str_len(second);
        sep_exists = 0;
        if (sep)
                sep_exists = 1;

        str = malloc(sizeof(char) * (len_one + len_two + 2));
        if (!str) {
                return NULL;
        }
        for (i = 0; i < len_one; i++) {
                str[i] = first[i];
        }
        if (sep_exists)
                str[i] = sep;
        for (i = 0; i < len_two; i++) {
                str[len_one + sep_exists + i] = second[i];
        }
        str[len_one + sep_exists + i] = '\0';

        return str;
}

int str_compare(char *input, char *test)
/* Compares all chars in strings */
{
        int i;

        for (i = 0; input[i] != '\0'; i++) {
                if (input[i] != test[i])
                        return 0;
        }
        if (test[i] != '\0')
                return 0;
        return 1;
}

int str_len(char *str)
/* Returns number of chars in string */
{
        int i;
        for (i = 0; str[i] != '\0'; i++);
        return i;
}

int strn_compare(char *input, char *test, int n)
/* Compares n characters of strings */
{
        int i;

        for (i = 0;  input[i] != '\0' && i < n; i++) {
                if (input[i] != test[i])
                        return 0;
        }
        if (input[i] == '\0' && test[i] != '\0')
                return 0;
        return 1;
}

char *trim_left(char *str, int n)
/* Returns newly allocated string */
{
        int i;
        int len;
        char *new;

        len = str_len(str);
        new = malloc(sizeof(char) * (len + 1 - n));
        new[len - n] = '\0';
        for (i = 0; str[n + i] != '\0'; i++) {
                new[i] = str[n + i];
        }
        return new;
}
