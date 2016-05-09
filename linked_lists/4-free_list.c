#include "my_header.h"

void free_list(List *list) {
  /* Recurses through list to free memory */
  List *next;

  next = list->next;
  free(list->str);
  free(list);
  if (next == NULL)
    return;
  free_list(next);
}
