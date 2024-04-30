#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "libTimer.h"
#include "shapes.h"

void state(int n){
  switch(n){
  case 1:
    redrawScreen = 1;
    current_color = (current_color+1) % NUM_SQCOLORS;
    break;

  case 2:
    redrawScreen = 1;
    current_position = 1;
    break;

  case 3:
    redrawScreen = 1;
    current_position = 2;
    break;

  case 4:
    redrawScreen = 1;
    current_position = 3;
    break;
  default:
    break;
  }
}
