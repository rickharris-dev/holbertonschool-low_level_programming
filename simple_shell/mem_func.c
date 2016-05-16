#include "my_header.h"

void free_array(char **arr)
{
        int i;
        for (i = 0; arr[i] != NULL; i++)
                free(arr[i]);
        free(arr);
}
