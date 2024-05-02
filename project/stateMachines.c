#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "libTimer.h"
#include "shapes.h"
#include "buzzer.h"

void squareNoise(){
  buzzer_set_period(G4); P1OUT |= LED; delay(Q);
  buzzer_set_period(0); P1OUT &= ~LED; delay(Q);
  buzzer_set_period(G4); P1OUT |= LED; delay(Q);
  buzzer_set_period(0); P1OUT &= ~LED; delay(Q);
  buzzer_set_period(G4); P1OUT |= LED; delay(Q);
  buzzer_set_period(0); P1OUT &= ~LED ; delay(Q);
  buzzer_set_period(G4); P1OUT |= LED ;delay(Q);
  buzzer_set_period(0); P1OUT &= ~LED; delay(Q);
}

void triangleNoise(){
  buzzer_set_period(E4); P1OUT |= LED; delay(Q);
  buzzer_set_period(0); P1OUT &= ~LED; delay(Q);
  buzzer_set_period(E4); P1OUT |= LED; delay(Q);
  buzzer_set_period(0); P1OUT &= ~LED; delay(Q);
  buzzer_set_period(E4); P1OUT |= LED; delay(Q);
  buzzer_set_period(0); P1OUT &= ~LED; delay(Q);
}

void state(int n){
  switch(n){
  case 1:
    redrawScreen = 1;
    current_color = (current_color+1) % NUM_SQCOLORS;
    break;

  case 2:
    redrawScreen = 1;
    current_shape = 1; //1 for square
    squareNoise();
    break;

  case 3:
    redrawScreen = 1;
    current_shape = 2; //2 for circle
    break;

  case 4:
    redrawScreen = 1;
    current_shape = 3; //3 for triangle
    triangleNoise();
    break;
    
  default:
    break;
  }
}
