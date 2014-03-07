
#include "Gate.h"
#include <avr/io.h>
#include <avr/iom169p.h>
#include <avr/portpins.h>

/*
(Gate) Responsible for writing to PORTE,
preventing a race condition between
the two pulse generators.
*/

void Gate(GATE *self, int whichpulse){

	if(whichpulse == 1){
		PORTE ^= 0x40;
		}else if(whichpulse == 0){
		PORTE ^= 0x10;
	}

	/*
	//LCDDR2 = 0x4F | LCDDR2;
	if(self->writepulseleft == 1){
		if(((PORTE >> 3) & 1) == 1){		//OBS MAYBE PORTE >> 4
			PORTE ^= 0x08;					//PORTE = (0 << PORTE4) & PORTE;
			self->writepulseleft = 0;
		}else{										
			PORTE ^= 0x08;					//PORTE = (1 << PORTE4) | PORTE;
			self->writepulseleft = 0;
		}
	}else if(self->writepulseright == 1){
		if(((PORTE >> 5) & 1) == 1){		//OBS MAYBE PORTE >> 6
			PORTE ^= 0x20;					//PORTE = (0 << PORTE6) & PORTE;
			self->writepulseright = 0;
		}else{
			PORTE ^= 0x20;					//PORTE = (1 << PORTE6) | PORTE;
			self->writepulseright = 0;
		}
	}
	*/	
}