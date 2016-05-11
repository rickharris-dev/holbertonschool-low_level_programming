#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#define BUFF_SIZE 1024
int print_stdin(void);
int print_file(char *file);
int print_file_content(int fd);
