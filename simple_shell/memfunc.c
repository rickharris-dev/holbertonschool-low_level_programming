#include "hdr.h"

void free_array(char **arr)
/* Frees each array element and the array pointer */
{
        int i;
        for (i = 0; arr[i] != NULL; i++)
                free(arr[i]);
        free(arr);
}

char *malloc_str(char *str)
/* Allocates memory for new string */
{
        int i;
        int len;
        char *new;

        len = str_len(str);
        new = malloc(sizeof(char) * (len + 1));
        new[len] = '\0';
        for (i = 0; str[i] != '\0'; i++)
                new[i] = str[i];
        return new;
}
