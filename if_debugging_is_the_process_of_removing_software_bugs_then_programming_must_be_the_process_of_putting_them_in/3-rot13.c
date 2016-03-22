char *rot13(char *c)
{
  int i;
  for (i = 0; c[i] != '\0'; i++)
  {
    if((c[i] > 64 && c[i] < 78) || (c[i] > 96 && c[i] < 110))
      c[i] += 13; /* If in 1st half of alphabet, adds 13 to value */
    else if ((c[i] > 77 && c[i] < 91) || (c[i] > 109 && c[i] < 123))
      c[i] -= 13; /* If in last half of alphabet, subtracts 13 from value */
  }
  return c; /* Returns the string */
}
