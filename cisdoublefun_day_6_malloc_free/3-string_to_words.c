#include <stdlib.h>

int is_alphanumeric(char c) {
  /* Determines if the char is alphanumeric */
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return 1;
  else if (c >= '0' && c <= '9')
    return 1;
  return 0;
}

int get_string_count(char *s) {
  int c;
  int total;

  c = 0;
  total = 0;
  while (s[c] != '\0') {
    /* Counts each string start point */
    if (is_alphanumeric(s[c]) && (c == 0 || !is_alphanumeric(s[c - 1])))
      total++;
    c++;
  }
  return total;
}

int get_string_length(char *s, int c) {
  int l;

  l = 0;
  /* Counts the length of each alphanumeric string */
  while(is_alphanumeric(s[c])) {
    l++;
    c++;
  }
  return l;
}

void store_string(char *a, char *s, int c) {
  int i;

  i = 0;
  /* Stores each string into the corresponding array position */
  while (is_alphanumeric(s[c])) {
    a[i] = s[c];
    i++;
    c++;
  }
  a[i] = '\0';
  return;
}

char **string_to_words(char *s) {
  int c;
  int i;
  int l;
  int str_count;
  char ** array;

  c = 0;
  i = 0;
  str_count = get_string_count(s);
  if (str_count == 0) /* Returns NULL if no strings are found */
    return NULL;
  array = malloc(sizeof(char *) * (str_count + 1)); /* Creates array of str */
  while (s[c] != '\0') {
    if (is_alphanumeric(s[c]) && (c == 0 || !is_alphanumeric(s[c - 1]))) {
      l = get_string_length(s, c);
      array[i] = malloc(sizeof(char) * (l + 1)); /* Creates memory for string */
      store_string(array[i], s, c);
      i++;
    }
    c++;
  }
  array[str_count] = NULL; /* Closes array with NULL value */
  return array;
}
