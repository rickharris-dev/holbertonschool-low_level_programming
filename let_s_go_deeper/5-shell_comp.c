int compare_strings(char *s1, char *s2, int c, int w){
  if (*s2 == '*') /* Sets wildcard flag and advances s2 */
    return compare_strings(s1, ++s2, 0, 1);
  else if (*s1 == *s2 && *s1 != '\0') /* Advances char comparison */
    return compare_strings(++s1, ++s2, ++c, w);
  else if (*s1 != *s2 && w == 1)  /* If wildcard set, resets char after match */
    return compare_strings(s1 - (c + 1), s2 - c, 0, 1);
  else if (*s1 == *s2)  /* Returns 1 if strings match */
    return 1;
  return 0; /* Returns 0 if strings do not match */
}

int shell_comp(char *s1, char *s2) {
  return compare_strings(s1, s2, 0, 0);  /* Initializes recursion */
}
