#include "my_header.h"

int open_files(char *orig, char *copy, int *fd, int *copy_fd) {
  /* Function opens orig and copy files */
  *fd = open(orig, O_RDONLY); /* Opens the orig file */
  if (*fd == -1) {
    perror("open");
    return 1;
  }
  umask(0); /* Prevents blocking of permissions */
  *copy_fd = open(copy, O_CREAT|O_RDWR|O_TRUNC, 00644); /* Open the copy file */
  if (*copy_fd == -1) {
    perror("open");
    return 1;
  }
  return 0;
}
