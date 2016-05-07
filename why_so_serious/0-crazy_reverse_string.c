#include <stdio.h>
#include <string.h>

int string_len(char *s)
{
     int l;

     l = 0;
     while (*s)
     {
          s++;
          l++;
     }
     return (l);
}

/* reverse a string
 * works for any string of size 0 to INT_MAX - 1
 */
void crazy_reverse_string(char *s)
{
     int l;
     int i;
     /* you are not allowed to declare new variables */

     l = string_len(s);
     i = 0;
     while (i < l / 2)
     {
          /* your code goes here only */
          /* you can only use s, l and i to complete the task */
          s[l] = s[i];
          s[i] = s[l - i - 1];
          s[l - i - 1] = s[l];
          s[l] = '\0';
          i++;
     }
}

int main(void)
{
     char *s;

     s = strdup("Hello Holberton! \\o/ #cisfun"); /* This is an example, but it should work for any string */
     printf("Before: %s\n", s);
     crazy_reverse_string(s);
     printf("After: %s\n", s);
     return (0);
}
