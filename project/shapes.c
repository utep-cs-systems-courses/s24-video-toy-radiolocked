#include "shapes.h"
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "switches.h"

Pos positions[] = {
  {10,10},/* upper left */
  {10, screenHeight-10}, /* lower left */
  {screenWidth - 10, screenHeight-10}, /* lower right */
  {screenWidth - 10, 10},       /* upper right */
  {screenWidth/2, screenHeight/2}      /* middle */
};

void update_shape(){
  static char last_position = 0, last_color = 0;
  redrawScreen = 0;
  int pos, color;
  and_sr(~8); //mask interrupts (GIE = 0)
  pos = current_position; //read state variables
  color = current_color;
  or_sr(8); //unmask interrupts
  if(pos == last_position && color == last_color){ //nothing to redraw
    return;
  }

  //erase old shape
  short col = positions[last_position].col;
  short row = positions[last_position].row;
  if(pos != last_position) //erase if position changed
    fillRectangle(col - 5, row - 5, 10, 10, BG_COLOR);
  //draw new shape
  col = positions[pos].col;
  row = positions[pos].row;
  fillRectangle(col-5, row-5, 10, 10, sqColors[color]); /* draw new shape */
  /* remember color & pos for next redraw */
  last_position = pos;
  last_color = color;
}

void set_shape(){
  static char last_color = 0;
  redrawScreen = 0;
  int color;
  int size = 80;
  and_sr(~8); //mask interrupts (GIE = 0)
  color = current_color;
  or_sr(8); //unmask interrupts

  if(color == last_color){
    return; //nothing to redraw
  }
  //erase old shape
  drawRectOutline((screenWidth / 2) - (size / 2), (screenHeight / 2) - (size / 2), size, size, BG_COLOR);
  drawCircleOutline((screenWidth / 2), (screenHeight / 2), (size / 2), BG_COLOR);
  //draw new shape
  if(current_shape == 1){
    drawRectOutline((screenWidth / 2) - (size / 2), (screenHeight / 2) - (size / 2), size, size, sqColors[color]);
  last_color = color; //remember for next redraw
  }else if(current_shape == 2){
    drawCircleOutline((screenWidth / 2), (screenHeight / 2), (size / 2), sqColors[color]);
    last_color = color; //remember for next redraw
  }
}
