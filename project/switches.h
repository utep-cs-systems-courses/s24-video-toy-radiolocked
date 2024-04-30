#ifndef switches_included
#define switches_included

#define S1 BIT0 //switch is p2.0
#define S2 BIT1 //switch is p2.1
#define S3 BIT2
#define S4 BIT3
#define SWITCHES (S1 | S2 | S3 | S4)

static char switch_update_interrupt_sense();
void switch_init();
void switch_interrupt_handler();
void wdt_init();

#endif //included
