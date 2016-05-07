#include "my_functions.h"

int number_length(int n){
  /* Function finds the number of digits in a number */
  int c;

  c = 0;
  if (n == 0)
    return 1;
  while(n >= 1) {
    n = n / 10;
    c++;
  }
  return c;
}

void print_number(int n){
  /* Function prints a number one digit at a time */
  int l;
  int ll;
  int d;
  char p;

  l = number_length(n);
  ll = l;
  d = 1;
  while (ll - 1 > 0){
    d = d * 10;
    ll--;
  }

  while (l > 0){
    p = '0' + (n / d);
    print_char(p);
    l--;
    n = n % d;
    d = d / 10;
  }
}

void print_string(char *str){
  /* Function prints a string */
  int i;
  for (i = 0; str[i] != '\0'; i++){
    print_char(str[i]);
  }
}

void print_array(char **array) {
  /* Function prints an array of strings */
  int i;

  for (i = 0; array[i] != NULL; i++) {
    if (i != 0){
      print_char(',');
      print_char(' ');
    }
    print_string(array[i]);
  }
}

void print_params_structs_array(struct Param *array){
  /* Function initializes the printing of each struct in array */
  int i;

  for (i = 0; array[i].str != NULL; i++) {
    print_string(array[i].str);
    print_char('\n');
    print_number(array[i].length);
    print_char('\n');
    print_array(array[i].tab);
    print_char('\n');
  }
}
