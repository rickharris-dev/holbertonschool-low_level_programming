#ifndef _LIST_H_
#define _LIST_H_

typedef struct List {
  char *str;
  struct List *prev;
  struct List *next;
} List;

#endif
