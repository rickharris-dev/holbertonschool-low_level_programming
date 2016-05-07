#include <stdlib.h>
#include "param_struct.h"
#define SIZE(i) (sizeof(struct Param) * i)
#include <stdio.h>
typedef struct Param param;

void free_tab_array(char **array){
  int l;
  for (l = 0; array[l] != NULL; l++);
  for (l = l - 1; l >= 0; l--){
    free(array[l]);
  }
  free(array);
}

int find_array_size(struct Param *array) {
  int l;
  for (l = 0; array[l].str != NULL; l++);
  return l;
}

void free_params_structs_array(struct Param *array) {
  /* Function frees the allocation of memory for all array allocations */
  int l;

  l = find_array_size(array) - 1;
  while(l >= 0) {
    free_tab_array(array[l].tab);
    free(array[l].copy);
    l--;
  }
  free(array);
}
