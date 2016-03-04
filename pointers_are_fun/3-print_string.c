int print_char(char c);

void print_string(char *str)
{
  int i;

  i = 0;

  for(i = 0; *(str + i) > 0; i++){
    print_char(*(str + i));
  }
}
