#include <stdlib.h>

int get_length(int n, int is_n) {
  int i;
  if (n == 0)
    return 1;
  for (i = 0;n < 0 && n <= -1; n = n / 10, i++);
  return i + is_n;
}

char *convert_to_string(int n, int l, int is_n) {
  char * str;
  int i, r;

  str = malloc(sizeof(char) * (l));

  if (is_n)
    str[0] = '-';
  str[l] = '\0';
  l--;
  for (i = is_n; i <= l; l--){
    r = n % 10 * -1;
    str[l] = '0' + r;
    n = n / 10;
  }
  return str;
}

char *int_to_string(int n) {
  int l, is_negative;

  if (n < 0)
    is_negative = 1;
  else
    n = n * -1;

  l = get_length(n, is_negative);
  return convert_to_string(n, l, is_negative);
}
