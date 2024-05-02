#ifndef buzzer_included
#define buzzer_included

//define notes for speaker
#define G4 3032
#define E4 3809
#define F5 1432
#define E5 1517
#define D5 1703
#define A4 2864

//define duration in milliseconds
#define W 2000 // whole note
#define Q 500 // quarter note

void buzzer_init();
void buzzer_set_period(short cycles);
void delay(unsigned int milliseconds);
#endif
