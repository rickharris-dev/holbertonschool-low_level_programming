#include <stdlib.h>

char *string_nconcat(char *s1, char *s2, int n){
  int i, l;
  char *s;

  for(i = 0; s1[i] != '\0'; i++);
  for(l = 0; s2[l] != '\0'; l++);
  if (l < n)
    i = i + l;
  else
    i = i + n;

  s = malloc(sizeof(*s) * ++i);
  if (s == NULL)
    return NULL;
  for(i = 0; s1[i] != '\0'; i++)
    s[i] = s1[i];
  for(l = 0; s2[l] != '\0' && l < n; i++, l++)
    s[i] = s2[l];
  s[i] = '\0';
  return s;
}
