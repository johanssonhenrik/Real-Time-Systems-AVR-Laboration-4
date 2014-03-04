/*
 * joystick.c
 *
 * Created: 2013-02-28 18:28:21
 *  Author: SIMON
 */ 
#include "TinyTimber.h"
#include "joystick.h"
#include "GUI.h"
#include "PulseGene.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/iom169p.h>

int joystick(Joystick* self){
	PULSEGEN* pulse;
	
	if(self->buttonPrevious == 1) {
		self->buttonPrevious = 0;
		return 0;
	}
	if(self->g->gui->pulseUsed == 0){
		pulse = self->g->gui->pulse1;
	}else{
		pulse = self->g->gui->pulse2;
	}
	
	if (((PINB >> 6) & 1) == 0){ 
		self->buttonPrevious = 1;
		//ASYNC(pulse, pulseInc, 0);					// Up
		//ASYNC(self->g, repeat, 0);
		//ASYNC(pulse, repeat, 0);
		self->g->firstpress = 1;
		ASYNC(self->g, repeat, 0);
		self->g->firstpress = 0;
		
		
	} else if ((PINB >> 7) == 0){
		self->buttonPrevious = 1;
		//ASYNC(pulse, pulseDec, 0);					// Down
		//ASYNC(pulse, repeat, 1);
		ASYNC(self->g, repeat, 1);
		
	} else if (((PINE >> 2) & 1) == 0 && self->g->gui->pulseUsed == 1){
		self->buttonPrevious = 1;
		ASYNC(self->g->gui, changegen, 0);				// Left
		
	} else if (((PINE >> 3) & 1) == 0 && self->g->gui->pulseUsed == 0){
		self->buttonPrevious = 1;
		ASYNC(self->g->gui, changegen, 0);				// Right
		
	} else if (((PINB >> 4) & 1) == 0){
		self->buttonPrevious = 1;
		ASYNC(pulse, SaveValue, 0);					// Middle
	}
	ASYNC(self->g->gui, update, 0);
	return 0;
}
