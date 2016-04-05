#include <stdio.h>

int main(int ac, char **av) {
  (void)(av); /* Prevents error from not using argument */
  printf("%d\n", ac - 1); /* Prints the number of args less the program */
  return 0;
}
