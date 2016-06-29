#include "header.h"

List *double_circular_link(List *first, List *last, List *new)
{
    if (first == NULL && last == NULL) {
        first = new; /* If first item sets new as first and last */
        last = new;
    }
    first->prev = new; /* Links first prev to the new item */
    new->next = first; /* Links new back to first */
    new->prev = last; /* Links new prev back to last */
    last->next = new; /* Links last next to the new item */
    return new;
}

List *add_dcl_list(List *list, char *str)
{
    List *first = NULL;
    List *new = NULL;
    List *last = NULL;

    new = malloc(sizeof(List)); /* Creates new list item */
    if (new == NULL)
        return NULL;

    if (list) { /* Finds first and last items in list */
        first = list;
        for (last = list; last->next != first; last = last->next);
    }

    new->str = strdup(str); /* Copies string into the new item */
    if (new->str == NULL)
        return NULL;

    /* Returns the new item once linked */
    return double_circular_link(first, last, new);
}

int add_end_dcl_list(List **list, char *str)
{
    List *new = NULL;

    new = add_dcl_list(*list, str); /* Creates and links the new item */
    if (new == NULL)
        return 1;
    if (*list == NULL) /* If first item points the list to it */
        *list = new;
    return 0;
}

int add_begin_dcl_list(List **list, char *str)
{
    List *new = NULL;

    new = add_dcl_list(*list, str); /* Creates and links the new item */
    if (new == NULL)
        return 1;
    *list = new; /* Points the list to the new item */
    return 0;
}
