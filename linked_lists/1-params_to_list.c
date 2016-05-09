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

  node = malloc(sizeof(List)); /* Allocate memory for new node */
  if (node == NULL)
    return 1;

  node->str = copy_string(str); /* Add copy of string to node */
  if (node->str == NULL) {
    return 1;
  }
  node->next = NULL;

  if (*list == NULL) {
    *list = node; /* If list is NULL, sets equal to new node */
  } else {
    last_node = find_last_node(*list); /* Appends the new node to the end */
    last_node->next = node;
  }

  return 0; /* Return successful */
}

List *params_to_list(int ac, char **av) {
  List *list;
  int i;

  list = NULL;
  for (i = 0; i < ac; i++) {
    if (add_node(&list, av[i]) == 1)
      return NULL;
  }
  return list;
}
