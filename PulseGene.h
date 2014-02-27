#ifndef __PULSEGEN_H_	// Förhindrar include loops.
#define __PULSEGEN_H_

#include "TinyTimber.h"

typedef struct {
	Object super;	// Always needed
	int frequency;
	int pin;
	int pos;
	int old_value;
	int saved;
} PULSEGEN;

void pulseInc(PULSEGEN *this, int a);
void pulseDec(PULSEGEN *this, int a);
void SaveValue(PULSEGEN *this, int a);
//void changegen(PULSEGEN *this, int a);

#define initPG(freq,pin,pos,old_value, saved){initObject(),freq,pin,pos, old_value, saved} 
// Defining a class in C using TinyTimber.
// init<Name>(variables....){initObject(FOR Object super...),variables....}
	
#endif	__PULSEGEN_H_