#include "header.h"

List *double_circular_link(List *first, List *last, List *new)
{
    if (first == NULL && last == NULL) {
        first = new;
        last = new;
    }
    first->prev = new;
    new->next = first;
    new->prev = last;
    last->next = new;
    return new;
}

List *add_dcl_list(List *list, char *str)
{
    List *first = NULL;
    List *new = NULL;
    List *last = NULL;

    new = malloc(sizeof(List));
    if (new == NULL)
        return NULL;

    if (list) {
        first = list;
        for (last = list; last->next != first; last = last->next);
    }

    new->str = strdup(str);
    if (new->str == NULL)
        return NULL;

    return double_circular_link(first, last, new);
}

int add_end_dcl_list(List **list, char *str)
{
    List *new = NULL;

    new = add_dcl_list(*list, str);
    if (new == NULL)
        return 1;
    if (*list == NULL)
        *list = new;
    return 0;
}

int add_begin_dcl_list(List **list, char *str)
{
    List *new = NULL;

    new = add_dcl_list(*list, str);
    if (new == NULL)
        return 1;
    *list = new;
    return 0;
}
