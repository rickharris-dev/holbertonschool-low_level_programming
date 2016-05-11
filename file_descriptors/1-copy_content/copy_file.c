#include "my_header.h"

int copy_file(int fd, int copy_fd) {
  /* Function reads the orig file and copies into copy file */
  int bytes;
  char buffer[BUFF_SIZE];

  bytes = BUFF_SIZE;

  while (bytes == BUFF_SIZE) {
    bytes = read(fd, buffer, BUFF_SIZE); /* Reads file */
    if (bytes == -1) {
      perror("read");
      return -1;
    }

    if (write(copy_fd, &buffer, bytes) == -1) { /* Writes file */
      perror("write");
      return -1;
    }
  }
  return 0;
}
