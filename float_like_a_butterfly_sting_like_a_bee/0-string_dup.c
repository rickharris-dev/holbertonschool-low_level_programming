#include <stdlib.h>
#include <stdio.h>

char *string_dup(char *str){
  int i;
  char *s;

  s = malloc(sizeof(*s) * 10);
  if (s == NULL)
    return NULL;
  for(i = 0; str[i] != '\0'; i++)
    s[i] = str[i];
  s[i] = '\0';
  return s;
}
