#include "header.h"
#include <stdio.h>

void free_dl_list(List *list)
{
    List *next;

    /* Frees each item in the list */
    while(list != NULL) {
        next = list->next; /* Stores the next pointer */
        free(list->str); /* Frees the string memory */
        free(list); /* Frees the list structure memory */
        list = next; /* Moves to the next item */
    }
}
