
#include "Gate.h"
#include <avr/io.h>
#include <avr/iom169p.h>
#include <avr/portpins.h>

void Gate(GATE *self){
	// Responsible for writing to PORTE, preventing a race condition between the two pulse generators
		
	if(self->writepulseleft == 1){
		if(((PORTE >> 4) & 1) == 1){
				PORTE = (0 << PORTE4) & PORTE;		
			}else{									
				PORTE = (1 << PORTE4) | PORTE;		
		}
	}else if(self->writepulseright == 1){
		if(((PORTE >> 6) & 1) == 1){
			PORTE = (0 << PORTE6) & PORTE;
		}else{
			PORTE = (1 << PORTE6) | PORTE;
		}
	}
	
	//if(self->writepulseleft == 1){
		//if(((PINE >> 4) & 1) == 1){
			//PINE = (0 << PINE4) & PINE;
			//}else{
			//PINE = (1 << PINE4) | PINE;
		//}
		//}else if(self->writepulseright == 1){
		//if(((PINE >> 6) & 1) == 1){
			//PINE = (0 << PIN6) & PINE;
			//}else{
			//PINE = (1 << PINE6) | PINE;
		//}
	//}
	
	// LÄS SIDA 57
}