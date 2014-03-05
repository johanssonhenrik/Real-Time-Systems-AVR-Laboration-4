
#include "init.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/iom169p.h>
#include <avr/portpins.h>
#define true	1
#define false	0

void init(){
		// Clock prescaler
		CLKPR = 0x80;
		CLKPR = 0x00;
		// LCD
		LCDCRA = 0xC0; // LCD ENABLE and LOW POWER WAVEFORM
		LCDCRB = 0xB7; // AsyncClock, 1/3 Bias, 1/4 Duty, 25 Segments 
		LCDFRR = 0x07; // LCD Clock Divide 32 Hz
		LCDCCR = 0x0F; // 3.35 Volt		
		TCCR1B = 0x0D; // Clock prescaler set to 1024 and CFC.
		// Ports
		//PORTB = (1 << PORTB7)|(1 << PORTB6)|(1 << PORTB4);
		
		PORTB = (1 << PORTB7) | PORTB;
		PORTB = (1 << PORTB6) | PORTB;
		PORTB = (1 << PORTB4) | PORTB;
	
		//PORTE = (1 << PORTE3)|(1 << PORTE2);
		
		PORTE = (1 << PORTE3) | PORTE;
		PORTE = (1 << PORTE2) | PORTE;
	
		//DDR_OC1A = 1 , sida 108
		// Sida 70
		
		//DDRE = (1 << DDE3) | (1 << DDE2);
		
		DDRE = (1 << DDE3) | DDRE;
		DDRE = (1 << DDE2) | DDRE;
		
		//LCDDR2 = 0x4F | LCDDR2; //Siffran 10 i nedre högra hörnet. LCD Segment.
		
		
		LCDDR17 = 0x10 | LCDDR17;	//Initial d section lit. 
		/*
		PORTB = 0xd0; // Enables pin 7(down),6(up),4(middle)
		PORTE = 0x0c; // Enables pin 3(right),2(left)
		*/
		
		// Pin Interrupt
		PCMSK0 = 0x0c; // Pin change interrupt enabled on corresponding I/O pin.
		PCMSK1 = 0xd0;
		EIFR = 0xc0; // Interrupt request
		EIMSK = 0xc0; // cause an interrupt	
}