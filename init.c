
#include "init.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/iom169p.h>
#include <avr/portpins.h>
#define true	1
#define false	0

void init(){
	
	//Clock prescaler
		CLKPR = 0x80;
		CLKPR = 0x00;
	//LCD
		LCDCRA = 0xC0;			//LCD ENABLE and LOW POWER WAVEFORM
		LCDCRB = 0xB7;			//AsyncClock, 1/3 Bias, 1/4 Duty, 25 Segments 
		LCDFRR = 0x07;			//LCD Clock Divide 32 Hz
		LCDCCR = 0x0F;			//3.35 Volt		
		TCCR1B = 0x0D;			//Clock prescaler set to 1024 and CFC.
		LCDDR17 = 0x10;		//Initial d section lit.
	//Ports
		PORTB ^= 0xD0;			//PORTB = (1 << PORTB7)|(1 << PORTB6)|(1 << PORTB4);
		PORTE ^= 0x0c;			//PORTE = (1 << PORTE3)|(1 << PORTE2);

		//DDRE ^= 0x50;			//DDRE = (1 << DDE4) | (1 << DDE6);
		//DDRE ^= 0x0c;			//DDRE = (1 << DDE2) | (1 << DDE3);
		
		//DDR_OC1A = 1			//S. 108, Check also S. 70
		
		//PORTB = 0xd0;			//Enables pin 7(down),6(up),4(middle)
		//PORTE = 0x0c;			//Enables pin 3(right),2(left)
		
	//Pin Interrupt
		PCMSK0 = 0x0c;			//Pin change interrupt enabled on corresponding I/O pin.
		PCMSK1 = 0xd0;
		EIFR = 0xc0;			//Interrupt request
		EIMSK = 0xc0;			//Cause an interrupt	
}