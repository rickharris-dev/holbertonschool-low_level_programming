#include "my_header.h"

int insert_recursion(List **list, List *node, List *curr, int index, int i) {
  /* Recurses to index point and inserts the new node */
  if (i < index && curr->next != NULL)
    return insert_recursion(list, node, curr->next, index, ++i);
  if (index == -1){
    node->next = curr;
    *list = node;
    return 0;
  }
  node->next = curr->next;
  curr->next = node;
  return 0;
}

int insert_in_list(List **list, char *content, int index){
  /* Creates new node and initializes recursion to insert at index */
  List *node;

  node = malloc(sizeof(List));
  if (node == NULL)
    return 1;

  if (index < 0)
    return 0;

  node->str = copy_string(content);
  if (node->str == NULL)
    return 1;

  return insert_recursion(list, node, *list, index - 1, 0);
}
