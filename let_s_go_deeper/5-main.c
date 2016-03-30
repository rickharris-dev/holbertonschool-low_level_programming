#include <stdio.h>

int shell_comp(char *s1, char *s2);

int main(void)
{
  int r;
  r = shell_comp("a", "a");
  if (r != 1)
    printf("a, a\n");
  r = shell_comp("aa", "a");
  if (r != 0)
    printf("aa, a\n");
  r = shell_comp("aaa", "a");
  if (r != 0)
    printf("aaa, a\n");
  r = shell_comp("a", "aa");
  if (r != 0)
    printf("a, aa\n");
  r = shell_comp("ab", "ab");
  if (r != 1)
    printf("ab, ab\n");
  r = shell_comp("abc", "*");
  if (r != 1)
    printf("abc, *\n");
  r = shell_comp("abc", "****");
  if (r != 1)
    printf("abc, ****\n");
  r = shell_comp("ab", "a*");
  if (r != 1)
    printf("ab, a*\n");
  r = shell_comp("ab", "*a");
  if (r != 0)
    printf("ab, *a\n");
  r = shell_comp("ab", "*c");
  if (r != 0)
    printf("ab, *c\n");
  r = shell_comp("ab", "*b");
  if (r != 1)
    printf("ab, *b\n");
  r = shell_comp("xyza", "*a");
  if (r != 1)
    printf("xyza, *a\n");
  r = shell_comp("main.c", "*m*a*i*n*.*c*");
  if (r != 1)
    printf("main.c, *m*a*i*n*.*c*\n");
  r = shell_comp("mainmain", "ma*");
  if (r != 1)
    printf("mainmain, ma*\n");
  r = shell_comp("inn", "*n");
  if (r != 1)
    printf("inn, *n\n");
  r = shell_comp("ma-main.c", "ma*in.c");
  if (r != 1)
    printf("ma-main.c, ma*in.c\n");
  r = shell_comp("imain.c", "ma*in.c");
  if (r != 0)
    printf("imain.c, ma*in.c\n");
  r = shell_comp("imain.c", "*in.c");
  if (r != 1)
    printf("imain.c, *in.c\n");
  r = shell_comp("b", "a*");
  if (r != 0)
    printf("b, a*\n");
  r = shell_comp("n.c", "*in.c");
  if (r != 0)
    printf("n.c, *in.c\n");
  r = shell_comp("b", "");
  if (r != 0)
    printf("b, ''\n");
  r = shell_comp("bb", "*ab");
  if (r != 0)
    printf("bb, *ab\n");
  r = shell_comp("ab", "*a");
  if (r != 0)
    printf("ab, *a\n");
  r = shell_comp("abb", "*ab");
  if (r != 0)
    printf("abb, *ab\n");
  printf("---------------------------\n");
  r = shell_comp("main.c", "*.c");
  if (r != 1)
    printf("main.c, *.c\n");
  r = shell_comp("main.c", "m*a*i*n*.*c*");
  if (r != 1)
    printf("main.c, m*a*i*n*.*c*\n");
  r = shell_comp("main.c", "main.c");
  if (r != 1)
    printf("main.c, main.c\n");
  r = shell_comp("main.c", "m*c");
  if (r != 1)
    printf("main.c, m*c\n");
  r = shell_comp("main.c", "ma********************************c");
  if (r != 1)
    printf("main.c, ma********************************c\n");
  r = shell_comp("main.c", "*");
  if (r != 1)
    printf("main.c, *\n");
  r = shell_comp("main.c", "***");
  if (r != 1)
    printf("main.c, ***\n");
  r = shell_comp("main.c", "m.*c");
  if (r != 0)
    printf("main.c, m.*c\n");
  r = shell_comp("main.c", "**.*c");
  if (r != 1)
    printf("main.c, **.*c\n");
  r = shell_comp("main-main.c", "ma*in.c");
  if (r != 1)
    printf("main-main.c, ma*in.c\n");
  return (0);
}
