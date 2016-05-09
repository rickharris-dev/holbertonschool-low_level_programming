#include "my_header.h"

int string_length(char *str) {
  /* Finds the length of the string. */
  int l;

  for(l = 0; str[l] != '\0'; l++);

  return l + 1;
}

char *copy_string(char *str){
  /* Copies string into newly allocated memory. */
  char * copy;
  int i;
  int l;

  l = string_length(str);
  copy = malloc(sizeof(char) * l);
  if (copy == NULL){
    return NULL;
  }
  for (i = 0; i < l; i++){
    copy[i] = str[i];
  }

  return copy;
}

int add_node(List **list, char *str){
  List *node;

  /* Allocate memory for new node */
  node = malloc(sizeof(List));

  /* Add copy of string to node */
  node->str = copy_string(str);
  if (node->str == NULL) {
    return 1;
  }

  /* Set new node next pointer to current first on list (if exists) */
  if (*list == NULL) {
    node->next = NULL;
  } else {
    node->next = *list;
  }
  /* Point list to point to new node */
  *list = node;

  /* Return successful */
  return 0;

}
