int str_len(char *s)
{
  int i;

  for(i = 0; *(s + i) > 0; i++){}

  return (i);
}

void reverse_string(char *s)
{
    int i,j,len;
    char c;
    len = str_len(s);

    for (i = 0, j = len - 1; i < ((len - 1) / 2); i++, j--)
    {
      c = *(s + i);
      *(s + i) = *(s + j);
      *(s + j) = c;
    }
}
