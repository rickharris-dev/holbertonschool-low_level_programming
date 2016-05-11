#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#include <sys/stat.h>
#define BUFF_SIZE 1000
int open_files(char *orig, char *copy, int *fd, int *copy_fd);
int copy_file(int fd, int copy_fd);
int close_files(int fd, int copy_fd);
