#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "led.h"
#include "switches.h"
#include "shapes.h"

char current_position = 0;
char current_color = 0;
unsigned short sqColors[] = {COLOR_RED, COLOR_GREEN, COLOR_ORANGE, COLOR_BLUE};
int redrawScreen = 1;

void wdt_c_handler(){
  /*static int sec2Count = 0;
  static int sec1Count = 0;
  if(sec2Count++ >= 125){
    sec2Count = 0;
    current_color = (current_color+1) % NUM_SQCOLORS;
    redrawScreen = 1;
  }
  if(sec1Count++ >= 250){
    sec1Count = 0;
    current_position = (current_position+1) % NUM_POSITIONS;
    redrawScreen = 1;
 }*/
}

void main(){
  led_init();
  configureClocks();
  lcd_init();
  switch_init();

  enableWDTInterrupts();
  or_sr(0x8);

  clearScreen(BG_COLOR);
  while(1){
    if(redrawScreen){
      redrawScreen = 0;
      set_shape();
    }
    P1OUT &= ~LED; //leds off
    or_sr(0x10); //CPU OFF
    P1OUT |= LED; //leds on
  }
}
