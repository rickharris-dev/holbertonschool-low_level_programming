#include "my_header.h"

void print_file_permissions(mode_t mode) {
  /* Function prints file type and permissions */
  PERM(S_IFDIR, 'd');
  PERM(S_IRUSR, 'r');
  PERM(S_IWUSR, 'w');
  PERM(S_IXUSR, 'x');
  PERM(S_IRGRP, 'r');
  PERM(S_IWGRP, 'w');
  PERM(S_IXGRP, 'x');
  PERM(S_IROTH, 'r');
  PERM(S_IWOTH, 'w');
  PERM(S_IXOTH, 'x');
  print_char('\n');
}
