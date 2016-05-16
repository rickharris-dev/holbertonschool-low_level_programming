#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include "libshell.h"
#include <errno.h>
#define BUFFER_SIZE 1024

/* ------ simple_shell.c ------ */
/* Program entry at main function */
int shell_prompt(int status, char **env);
int get_arg_count(char **argv);

/* ------ check_builtins.c ------ */
int check_builtins(char *cmd, char **argv, char **env);

/* ------ check_path.c ------ */
int check_path(char *cmd, char **argv, char **env);
char *find_path(char **env);
char *find_program(char **paths, char *cmd);
int check_file_exists(char *path);

/* ------ exit.c ------ */
void exit_shell(char *val, char **argv);
int str_to_int(char *str);

/* ------ env.c ------ */
int print_env(char **env);

/* ------ exec_program.c ------ */
int exec_program(char *cmd, char **argv, char **env);

/* ------ string_functions.c ------ */
int strn_compare(char *input, char *test, int n);
int compare_strings(char *input, char *test);
char *concat_strings(char *first, char *second, char sep);
char *trim_left(char *str, int n);
int string_len(char *str);

/* ------ vars.c ------ */
char **dollar_vars(int status, char **argv, __attribute__((unused)) char **env);
char *dollar_builtins(int status, char *argv);
char *int_to_str(int n);
int int_len(int n);

/* ------ write_functions.c ------ */
void write_string(char *str);
int print_char(char c);

/* ------ mem_func.c ------ */
void free_array(char **arr);
