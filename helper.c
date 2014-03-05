/*
 * helper.c
 *
 * Created: 2014-03-03 18:05:51
 *  Author: SIMON
 */ 
#include <avr/io.h>
#include "GUI.h"
#include "helper.h"
#include "PulseGene.h"

void repeat(HELP* self, int incordec){
	PULSEGEN* pulse;
	
	if(self->gui->pulseUsed == 0){
		pulse = self->gui->pulse1;
	}else{
		pulse = self->gui->pulse2;
	}
	if(self->firstpress){
		self->firstpress = 0;
		AFTER(MSEC(1000), self, repeat, 0);	
	}
	if((((PINB >> 6) & 1) == 0 && incordec == 0)){ // Up
		//pulseInc(pulse, 0);
		SYNC(pulse, pulseInc, 0);
		SYNC(self->gui, update, 0);
		AFTER(MSEC(400), self, repeat, 0);
	}else if (((PINB >> 7) == 0) && incordec == 1){ // Down
		//pulseDec(pulse, 1);
		SYNC(pulse, pulseDec, 0);
		SYNC(self->gui, update, 0);
		AFTER(MSEC(400), self, repeat, 1);
	}
}
