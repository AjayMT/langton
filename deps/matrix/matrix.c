
#include <stdlib.h>

#include "matrix.h"

matrix *matrix_new (int cols, int rows)
{
  matrix *m = malloc(sizeof(matrix));
  m->cols = cols;
  m->rows = rows;
  m->vals = malloc(cols * rows * sizeof(int));

  return m;
}

int matrix_get (matrix *m, int col, int row)
{
  return m->vals[(row * m->rows) + col];
}

void matrix_set (matrix *m, int col, int row, int val)
{
  m->vals[(row * m->rows) + col] = val;
}

void matrix_free (matrix *m)
{
  free(m->vals);
  free(m);
}
