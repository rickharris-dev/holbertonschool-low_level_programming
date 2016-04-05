#include <stdio.h>

int single_hyphen(char **av, int c, char *source, int z){
  int i, x;
  /* Checks for double-hyphenated single char to test */
  for (i = 0; i < c; i++){
    if(av[i][0] == '-' && av[i][1] == '-' && av[i][3] == '\0'){
      if (source[0] == av[i][2])
        return 0;
    } /* Checks for single-hyphenated single char to test */
    else if (av[i][0] == '-' && av[i][2] == '\0' && source[0] == av[i][1])
      return 0;
    else if (av[i][0] == '-' && av[i][1] != '-') /* Single hyphen, multi-char */
      for (x = 1; av[i][x] != '\0'; x++)
        if (source[0] == av[i][x])
          return 0;
    if(source[0 - 1] != '-') /* Tests preceeding chars on single hyphen */
      for (x = 1; source[0 - x] != '-' && source[0 - x - 1] != '\0'; x++)
        if (source[0] == source[0 - x])
          return 0;
  }
  if (z != 0) /* Prints comma and space if not the start of output */
    printf(", ");
  printf("%c", *source);
  return 1;
}

int double_hyphen(char **av, int c, char *source, int z){
  int i, r, x;
  /* Compares double-hyphenated strings */
  for (i = 0, r = 1; i < c; i++){
    if(av[i][0] == '-' && av[i][1] == '-'){
      for (x = 0; av[i][x + 1] != '\0' && source[x - 1] != '\0'; x++){
        if (av[i][x + 2] != source[x])
          r = 0;
      }
      if (r == 1)
        return 0;
    }
  }
  if (z != 0) /* Prints comma and space if not the start of output */
    printf(", ");
  printf("%s", source);
  return 1;
}

int main(int ac, char **av) {
  int i, x, z;
  /* Identifies the source string and delivers to test functions */
  for (i = 0, z = 0; i < ac; i++) {
    if (av[i][0] == '-' && av[i][1] == '-' && av[i][2] == '\0')
      break;
    else if (av[i][0] == '-' && av[i][1] == '-' && av[i][3] != '\0')
      z = z + double_hyphen(av, i, &(av[i][2]), z);
    else if (av[i][0] == '-' && av[i][1] == '-')
      z = z + single_hyphen(av, i, &(av[i][2]), z);
    else if (av[i][0] == '-' && av[i][2] == '\0')
      z = z + single_hyphen(av, i, &(av[i][1]), z);
    else if (av[i][0] == '-')
      for(x = 1; av[i][x] != '\0'; x++)
        z = z + single_hyphen(av, i, &(av[i][x]), z);
  }
  printf("\n"); /* Prints closing new line and returns successful */
  return 0;
}
