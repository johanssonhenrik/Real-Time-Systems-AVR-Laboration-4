/*	
	Reactive Object:
	Frequency -> Timer, AFTER skickas efter en viss tidsintervall, frequency minskar tidsintervallet.
	Write to port E bit 4 and 6
	Reset -> save current values and set to 0, when pressed again -> load the saved values.
	Middle PINB,4
	Left PINE,2
	Right PINE,3
*/
#include <avr/io.h>
#include <avr/iom169p.h>
#include "PulseGene.h"
#include "joystick.h"
#include "GUI.h"

void pulseInc(PULSEGEN *self, int a){
	if(self->frequency < 99){
		self->frequency = self->frequency + 1;
	}
}

void pulseDec(PULSEGEN *self, int a){
	if(self->frequency > 0){
		self->frequency = self->frequency - 1;
	}
}

void SaveValue(PULSEGEN *self, int a){
	if(self->saved == 0){
		self->old_value = self->frequency;
		self->frequency = 0;
		self->saved = 1;
	}else if(self->saved == 1){
		self->frequency = self->old_value;
		self->old_value = 0;
		self->saved = 0;
	}
}

void repeat(PULSEGEN* pulse, int incordec){
	if((((PINB >> 6) & 1) == 0 && incordec == 0)){
		pulseInc(pulse, 0);
		AFTER(MSEC(500), pulse, repeat, 0);
	}else if (((PINB >> 7) == 0) && incordec == 1){ 
		pulseDec(pulse, 1);
		AFTER(MSEC(500), pulse, repeat, 1);
	}
}
