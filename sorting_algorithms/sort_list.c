#include <stdio.h>
#include "list.h"
int node_cmp(List *node1, List *node2);

void sort_list(List **list, int (*cmp_func)(List *, List *))
{
        int i;
        List *ptr;
        char *str;
        int sorted = 0;

        /* Repeats until completely sorted */
        while(!sorted) {
                sorted = 1;
                ptr = *list;
                /* Passes through the linked list */
                for (i = 0; ptr->next != NULL; i++) {
                        if ((*cmp_func)(ptr, ptr->next) > 0) {
                                /* Swaps strings if out of order */
                                str = ptr->str;
                                ptr->str = ptr->next->str;
                                ptr->next->str = str;
                                sorted = 0;
                        }
                        ptr = ptr->next;
                }
        }
}
