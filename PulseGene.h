#ifndef __PULSEGEN_H_	// Förhindrar include loops.
#define __PULSEGEN_H_

#include "TinyTimber.h"
#include "Gate.h"

typedef struct {
	Object super;	// Always needed
	int frequency;
	int pos;
	int old_value;
	int saved;
	GATE *gate;
	int used;
} PULSEGEN;

void pulseInc(PULSEGEN *this, int a);
void pulseDec(PULSEGEN *this, int a);
void SaveValue(PULSEGEN *this, int a);
void sendtogate(PULSEGEN *this);
//void repeat(PULSEGEN* pulse, int incdec);
//void update_freq(PULSEGEN *this, Joystick *that);
//void changegen(PULSEGEN *this, int a);

#define initPG(freq, pos, old_value, saved, gate, used){initObject(),freq, pos, old_value, saved, gate, used} 
// Defining a class in C using TinyTimber.
// init<Name>(variables....){initObject(FOR Object super...),variables....}
	
#endif	__PULSEGEN_H_