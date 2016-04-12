#include <stdlib.h>
#include <stdio.h>

char *string_dup(char *str){
  int i;
  char *s;

  for(i = 0; str[i] != '\0'; i++);

  s = malloc(sizeof(*s) * ++i);
  if (s == NULL)
    return NULL;
  for(i = 0; str[i] != '\0'; i++)
    s[i] = str[i];
  s[i] = '\0';
  return s;
}
