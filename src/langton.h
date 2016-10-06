
// langton.h

#ifndef _LANGTON_H
#define _LANGTON_H

#include "matrix.h"

typedef enum {
  LANGTON_UP,
  LANGTON_RIGHT,
  LANGTON_DOWN,
  LANGTON_LEFT,
} langton_direction;

typedef enum {LANGTON_WHITE, LANGTON_BLACK} langton_color;

typedef struct _langton_ant {
  int x, y;
  langton_direction dir;
} langton_ant;

langton_ant *langton_ant_new (int x, int y);
void langton_fill_matrix (matrix *m, langton_color color);
int langton_iterate (langton_ant *a, matrix *m);
void langton_ant_free (langton_ant *a);

#endif
