#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int add_end_dl_list(List **, char *);
int add_begin_dl_list(List **, char *);
void print_dl_list(List *);
void free_dl_list(List *list);

int main(void)
{
  List *list;

  list = NULL;
  if (add_end_dl_list(&list, "Holberton") == 1 ||
      add_end_dl_list(&list, "School") == 1 ||
      add_end_dl_list(&list, "Full") == 1 ||
      add_end_dl_list(&list, "Stack") == 1 ||
      add_end_dl_list(&list, "Engineer") == 1)
    return (1);
  printf("FIRST EXAMPLE:\n");
  print_dl_list(list);
  free_dl_list(list);
  list = NULL;
  if (add_begin_dl_list(&list, "Holberton") == 1 ||
      add_begin_dl_list(&list, "School") == 1 ||
      add_begin_dl_list(&list, "Full") == 1 ||
      add_begin_dl_list(&list, "Stack") == 1 ||
      add_begin_dl_list(&list, "Engineer") == 1)
    return (1);
  printf("SECOND EXAMPLE:\n");
  print_dl_list(list);
  free_dl_list(list);
  return (0);
}
/*
#include <stdlib.h>
#include "list.h"

List *array_to_dl_list(char **);
void print_dl_list(List *);
void free_dl_list(List *);

int main(__attribute__((unused))int ac, char **av)
{
  List *list;

  list = array_to_dl_list(av);
  if (list == NULL)
    return (1);
  print_dl_list(list);
  free_dl_list(list);
  return (0);
}
*/
