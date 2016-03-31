int print_char(char c);

void print_string_half(char *str)
{
  int i,j;
  /* Find the length of the string */
  for (i = 0; *(str + i) != '\0'; i++);

  /* Determine char where last half begins and start loop */
  for (j = i / 2 + i % 2; j < i; j++)
    print_char(*(str + j)); /* Prints the selected char */
}
