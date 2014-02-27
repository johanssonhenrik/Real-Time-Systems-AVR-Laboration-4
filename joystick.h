/*
 * joystick.h
 *
 * Created: 2013-02-28 18:28:49
 *  Author: SIMON
 */ 
#ifndef __JOYSTICK_H_
#define __JOYSTICK_H_

#include "TinyTimber.h"
#include "GUI.h"
#include "PulseGene.h"

typedef struct{
	Object super;
	GUI* g;
	int buttonPrevious;
} Joystick;

int joystick(Joystick* this);
void repeat(Joystick* this, PULSEGEN* pulse, int cond);

#define initJoy(g, buttonPrevious){initObject(), g, buttonPrevious}

#endif __JOYSTICK_H_/* JOYSTICK_H_ */