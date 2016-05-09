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

List *find_last_node(List *list){
  if(list->next == NULL)
    return list;
  return find_last_node(list->next);
}

int add_node(List **list, char *str){
  List *last_node;
  List *node;

  /* Allocate memory for new node */
  node = malloc(sizeof(List));

  /* Add copy of string to node */
  node->str = copy_string(str);
  if (node->str == NULL) {
    return 1;
  }
  node->next = NULL;

  if (*list == NULL) {
    /* If list is NULL, sets equal to new node */
    *list = node;
  } else {
    /* Appends the new node to the end of the list */
    last_node = find_last_node(*list);
    last_node->next = node;
  }

  /* Return successful */
  return 0;
}
