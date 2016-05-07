#include <stdlib.h>
#include "param_struct.h"
#define SIZE(i) (sizeof(struct Param) * i)
typedef struct Param param;
#include <stdio.h>

char **string_split(char * str);

int string_length(char *str) {
  /* Finds the length of the string */
  int i;
  for (i = 0; str[i] != '\0'; i++);
  return i;
}

void copy_string(char *str, char *copy){
  int i;

  for (i = 0; str[i] != '\0'; i++) {
    copy[i] = str[i];
  }

  copy[i] = '\0';
}

struct Param *params_to_struct_array(int ac, char **av){
  param *array;
  int i;

  array = malloc(SIZE((ac + 1)));
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
