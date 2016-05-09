#include "my_header.h"

void rev_list_recursion(List **list, List *curr, List *prev){
  /* Recurses through linked list to reverse connections */
  List *next;

  next = curr->next;
  curr->next = prev;
  if(next == NULL){
    *list = curr;
    return;
  }
  rev_list_recursion(list, next, curr);
}

void rev_list(List **list) {
  /* Initializes recursion to reverse linked list */
  rev_list_recursion(list, *list, NULL);
}
