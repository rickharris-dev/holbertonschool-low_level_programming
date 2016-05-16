#include "hdr.h"

void free_array(char **arr)
/* Frees each array element and the array pointer */
{
        int i;
        for (i = 0; arr[i] != NULL; i++)
                free(arr[i]);
        free(arr);
}
