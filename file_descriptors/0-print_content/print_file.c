#include "my_header.h"

int print_file(int fd){
  /* Function prints the content of the given file */
  int bytes;
  char buffer[BUFF_SIZE];

  bytes = BUFF_SIZE;

  while (bytes == BUFF_SIZE) {
    bytes = read(fd, buffer, BUFF_SIZE); /* Read the content of the file */
    if (bytes == -1)
      return 1;

    write(1, buffer, bytes); /* Writes the buffer to stdout */
  }
  return 0;
}
