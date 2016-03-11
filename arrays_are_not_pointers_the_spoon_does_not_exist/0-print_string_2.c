int print_char(char c);

void print_string_2(char *str){
  int i, j;
  //Gets the length of the string
  for (i = 0; *(str + i) != '\0'; i++){}
  //Prints every other character starting with the first
  for (j = 0; j < i; j+=2)
    print_char(*(str + j));
}
