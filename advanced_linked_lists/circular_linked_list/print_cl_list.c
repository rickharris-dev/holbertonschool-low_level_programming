#include "header.h"

void print_cl_list(List *list)
{
    List *first = NULL;
    List *next = NULL;

    while (list != first) { /* Prints each list item */
        if (first == NULL)
            first = list;
        next = list->next; /* Sets the next item */
        print_string(list->str); /* Prints the current item's str */
        print_string("\n\t"); /* Prints new line and tab */
        if (next)
            print_string(next->str); /* Prints the next line string */
        else
            print_string("NULL"); /* Prints NULL if prev is NULL */
        print_char('\n'); /* Prints a new line character */
        list = next; /* Moves to the next item */
    }
}
