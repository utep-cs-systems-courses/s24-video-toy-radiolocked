# makfile configuration
CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all:msquares.elf

#additional rules for files
msquares.elf: ${COMMON_OBJECTS} wdt_handler.o led.o shapes.o switches.o p2_interrupt_handler.o main.o stateMachines.o buzzer.o mainLoopCondition.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd

load: msquares.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf *~ *#
