#include "my_header.h"

void remove_recursion(List **list, List *curr, List *prev, int index, int i){
  /* Identifies if at index and removes if true */
  if (index == i){
    if(index == 0)
      *list = curr->next;
    else
      prev->next = curr->next;
    free(curr->str);
    free(curr);
    return;
  } else if (curr == NULL) {
    /* If index is larger than the list, returns */
    return;
  }
  /* Continues recursion */
  remove_recursion(list, curr->next, curr, index, ++i);
}

void remove_from_list(List **list, int index){
  /* Initializes recursion to remove node at index */
  remove_recursion(list, *list, NULL, index, 0);
}
