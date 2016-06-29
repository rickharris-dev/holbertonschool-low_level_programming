#include "header.h"

void print_dcl_list(List *list)
{
    List *first = NULL;
    List *next = NULL;
    List *prev = NULL;

    while (list != first) { /* Prints each list item */
        if (first == NULL)
            first = list;
        next = list->next; /* Sets the next item */
        prev = list->prev; /* Sets the prev item */
        print_string(list->str); /* Prints the current item's str */
        print_string("\n\t"); /* Prints new line and tab */
        if (prev != NULL)
            print_string(prev->str); /* Prints the prev line string */
        else
            print_string("NULL"); /* Prints NULL if prev is NULL */
        print_string("\n\t"); /* Prints new line and tab */
        if (next != NULL)
            print_string(next->str); /* Prints the next line string */
        else
            print_string("NULL"); /* Prints NULL if prev is NULL */
        print_char('\n'); /* Prints a new line character */
        list = next; /* Moves to the next item */
    }
}
