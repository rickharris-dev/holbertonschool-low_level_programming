#include "header.h"

void free_dcl_list(List *list)
{
    List *next = NULL;
    List *last = list;

    while (last->next != list) /* Finds last item */
        last = last->next;
    list->prev = NULL; /* Breaks the circular link */
    last->next = NULL;

    while (list != NULL) {
        next = list->next; /* Sets the next item */
        free(list->str); /* Frees the string */
        free(list); /* Frees the list */
        list = next; /* Moves to the next item */
    }
}
