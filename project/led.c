#include <msp430.h>
#include "led.h"
#include "switches.h"

void led_init()
{
  P1DIR |= LED;
  P1OUT |= LED; //green led on when cpu is on
}
