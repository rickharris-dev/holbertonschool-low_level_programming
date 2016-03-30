#include <stdio.h>

int compare_strings(char *s1, char *s2, int c, int w){
  if (*s2 == '*') /* Sets wildcard flag and advances s2 */
    return compare_strings(s1, ++s2, 0, 1);
  else if (*(s2 - 1) == '*' && *s1 != *s2 && *s1 != '\0')
    return compare_strings(++s1, s2, 0, w); /* Adv s1 to match after wildcard */
  else if (*s1 == *s2 && *s1 != '\0') /* Advances char comparison */
    return compare_strings(++s1, ++s2, ++c, w);
  else if (*s1 != *s2 && w == 1 && c > 0) /* If fail & wild set, resets char */
    return compare_strings(s1 + (1 - c), s2 - c, 0, 1);
  else if (*s1 == *s2)  /* Returns 1 if strings match */
    return 1;
  return 0; /* Returns 0 if strings do not match */
}

int shell_comp(char *s1, char *s2) {
  return compare_strings(s1, s2, 0, 0);  /* Initializes recursion */
}
