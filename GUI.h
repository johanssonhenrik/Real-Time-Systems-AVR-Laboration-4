#ifndef __GUI_H_
#define __GUI_H_

#include "PulseGene.h"
typedef struct {
	Object super;
	PULSEGEN *pulse1;
	PULSEGEN *pulse2;
	int pulseUsed;
} GUI;

//int writeChar(GUI *this, int a);
void writeChar(GUI *this, int pp, int freq);
void printAt(GUI *this, int a);
void update(GUI *this, int a);
//int joystick(GUI *this, int a);
void changegen(GUI *this, int a);
//void render(GUI *this, int a);

#define initGUI(initPG1, initPG2, pulseUsed){initObject(), initPG1, initPG2, pulseUsed}
	
#endif __GUI_H_