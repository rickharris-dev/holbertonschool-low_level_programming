#include "header.h"

void free_cl_list(List *list)
{
    List *next = NULL;
    List *last = list;

    while (last->next != list)
        last = last->next;
    last->next = NULL;

    while (list != NULL) {
        next = list->next;
        free(list->str);
        free(list);
        list = next;
    }
}
