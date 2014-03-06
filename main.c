#include "TinyTimber.h"
#include "GUI.h"
#include "PulseGene.h"
#include "joystick.h"
#include "init.h"
#include "Gate.h"
#include <avr/io.h>

//50% duty cycle, half time on and half time off.

GATE gate = initGATE(0,1,0);						//writepulseleft, writepulseright, pulseguard
PULSEGEN pulsegen1 = initPG(0,0,0,0, &gate, 0);		//freq, pos, old, saved, gate, used
PULSEGEN pulsegen2 = initPG(0,3,0,0, &gate, 1);
GUI g = initGUI(&pulsegen1, &pulsegen2, 1);			//pulse1, pulse2, pulseused
HELP help = initHelp(&g,0);
Joystick j = initJoy(&help, 0);

int main(void){
	
	init();
	INSTALL(&j, joystickPORTE, IRQ_PCINT0);			//Right, Left
	INSTALL(&j, joystickPORTB, IRQ_PCINT1);			//Up, Down, Press

	return TINYTIMBER(&g, update, 0);
	//return TINYTIMBER(&gate, Gate, 0);
	//return TINYTIMBER(&pulsegen2, sendtogate, 0);
}