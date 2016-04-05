#include <stdio.h>

int main(int ac, char **av) {
  (void)(av);
  printf("%d\n", ac - 1);
  return 0;
}
