
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/iom169p.h>
#include <avr/portpins.h>
#define true	1
#define false	0

void Gate(){
	// Responsible for writing to PORTE, preventing a race condition between the two pulse generators
}