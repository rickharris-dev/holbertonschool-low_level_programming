#include "my_header.h"

int string_len(char *str)
{
        int i;
        for (i = 0; str[i] != '\0'; i++);
        return i;
}

char *trim_left(char *str, int n)
{
        return &str[n];
}

char *concat_strings(char *first, char *second, char sep)
{
        int i;
        int len_one;
        int len_two;
        int sep_exists;
        char *str;

        len_one = string_len(first);
        len_two = string_len(second);
        sep_exists = 0;
        if (sep)
                sep_exists = 1;

        str = malloc(sizeof(char) * (len_one + len_two + 2));
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

int compare_strings(char *input, char *test)
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

int strn_compare(char *input, char *test, int n)
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
