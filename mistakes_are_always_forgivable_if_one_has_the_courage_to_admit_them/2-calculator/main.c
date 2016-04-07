#include <stdio.h>
#include <stdlib.h>

int (*get_op_func(char c))(int, int);

int main(int c, char **v){
  if (c != 4 || *get_op_func(*v[2]) == (NULL))
    return 1;
  printf("%d\n", (*get_op_func(*v[2]))(atoi(v[1]), atoi(v[3])));
  return 0;
}
