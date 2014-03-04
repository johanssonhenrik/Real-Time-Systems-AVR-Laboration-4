#include "TinyTimber.h"
#include "GUI.h"
#include "PulseGene.h"
#include "joystick.h"
#include "init.h"
#include "Gate.h"
#include <avr/io.h>

// 50% duty cycle, half time on and half time off.
// Sätta som global var då dessa är makron.
GATE gate = initGATE(0,1,0);	//pulse1, pulse2, pulseguard
PULSEGEN pulsegen1 = initPG(0,0,0,0, &gate, 0); // freq, pos, old, saved, gate, used
PULSEGEN pulsegen2 = initPG(0,3,0,0, &gate, 1);
GUI g = initGUI(&pulsegen1, &pulsegen2, 1);	//pulse1, pulse2, pulseused
HELP help = initHelp(&g,0);
Joystick j = initJoy(&help, 0);


int main(void)
{
	init();
	//INSTALL(&g, joystick, IRQ_PCINT0); // Höger Vänster
	//INSTALL(&g, joystick, IRQ_PCINT1); // Upp Ner Tryck
	INSTALL(&j, joystick, IRQ_PCINT0); // Höger Vänster
	INSTALL(&j, joystick, IRQ_PCINT1); // Upp Ner Tryck
	//LCDDR16 = 0xF0;
	return TINYTIMBER(&g, update, 0);
}