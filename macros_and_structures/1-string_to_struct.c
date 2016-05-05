#include "str_struct.h"
#include <stdlib.h>

int string_length(char *str) {
  /* Finds the length of the string */
  int i;
  for (i = 0; str[i] != '\0'; i++);
  return i;
}

struct String *string_to_struct(char *str) {
  /* Stores a string and its length in a newly allocated structure */
  struct String *string;
  int i;
  int l;

  l = string_length(str);
  string = malloc(sizeof(struct String));
  string->str = malloc(l + 1);
  string->length = l;

  for (i = 0; str[i] != '\0'; i++){
    string->str[i] = str[i];
  }

  string->str[l] = '\n';

  return string;
}
