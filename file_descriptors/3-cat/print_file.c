#include "my_header.h"

int print_file(char *file) {
  /* Function opens, sends to print, and closes each file */
  int fd;

  fd = open(file, O_RDONLY); /* Opens the file */
  if (fd == -1) {
    perror("open");
    return -1;
  }

  if (print_file_content(fd) == 1){ /* Prints the file */
    perror("read");
    return -1;
  }

  if (close(fd) == -1) { /* Close the file */
    perror("close");
    return -1;
  }
  return 0;
}
