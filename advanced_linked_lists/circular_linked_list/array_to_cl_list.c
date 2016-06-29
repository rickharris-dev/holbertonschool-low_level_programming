#include "header.h"

List *array_to_cl_list(char **array)
{
    int i;
    List *new = NULL;
    List *list = NULL;

    for (i = 0; array[i] != NULL; i++) {
        new = add_cl_list(list, array[i]); /* Creates and links new item */
        if (i == 0)
            list = new; /* If first, points list to new item */
    }

    return list;
}
