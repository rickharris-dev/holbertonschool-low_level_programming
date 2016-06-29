#include "header.h"

List *add_cl_list(List *list, char *str)
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
        first->prev = new;
        last->next = new;
    } else {
        first = new;
        last = new;
    }
    new->str = strdup(str);
    if (new->str == NULL)
        return NULL;
    new->next = first;
    new->prev = last;
    return new;
}

int add_end_cl_list(List **list, char *str)
{
    List *new = NULL;

    new = add_cl_list(*list, str);
    if (new == NULL)
        return 1;
    if (*list == NULL)
        *list = new;
    return 0;
}

int add_begin_cl_list(List **list, char *str)
{
    List *new = NULL;

    new = add_cl_list(*list, str);
    if (new == NULL)
        return 1;
    *list = new;
    return 0;
}
