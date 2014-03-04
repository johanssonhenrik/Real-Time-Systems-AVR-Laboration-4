
#include "Gate.h"
#include <avr/io.h>
#include <avr/iom169p.h>
#include <avr/portpins.h>

void Gate(GATE *self){
	// Responsible for writing to PORTE, preventing a race condition between the two pulse generators
		
	if(self->pulse1 == 1){
		if(((PORTE >> 4) & 1) == 1){
				PORTE = (0 << PORTE4);
			}else{
				PORTE = (1 << PORTE4);
		}
	}else if(self->pulse2 == 1){
		if(((PORTE >> 6) & 1) == 1){
			PORTE = (0 << PORTE6);
		}else{
			PORTE = (1 << PORTE6);
		}
	}
}