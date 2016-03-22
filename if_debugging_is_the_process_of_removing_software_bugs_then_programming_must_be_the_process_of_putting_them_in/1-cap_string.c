char *cap_string(char *c)
{
  int i;
  for (i = 0; c[i] != '\0'; i++)
    if (c[i] > 96 && c[i] < 123)
      if (i == 0 || c[i-1] == ' ' || c[i-1] == '\t' || c[i-1] == '\n')
        c[i] -= 32; /* Capitalizes letters following whitespace & char 0 */
  return c;
}
