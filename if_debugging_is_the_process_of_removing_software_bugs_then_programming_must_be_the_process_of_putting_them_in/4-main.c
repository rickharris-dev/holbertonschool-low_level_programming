#include <stdio.h>
char *infinite_add(char *n1, char *n2, char *r, int size_r);

int main(void)
{
  char *n = "1234567892434574367823574575678477685785645685876876774586734734563456453743756756784458";
  char *m = "9034790663470697234682914569346259634958693246597324659762347956349265983465962349569346";
  char r[100];
  char *res;

  res = infinite_add(n, m, r, 100);
  if (res == 0)
    {
      printf("Error\n");
      return (1);
    }
  printf("%s + %s = %s\n", n, m, res);
  return (0);
}
