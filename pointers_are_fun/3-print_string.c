int print_char(char c);

void print_string(char *str)
{
  int i;

  i = 0;
  /* Sets for loop to cycle through array of char */
  for(i = 0; *(str + i) > 0; i++){
    print_char(*(str + i)); /* Prints current char */
  }
}
