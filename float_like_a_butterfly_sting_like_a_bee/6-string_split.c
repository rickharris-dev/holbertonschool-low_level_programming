#include <stdlib.h>

int is_printable(char c){
  if (c == ' ' || c == '\0')
    return 0;
  return 1;
}

int find_len_or_loc(char * str, int req){
  int c, l;

  for(l = 0, c = 0; str[l] != '\0'; l++) {
    if(is_printable(str[l]) && !(is_printable(str[l-1])))
      ++c;
    if (c != 0 && c == req)
      return l;
  }
  return c;
}

int length_of_string(char * str, int loc) {
  int i;
  for(i = 0; is_printable(str[loc]); i++, loc++);
  return i;
}

char **string_split(char * str){
  char ** array;
  int c, i, j;

  c = find_len_or_loc(str, 0);
  array = malloc(sizeof(char *) * (c + 1));
  for (i = 0; i < c; i++){
    int len, loc;
    loc = find_len_or_loc(str, i + 1);
    len = length_of_string(str, loc);
    array[i] = malloc(sizeof(char) * (len + 1));
    for (j = 0; j < len; j++)
      array[i][j] = str[loc + j];
    array[i][len] = '\0';
  }
  array[c + 1] = NULL;
  return array;
}
