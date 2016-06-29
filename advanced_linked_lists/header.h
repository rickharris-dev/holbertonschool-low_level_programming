#include <string.h>
#include <stdlib.h>
#include "list.h"
int print_char(char c);
void print_string(char *str);
int add_end_dl_list(List **list, char *str);
int add_begin_dl_list(List **list, char *str);
List *array_to_dl_list(char **);
void print_dl_list(List *list);
void free_dl_list(List *list);
int add_end_cl_list(List **list, char *str);
int add_begin_cl_list(List **list, char *str);
List *add_cl_list(List *list, char *str);
List *array_to_cl_list(char **array);
void print_cl_list(List *list);
void free_cl_list(List *list);
