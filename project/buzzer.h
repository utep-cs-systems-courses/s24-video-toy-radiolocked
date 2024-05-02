#ifndef buzzer_included
#define buzzer_included

//define notes for speaker
//G4 for square
#define G4 3032

//define duration in milliseconds
#define W 2000 // whole note
#define Q 500 // quarter note

void buzzer_init();
void buzzer_set_perdiod(short cycles);
void delay(unsigned int milliseconds);
#endif
