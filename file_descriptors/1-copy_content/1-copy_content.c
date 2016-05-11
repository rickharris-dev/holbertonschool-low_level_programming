#include "my_header.h"

int main(int ac, char **av) {
  /* Function opens, copies the content to new file, and closes the files */
  int fd;
  int copy_fd;

  if (ac != 3) /* Confirm there are three arguments */
    return 1;

  open_files(av[1], av[2], &fd, &copy_fd); /* Open the files */
  if (fd == -1 || copy_fd == -1)
    return 1;

  if (copy_file(fd, copy_fd) == -1) /* Copies the file */
    return 1;

  if (close_files(fd, copy_fd)  == -1) /* Close the files */
    return 1;

  return 0;
}
