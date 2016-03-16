char *nconcat_strings(char *dest, const char *src, int n)
{
  int i, j;
  /* Finds the length of the dest */
  for (i = 0; *(dest + i) != '\0'; i++);
  /* Adds n characters from the src string to the dest string */
  for (j = 0; *(src + j) != '\0' && j < n; i++, j++)
  {
    *(dest + i) = *(src + j);
  }
  *(dest + i + 1) = '\0';
  return dest;
}
