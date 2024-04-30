#ifndef shapes_included
#define shapes_included

#include "lcdutils.h"
#include "lcddraw.h"

#define NUM_POSITIONS 5
#define NUM_SQCOLORS 4
#define BG_COLOR COLOR_BLACK

extern unsigned short sqColors[];
extern char current_color, current_shape;
extern int redrawScreen;
extern int redrawScreen;

void set_shape();

#endif
