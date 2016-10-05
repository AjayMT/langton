
#include <stdlib.h>

#include "langton.h"
#include "matrix.h"

void init_matrix (matrix *m, langton_color color)
{
  for (int i = 0; i < m->cols; i++)
    for (int j = 0; j < m->rows; j++)
      matrix_set(m, i, j, color);
}

langton_ant *langton_new_ant (int x, int y)
{
  langton_ant *a = malloc(sizeof(langton_ant));
  a->dir = LANGTON_UP;
  a->x = x;
  a->y = y;

  return a;
}

int langton_iterate (langton_ant *a, matrix *m)
{
  if (a->x < 0 || a->x >= m->cols) return 0;
  if (a->y < 0 || a->y >= m->rows) return 0;

  langton_color color = matrix_get(m, a->x, a->y);
  matrix_set(m, a->x, a->y, (! color));

  if (color) { // black
    // move
    a->x -= (a->dir == LANGTON_UP ? 1 : 0);
    a->x += (a->dir == LANGTON_DOWN ? 1 : 0);
    a->y -= (a->dir == LANGTON_LEFT ? 1 : 0);
    a->y += (a->dir == LANGTON_RIGHT ? 1 : 0);

    // rotate
    a->dir = (a->dir + 3) % 4;
  } else { // white
    // move
    a->x += (a->dir == LANGTON_UP ? 1 : 0);
    a->x -= (a->dir == LANGTON_DOWN ? 1 : 0);
    a->y += (a->dir == LANGTON_LEFT ? 1 : 0);
    a->y -= (a->dir == LANGTON_RIGHT ? 1 : 0);

    // rotate
    a->dir = (a->dir + 1) % 4;
  }

  return 1;
}

void langton_free_ant (langton_ant *a)
{
  free(a);
}
