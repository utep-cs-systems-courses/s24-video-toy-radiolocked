#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

void buzzer_init(){
  timerAUpmode(); //used to drive speaker
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6; //output to speaker
}

void buzzer_set_period(short cycles)
{
  CCR0 = cycles;
  CCR1 = cycles >> 1; //one half cycle
}

void delay(unsigned int milliseconds){
  unsigned int i;
  for(i = 0; i < milliseconds; i++){
    __delay_cycles(2000); //delay 1 millisecond
  }
}
