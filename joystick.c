/*
 * joystick.c
 *
 * Created: 2013-02-28 18:28:21
 *  Author: SIMON
 */ 
#include "TinyTimber.h"
#include "GUI.h"
#include "PulseGene.h"
#include "joystick.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/iom169p.h>

int joystick(Joystick* self){
	//int b;
	PULSEGEN* pulse;
	
	if(self->buttonPrevious == 1) {
		cond = 0;
		self->buttonPrevious = 0;
		return 0;
	}
	if(self->g->pulseUsed == 0){
		pulse = self->g->pulse1;
		//b = 0;
	}else{
		pulse = self->g->pulse2;
		//b = 1;
	}
	
	if (((PINB >> 6) & 1) == 0){ 
		self->buttonPrevious = 1;
		//ASYNC(pulse, pulseInc, 0);					// Up
		repeat(self, pulse, 0);
		
	} else if ((PINB >> 7) == 0){
		self->buttonPrevious = 1;
		//ASYNC(pulse, pulseDec, 0);					// Down
		repeat(self, pulse, 1);
		
	} else if (((PINE >> 2) & 1) == 0 && self->g->pulseUsed == 1){
		self->buttonPrevious = 1;
		ASYNC(self->g, changegen, 0);				// Left
	} else if (((PINE >> 3) & 1) == 0 && self->g->pulseUsed == 0){
		self->buttonPrevious = 1;
		ASYNC(self->g, changegen, 0);				// Right
	} else if (((PINB >> 4) & 1) == 0){
		self->buttonPrevious = 1;
		ASYNC(pulse, SaveValue, 0);					// Middle
	}
	ASYNC(self->g, update, 0);
	return 0;
}

void repeat(Joystick* self, PULSEGEN* pulse, int cond){ // cond = pulseInc/pulseDec
	
	if(){
		if(cond == 0){
			ASYNC(pulse, pulseInc, 0);
			repeat(self, pulse, cond);
		}else if (cond == 1){
			ASYNC(pulse, pulseDec, 1);
			repeat(self, pulse, cond);
		}
	}
}

	
	//if(((PINB >> 6) & 1) == 0 && joy->buttonPrevious == 1){
	//joy->buttonPrevious = 0;
	//}else if(((PINB >> 7) & 1) == 0 && joy->buttonPrevious == 1){
	//joy->buttonPrevious = 0;
	//}else if(((PINB >> 2) & 1) == 0 && joy->buttonPrevious == 1){
	//joy->buttonPrevious = 0;
	//}else if(((PINB >> 3) & 1) == 0 && joy->buttonPrevious == 1){
	//joy->buttonPrevious = 0;
	//}else if(((PINB >> 4) & 1) == 0 && joy->buttonPrevious == 1){
	//joy->buttonPrevious = 0;
	//}