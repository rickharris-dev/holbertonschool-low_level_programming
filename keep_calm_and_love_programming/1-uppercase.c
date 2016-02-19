char uppercase(char c)
{
  if(96 < c && c < 123)
    return(c - 32);
  return c;
}
