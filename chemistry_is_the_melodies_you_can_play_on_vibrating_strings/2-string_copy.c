char *string_copy(char *dest, const char *src)
{
  int i;

  /* Store source string into dest including '\0' */
  for (i = 0; *(src + i) != '\0'; i++)
    *(dest + i) = *(src + i);
  /* Add null terminator */
  *(dest + i + 1) = '\0';
  /* Return address of the dest string */
  return dest;
}
