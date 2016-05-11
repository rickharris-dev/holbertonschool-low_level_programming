#include "my_header.h"

int main(int ac, char **av) {
  /* Function prints stdin or files to stdout */
  int i;

  if (ac == 1) {
    if (print_stdin() == -1) /* Prints stdin to stdout */
      return -1;
  } else {
    for (i = 1; i < ac; i++) {
      if (print_file(av[i]) == -1) /* Prints files to stdout */
        return 1;
    }
  }
  return 0;
}
