
// matrix.h

#ifndef _MATRIX_H
#define _MATRIX_H

typedef struct _matrix {
  int cols;
  int rows;
  int *vals;
} matrix;

matrix *matrix_new (int cols, int rows);
int matrix_get (matrix *m, int col, int row);
void matrix_set (matrix *m, int col, int row, int val);
void matrix_free (matrix *m);

#endif
