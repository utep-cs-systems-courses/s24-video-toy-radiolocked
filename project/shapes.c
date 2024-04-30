#include "shapes.h"
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "switches.h"

void set_shape(){
  static char last_color = 0;
  redrawScreen = 0;
  int color;
  int size = 80;
  and_sr(~8); //mask interrupts (GIE = 0)
  color = current_color;
  or_sr(8); //unmask interrupts

  //erase old shape
  drawRectOutline((screenWidth / 2) - (size / 2), (screenHeight / 2) - (size / 2), size, size, BG_COLOR);
  drawCircleOutline((screenWidth / 2), (screenHeight / 2), (size / 2), BG_COLOR);
  drawTriangleOutline((screenWidth / 2), (screenHeight / 2) - (size / 2), (screenWidth / 2) - (size / 2), (screenHeight / 2) + (size / 2), (screenWidth / 2) + (size / 2), (screenHeight / 2) + (size / 2), BG_COLOR);
  //draw new shape
  //if current_shape is a square
  if(current_shape == 1){
    drawRectOutline((screenWidth / 2) - (size / 2), (screenHeight / 2) - (size / 2), size, size, sqColors[color]);

  //if current shape is a circle
  }else if(current_shape == 2){
    drawCircleOutline((screenWidth / 2), (screenHeight / 2), (size / 2), sqColors[color]);

    //if current shape is a triangle
  }else if(current_shape == 3){
    drawTriangleOutline((screenWidth / 2), (screenHeight / 2) - (size / 2), (screenWidth / 2) - (size / 2), (screenHeight / 2) + (size / 2), (screenWidth / 2) + (size / 2), (screenHeight / 2) + (size / 2), sqColors[color]);
  }
}
