#include "my_header.h"

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
