#include "header.h"

void free_cl_list(List *list)
{
    List *next = NULL;
    List *last = list;

    while (last->next != list) /* Finds last item in list */
        last = last->next;
    last->next = NULL; /* Breaks circular link */

    while (list != NULL) {
        next = list->next; /* Sets next item */
        free(list->str); /* Frees the string in list item */
        free(list); /* Frees the list item */
        list = next; /* Moves to the next item */
    }
}
