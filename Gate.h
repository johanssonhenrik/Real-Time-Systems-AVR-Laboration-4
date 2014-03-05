#ifndef __GATE_H_
#define __GATE_H_
#include "TinyTimber.h"

typedef struct {
	Object super;
	int writepulseleft;
	int writepulseright;
	int pulseguard;
}GATE;

void Gate(GATE *this);

#define initGATE(writepulseleft, writepulseright, pulseguard){initObject(), writepulseleft, writepulseright ,pulseguard}

#endif __GATE_H_