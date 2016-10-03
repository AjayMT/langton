
#include <stdlib.h>

#include "langton.h"
#include "matrix.h"

#define NULL (void *)0

void init_matrix (matrix *m, langton_color color)
{
  for (int i = 0; i < m->cols; i++)
    for (int j = 0; j < m->rows; j++)
      matrix_set(m, i, j, color);
}

langton_ant *langton_new_ant (int x, int y)
{
  langton_ant *a = malloc(sizeof(langton_ant));
  a->dir = LANGTON_Y;
  a->x = x;
  a->y = y;

  return a;
}

int langton_iterate (langton_ant *a, matrix *m)
{
  if (a->x < 0 || a->x >= m.cols) return 0;
  if (a->y < 0 || a->y >= m.rows) return 0;

  langton_color color = matrix_get(m, a->x, a->y);
  // do shit

  return 1;
}

void langton_free_ant (langton_ant *a)
{
  free(a);
}
