char uppercase(char c)
{
  if(96 < c && c < 123) /* Check if is lowercase letter */
    return(c - 32); /* Converts to uppercase */
  return c; /* Returns character to print */
}
