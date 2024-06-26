#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "led.h"
#include "switches.h"
#include "shapes.h"
#include "buzzer.h"

char current_color = 0;
char current_shape = 0;
unsigned short sqColors[] = {COLOR_RED, COLOR_GREEN, COLOR_ORANGE, COLOR_BLUE};
int redrawScreen = 1;

void wdt_c_handler(){
  //not using currently
}

void main(){
  configureClocks();
  lcd_init();
  led_init();
  switch_init();
  buzzer_init();
  enableWDTInterrupts();
  or_sr(0x8);

  clearScreen(BG_COLOR);
  while(1){
    if(redrawScreen){
      redrawScreen = 0;
    }
    P1OUT &= ~LED; //leds off
    or_sr(0x10); //CPU OFF
    P1OUT |= LED; //leds on
  }
}
