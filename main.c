/*
 * AVRGCC4.c
 *
 * Created: 2012-03-07 14:20:24
 *  Author: johsim-0
 */ 

#include "TinyTimber.h"
#include "GUI.h"
#include "PulseGene.h"
#include "joystick.h"
#include "init.h"
#include "Gate.h"
#include <avr/io.h>

// 50% duty cycle, half time on and half time off.
// Sätta som global var då dessa är makron.
PULSEGEN pulsegen1 = initPG(0,1,0,0,0); // freq, pin, pos, old, saved
PULSEGEN pulsegen2 = initPG(0,3,3,0,0);
GUI g = initGUI(&pulsegen1, &pulsegen2, 1);
Joystick j = initJoy(&g, 0);
GATE gate = initGATE();

int main(void)
{
	init();
	//INSTALL(&g, joystick, IRQ_PCINT0); // Höger Vänster
	//INSTALL(&g, joystick, IRQ_PCINT1); // Upp Ner Tryck
	INSTALL(&j, joystick, IRQ_PCINT0); // Höger Vänster
	INSTALL(&j, joystick, IRQ_PCINT1); // Upp Ner Tryck
	//LCDDR17 = 0x10;
	return TINYTIMBER(&g, update, 0);
}