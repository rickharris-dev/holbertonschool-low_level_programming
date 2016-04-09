#include <stdio.h> /*Required for printf() function */
#include <stdlib.h> /* Required for atoi() function */

int (*get_op_func(char c))(int, int); /* Prototype declaration */

int main(int c, char **v){
  int (*r)(int,int); /* Pointer to function variable declaration */

  if (c != 4)
    return 1; /* If not enough command line arguments, returns error */

  r = *get_op_func(*v[2]);
  if (*r == NULL)
    return 1; /* If function pointer is NULL, returns error */

  printf("%d\n", (*r)(atoi(v[1]), atoi(v[3]))); /* Prints returned integer */
  return 0; /* Returns sucessful */
}
