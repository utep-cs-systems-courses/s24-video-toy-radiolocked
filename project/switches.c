#include <msp430.h>
#include "switches.h"
#include "libTimer.h"
#include "led.h"
#include "stateMachines.h"
#include "shapes.h"
#include "lcdutils.h"
#include "lcddraw.h"

static char
switch_update_interrupt_sense()
{
  char p2val = P2IN;

  P2IES |= (p2val & SWITCHES);
  P2IES &= (p2val | ~SWITCHES);
  return p2val;
}

void
switch_init()
{
  P2REN |= SWITCHES;/* enables resistors for switches */
  P2IE |= SWITCHES;/* enable interrupts from switches */
  P2OUT |= SWITCHES;/* pull-ups for switches */
  P2DIR &= ~SWITCHES;/* set switches' bits for input */
  switch_update_interrupt_sense();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  
  char sw_1 = (p2val & S1) ? 0 : S1;
  char sw_2 = (p2val & S2) ? 0 : S2;
  char sw_3 = (p2val & S3) ? 0 : S3;
  char sw_4 = (p2val & S4) ? 0 : S4;

  if(sw_1){
    //state(1);
    redrawScreen = 1;
    current_position = 0;
  }
  else if(sw_2){
    //state(2);
    redrawScreen = 1;
    current_position = 1;
  }
  else if(sw_3){
    //state(3);
    redrawScreen = 1;
    current_position = 2;
  }
  else if(sw_4){
    //state(4);
    redrawScreen = 1;
    current_position = 3;
  }
}
