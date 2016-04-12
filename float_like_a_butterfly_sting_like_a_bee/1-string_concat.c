#include <stdlib.h>

char *string_concat(char *s1, char *s2) {
  int i, l;
  char *s;

  for(i = 0; s1[i] != '\0'; i++);
  for(l = 0; s2[l] != '\0'; i++, l++);

  s = malloc(sizeof(*s) * ++i);
  if (s == NULL)
    return NULL;
  for(i = 0; s1[i] != '\0'; i++)
    s[i] = s1[i];
  for(l = 0; s2[l] != '\0'; i++, l++)
    s[i] = s2[l];
  s[i] = '\0';
  return s;
}
