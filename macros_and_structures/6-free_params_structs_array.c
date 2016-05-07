#include "my_functions.h"

void free_tab_array(char **array){
  /* Function frees memory allocated in the tab section of struct */
  int l;
  for (l = 0; array[l] != NULL; l++);
  for (l = l - 1; l >= 0; l--){
    free(array[l]);
  }
  free(array);
}

int find_array_size(struct Param *array) {
  /* Function determines the number of structs in array */
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
