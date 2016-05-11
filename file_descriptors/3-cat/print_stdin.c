#include "my_header.h"

int print_stdin(void) {
  /* Function prints stdin to stdout */
  int bytes;
  char buffer[BUFF_SIZE];

  while(bytes != 0) {
    bytes = read(0, buffer, BUFF_SIZE); /* Read the content of stdin */
    if (bytes == -1)
      return -1;
    write(1, buffer, bytes); /* Writes the buffer to stdout */
  }
  return 0;
}
