#include "my_header.h"

int main(int ac, char **av) {
  /* Function prints the permissions of a file */
  struct stat *data;

  data = malloc(sizeof(struct stat)); /* Allocate memory for stat struct */
  if (data == NULL) {
    perror("malloc");
    return 1;
  }

  if (ac != 2) /* Confirm there are two arguments */
    return 1;

  lstat(av[1], data); /* Get permissions of file or link */ 

  print_file_permissions(data->st_mode);
  free(data); /* Frees allocated memory */
  return 0;
}
