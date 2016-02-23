char lowercase(char c)
{
  if(64 < c && c < 91) /* Check if is uppercase  letter */
    return(c + 32); /* Converts to lowercase */
  return c; /* Returns character to print */
}

