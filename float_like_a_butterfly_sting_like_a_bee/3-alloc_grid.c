#include <stdlib.h>
#include <stdio.h>

int **alloc_grid(int y, int x){
  int i, j;
  int ** grid;

  grid = malloc(sizeof(int *) * y);

  if (grid == NULL)
    return NULL;

  for (i = 0; i < y; i++) {
    grid[i] = malloc(sizeof(int) * x);
    if (grid[i] == NULL)
      return NULL;
  }

  for (i = 0; i < y; i++)
    for (j = 0; j < x; j++)
      grid[i][j] = 0;

  return grid;
}
