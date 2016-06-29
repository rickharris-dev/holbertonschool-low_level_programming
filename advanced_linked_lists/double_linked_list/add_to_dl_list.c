#include "header.h"
#include <stdio.h>

int add_end_dl_list(List **list, char *str)
{
    List *new = NULL;
    List *prev = *list;

    new = malloc(sizeof(List)); /* Create the new list item */
    if (new == NULL)
        return 1;

    new->str = strdup(str); /* Set the string for the new list item */
    if (new->str == NULL)
        return 1;
    new->next = NULL; /* Set the next pointer for the new list item */

    if (prev != NULL) {
        while (prev->next != NULL) /* Point to last item in current list */
            prev = prev->next;
        prev->next = new; /* Set the next pointer for prev */
        new->prev = prev; /* Set the prev pointer for the new list item */
    } else {
        *list = new; /* Set the list pointer if prev is NULL */
        new->prev = NULL; /* Sets the prev point for new list item if NULL */
    }
    return 0;
}

int add_begin_dl_list(List **list, char *str)
{
    List *new = NULL;
    List *curr = NULL;

    new = malloc(sizeof(List)); /* Create the new list item */
    if (new == NULL)
        return 1;

    if (*list) {
        curr = *list; /* Point to the beginning of the list */
        while (curr->prev) /* Moves to start of list */
            curr = curr->prev;
        curr->prev = new; /* Point prev on list to new */
    }

    new->str = strdup(str); /* Copy the string into the new item */
    if (new->str == NULL)
        return 1;
    new->prev = NULL; /* Set prev for the new item to NULL */
    new->next = curr; /* Set next to start of list */
    *list = new; /* Update list to point to the new item */
    return 0;
}
