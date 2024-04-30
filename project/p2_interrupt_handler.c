#include <msp430.h>
#include <libTimer.h>
#include "switches.h"

/*switch is on p2*/
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if(P2IFG & SWITCHES) {
    P2IFG &= ~SWITCHES;
    switch_interrupt_handler();
  }
}

/*single handler for a switches*/
