#include "my_header.h"

int close_files(int fd, int copy_fd) {
  if (close(fd) == -1) /* Close the orig file */
    return -1;
  if (close(copy_fd) == -1) /* Close the copy file */
    return -1;
  return 0;
}
