#include "header.h"

void free_dcl_list(List *list)
{
    List *next = NULL;
    List *last = list;

    while (last->next != list)
        last = last->next;
    list->prev = NULL;
    last->next = NULL;

    while (list != NULL) {
        next = list->next;
        free(list->str);
        free(list);
        list = next;
    }
}
