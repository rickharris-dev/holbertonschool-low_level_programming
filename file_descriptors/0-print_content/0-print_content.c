#include "my_header.h"

int main(int ac, char **av) {
  /* Function opens, sends to print, and closes file to be printed */
  int fd;

  if (ac != 2) /* Confirm there are two arguments */
    return 1;

  fd = open(av[1], O_RDONLY); /* Opens the file */
  if (fd == -1) {
    perror("open");
    return 1;
  }

  if (print_file(fd) == 1){ /* Prints the file */
    perror("read");
    return 1;
  }

  if (close(fd) == -1) { /* Close the file */
    perror("close");
    return 1;
  }

  return 0;
}
