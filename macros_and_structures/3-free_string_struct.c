#include <stdlib.h>
#include "str_struct.h"

void free_string_struct(struct String *str) {
  /* Function frees the allocation of memory for string and struct String */
  free(str->str);
  free(str);
}
