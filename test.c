
#include <stdio.h>

#include "langton.h"

int main (int argc, char *argv[])
{
  matrix *m = matrix_new(20, 20);
  langton_ant *a = langton_ant_new(10, 10);
  langton_fill_matrix(m, LANGTON_WHITE);

  printf("should be:\n10 10 0\n11 10 0\n11 9 0\n10 9 0\n10 10 1\n9 10 0\n\n");

  printf("%d %d %d\n", a->x, a->y, matrix_get(m, a->x, a->y));

  for (int i = 0; i < 5; i++) {
    langton_iterate(a, m);
    printf("%d %d %d\n", a->x, a->y, matrix_get(m, a->x, a->y));
  }

  langton_ant_free(a);
  matrix_free(m);

  return 0;
}
