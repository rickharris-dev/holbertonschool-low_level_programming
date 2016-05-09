#include "my_header.h"

int find_size(List *list, int i){
  /* Recurses to the end of the list to find the size */
  if (list == NULL)
    return i;
  return find_size(list->next, ++i);
}

int list_size(List *list) {
  /* Initializes recursion through the list */
  return find_size(list, 0);
}
