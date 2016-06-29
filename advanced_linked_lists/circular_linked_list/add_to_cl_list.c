#include "header.h"

List *circular_list_link(List *first, List *last, List *new)
{
    if (first == NULL) {
        first = new; /* Links back to new if first */
        last = new;
    }
    last->next = new; /* Links last next to the new item */
    new->next = first; /* Links the new item to the first */
    return new; /* Returns the new item */
}

List *add_cl_list(List *list, char *str)
{
    List *first = NULL;
    List *new = NULL;
    List *last = NULL;

    new = malloc(sizeof(List)); /* Allocates memory for new list struct */
    if (new == NULL)
        return NULL;

    if (list) { /* Identifies the first and last list items */
        first = list;
        for (last = list; last->next != first; last = last->next);
    }

    new->str = strdup(str); /* Copies string into new list item */
    if (new->str == NULL)
        return NULL;

    return circular_list_link(first, last, new); /* Returns linked list */
}

int add_end_cl_list(List **list, char *str)
{
    List *new = NULL;

    new = add_cl_list(*list, str); /* Creates and links new item */
    if (new == NULL)
        return 1;
    if (*list == NULL) /* If first item, points list to new item */
        *list = new;
    return 0;
}

int add_begin_cl_list(List **list, char *str)
{
    List *new = NULL;

    new = add_cl_list(*list, str); /* Creates and links new item */
    if (new == NULL)
        return 1;
    *list = new; /* Points the list to the new item */
    return 0;
}
