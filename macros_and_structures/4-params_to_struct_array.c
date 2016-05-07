#include "my_functions.h"

int string_length(char *str) {
  /* Finds the length of the string */
  int i;
  for (i = 0; str[i] != '\0'; i++);
  return i;
}

void copy_string(char *str, char *copy){
  /* Copies the string into newly allocated memory */
  int i;

  for (i = 0; str[i] != '\0'; i++) {
    copy[i] = str[i];
  }

  copy[i] = '\0';
}

struct Param *params_to_struct_array(int ac, char **av){
  /* Function sets up each argument into an array of structs */
  param *array;
  int i;

  array = malloc(sizeof(struct Param) * (ac + 1));
  if (array == NULL)
    return NULL;

  for (i = 0; i < ac; i++) {
    array[i].str = av[i];
    array[i].length = string_length(av[i]);
    array[i].copy = malloc(array[i].length + 1);
    if (array[i].copy == NULL)
      return NULL;
    copy_string(array[i].str, array[i].copy);
    array[i].tab = string_split(av[i]);
  }

  array[ac].str = NULL;

  return array;
}
