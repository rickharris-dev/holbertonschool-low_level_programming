#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "libshell.h"
#include "structs.h"
#define BUFFER_SIZE 1024

/* ------ chdir.c ------ */
int cd_no_input(struct Stringlist *env);
int change_directory(char **argv, struct Stringlist *env);
void convert_env_value(char *val, int len);
void convert_tilde(char **argv, struct Stringlist *env);
char *get_env_value(char *val, struct Stringlist *env);

/* ------ chkbuiltins.c ------ */
int check_builtins(char *cmd, char **argv, struct Stringlist *env);

/* ------ chkpath.c ------ */
int check_file_exists(char *path);
int check_path(char *cmd, char **argv, struct Stringlist *env);
char *find_path(struct Stringlist *env);
char *find_program(char **paths, char *cmd);

/* ------ env.c ------ */
int print_env(struct Stringlist *env);
int set_env(char **argv, struct Stringlist *env);
int unset_env(char **argv, struct Stringlist *env);

/* ------ execcmd.c ------ */
int exec_cmd(char *cmd, char **argv, struct Stringlist *env);

/* ------ exit.c ------ */
void exit_shell(char *val, char **argv);

/* ------ intfunc.c ------ */
int int_len(int n);
char *int_to_str(int n);
int str_to_int(char *str);

/* ------ listfunc.c ------ */
void free_strlist(struct Stringlist *list);
char ** list_to_strarr(struct Stringlist *list);
struct Stringlist *strarr_to_list(char **array);
int strlist_len(struct Stringlist *list);

/* ------ memfunc.c ------ */
void free_array(char **arr);
char *malloc_str(char *str);

/* ------ prntfunc.c ------ */
int print_char(char c);
void write_string(char *str);

/* ------ shell.c ------ */
/* Program entry at main function */
int get_arg_count(char **argv);
int return_status(int status, char **argv);
int process_cmd(int status, char **argv, struct Stringlist *env);
int shell_prompt(int status, struct Stringlist *env);

/* ------ specchar.c ------ */
void handle_comments(char **argv);

/* ------ strfunc.c ------ */
char *concat_strings(char *first, char *second, char sep);
int str_compare(char *input, char *test);
int str_len(char *str);
int strn_compare(char *input, char *test, int n);
char *trim_left(char *str, int n);

/* ------ vars.c ------ */
char *dollar_builtins(int status, char *argv, struct Stringlist *env);
int dollar_vars(int status, char **argv, struct Stringlist *env);
char *env_vars(char *argv, struct Stringlist *env);
