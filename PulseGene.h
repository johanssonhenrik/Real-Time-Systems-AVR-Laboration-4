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
	int whichpulse;
} PULSEGEN;

void pulseInc(PULSEGEN *this, int a);
void pulseDec(PULSEGEN *this, int a);
void SaveValue(PULSEGEN *this, int a);
void sendtogate(PULSEGEN *this);

#define initPG(freq, pos, old_value, saved, gate, whichpulse){initObject(),freq, pos, old_value, saved, gate, whichpulse} 
// Defining a class in C using TinyTimber.
// init<Name>(variables....){initObject(FOR Object super...),variables....}
	
#endif	__PULSEGEN_H_