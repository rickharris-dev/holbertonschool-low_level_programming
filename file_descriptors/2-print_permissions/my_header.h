#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#define PERM(a,b) ( (mode & a) ? print_char(b) : print_char('-') )
void print_file_permissions(mode_t mode);
int print_char(char c);
