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
#include "helper.h"

typedef struct{
	Object super;
	HELP *g;
	int buttonPrevious;
} Joystick;

int joystickPORTB(Joystick *this);
int joystickPORTE(Joystick *this);

#define initJoy(g, buttonPrevious){initObject(), g, buttonPrevious}

#endif __JOYSTICK_H_