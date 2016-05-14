#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include "libshell.h"
#define BUFFER_SIZE 1024
int compare_strings(char *input, char *test);
int strn_compare(char *input, char *test, int n);
char *concat_strings(char *first, char * second, char sep);
int string_len(char *str);
void write_string(char *str);
char *trim_left(char *str, int n);
void shell_prompt(char **env);
int process_input(char *input, char **env);
int check_builtins(char *cmd, char **env);
int check_path(char *cmd, char **argv, char **env);
int get_arg_count(char **argv);
int print_char(char c);
int find_cmd(char *cmd, char *path, char **argv, char **env);
int exec_program(char *cmd, char **argv, char **env);
