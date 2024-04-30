#ifndef shapes_included
#define shapes_included

#include "lcdutils.h"
#include "lcddraw.h"

#define NUM_POSITIONS 5
#define NUM_SQCOLORS 4
#define BG_COLOR COLOR_BLACK

typedef struct{
  short col, row;
}Pos;

extern Pos positions[];

extern unsigned short sqColors[];
extern char current_position, current_color;
extern int redrawScreen;
extern int redrawScreen;

void update_shape();

#endif
