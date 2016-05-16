#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include "libshell.h"
#include <errno.h>
#define BUFFER_SIZE 1024

/* ------ chkbuiltins.c ------ */
int check_builtins(char *cmd, char **argv, char **env);

/* ------ chkpath.c ------ */
int check_file_exists(char *path);
int check_path(char *cmd, char **argv, char **env);
char *find_path(char **env);
char *find_program(char **paths, char *cmd);

/* ------ env.c ------ */
int print_env(char **env);

/* ------ execcmd.c ------ */
int exec_cmd(char *cmd, char **argv, char **env);

/* ------ exit.c ------ */
void exit_shell(char *val, char **argv);

/* ------ intfunc.c ------ */
int int_len(int n);
char *int_to_str(int n);
int str_to_int(char *str);

/* ------ memfunc.c ------ */
void free_array(char **arr);
char *malloc_str(char *str);

/* ------ prntfunc.c ------ */
int print_char(char c);
void write_string(char *str);

/* ------ shell.c ------ */
/* Program entry at main function */
int return_status(int status, char **argv);
int shell_prompt(int status, char **env);

/* ------ strfunc.c ------ */
char *concat_strings(char *first, char *second, char sep);
int str_compare(char *input, char *test);
int str_len(char *str);
int strn_compare(char *input, char *test, int n);
char *trim_left(char *str, int n);

/* ------ vars.c ------ */
char *dollar_builtins(int status, char *argv, char **env);
int dollar_vars(int status, char **argv, char **env);
char *env_vars(char *argv, char **env);
