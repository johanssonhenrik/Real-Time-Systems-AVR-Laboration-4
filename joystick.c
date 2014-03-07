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
#include <avr/iom169p.h>

int joystickPORTB(Joystick* self){
	PULSEGEN* pulse;
	
	if(self->buttonPrevious == 1){
		self->buttonPrevious = 0;
		return 0;
	}
	if(self->g->gui->pulseUsed == 0){
		pulse = self->g->gui->pulse1;
	}else{
		pulse = self->g->gui->pulse2;
	}
	
	if (((PINB >> 6) & 1) == 0){				//Up
		self->buttonPrevious = 1;
		self->g->firstpress = 1;
		ASYNC(self->g, repeat, 0);
		
	}else if (((PINB >> 7) & 1) == 0){			//Down
		self->buttonPrevious = 1;														
		ASYNC(self->g, repeat, 1);
		
	}else if (((PINB >> 4) & 1) == 0){
		self->buttonPrevious = 1;
		ASYNC(pulse, SaveValue, 0);						
	}
	ASYNC(self->g->gui, update, 0);
	return 0;
}

int joystickPORTE(Joystick *self){
	if(self->buttonPrevious == 1){
		self->buttonPrevious = 0;
		return 0;
	}
	if(((PINE >> 2) & 1) == 0 && self->g->gui->pulseUsed == 1){
		self->buttonPrevious = 1;
		ASYNC(self->g->gui, changegen, 0);									//Left->Right
	}else if (((PINE >> 3) & 1) == 0 && self->g->gui->pulseUsed == 0){
		self->buttonPrevious = 1;
		ASYNC(self->g->gui, changegen, 0);									//Right->Left
	}
	ASYNC(self->g->gui, update, 0);
	return 0;
	
}
