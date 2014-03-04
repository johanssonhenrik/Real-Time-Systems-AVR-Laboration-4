#ifndef __GATE_H_
#define __GATE_H_
#include "TinyTimber.h"

typedef struct {
	Object super;
	int pulse1;
	int pulse2;
	int pulseguard;
}GATE;

void Gate(GATE *this);

#define initGATE(pulse1, pulse2, pulseguard){initObject(), pulse1, pulse2 ,pulseguard}

#endif __GATE_H_