char *concat_strings(char *dest, const char *src)
{
  int i, j;
  /* Finds the length of the dest */
  for (i = 0; *(dest + i) != '\0'; i++);
  /* Adds the src string to the dest string */
  for (j = 0; *(src + j) != '\0'; i++, j++)
  {
    *(dest + i) = *(src + j); /* Appends src to dest */
  }
  *(dest + i + 1) = '\0'; /* Applies null terminator */
  return dest;
}
