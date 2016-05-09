#include "my_header.h"

void print_string(char *str, int c){
  /* Prints each string in the list */
  int i;
  if (c != 0){
    print_char(',');
    print_char(' ');
  }
  for (i = 0; str[i] != '\0'; i++) {
    print_char(str[i]);
  }
}

void print_recursion(List *list, int c){
  /* Recurses through list to print each string */
  if (list == NULL){
    print_char('\n');
    return;
  }
  print_string(list->str, c);
  print_recursion(list->next, ++c);
}

void print_list(List *list) {
  /* Initializes list recursion for printing */
  print_recursion(list, 0);
}
