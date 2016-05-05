#include "str_struct.h"

int print_char(char c);

int get_divisor (int l) {
  /* Function creates a divisor to isolate each digit */
  int d;

  d = 1;
  while (l - 1 > 0){
    d = d * 10;
    l--;
  }
  return d;
}

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
  int d;
  char p;

  l = number_length(n);
  d = get_divisor(l);
  while (l > 0){
    p = '0' + (n / d);
    print_char(p);
    l--;
  }
}

void print_string(char *str){
  /* Function prints a string */
  int i;
  for (i = 0; str[i] != '\0'; i++){
    print_char(str[i]);
  }
}

void print_string_struct(struct String *str){
  /* Function that prints the content of a struct String */
  print_string(str->str);
  print_char(',');
  print_char(' ');
  print_number(str->length);
  print_char('\n');
}
