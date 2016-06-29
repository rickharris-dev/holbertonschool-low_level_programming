#include "header.h"

List *array_to_dl_list(char **arr)
{
    int i;
    List *first = NULL;
    List *prev = NULL;
    List *next = NULL;

    for (i = 0; arr[i] != NULL; i++) {
        next = malloc(sizeof(List)); /* Allocate memory for new item */
        if (next == NULL)
            return NULL;

        if (first == NULL)
            first = next; /* Sets the new item as the first item */
        if (prev != NULL)
            prev->next = next; /* Points the prev item to the next */

        next->str = strdup(arr[i]); /* Copies string into linked list */
        next->prev = prev; /* Points the next item to the prev */
        next->next = NULL; /* Sets NULL item */
        prev = next; /* Sets up the for the next array item */
        next = NULL;
    }

    return first; /* Returns the first list item */
}
