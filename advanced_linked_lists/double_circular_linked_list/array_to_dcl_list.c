#include "header.h"

List *array_to_dcl_list(char **array)
{
    int i;
    List *new = NULL;
    List *list = NULL;

    for (i = 0; array[i] != NULL; i++) {
        new = add_dcl_list(list, array[i]); /* Creates a new list item */
        if (i == 0)
            list = new; /* If first, points list to the item */
    }
    return list;
}
