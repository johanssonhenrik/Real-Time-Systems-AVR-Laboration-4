
#include "TinyTimber.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/iom169p.h>
#include "GUI.h"
#include "PulseGene.h"

int ASCII_TABLE[10] = 
{
		0x1551,		// 0 = 1551, A = 0F51
		0x0110,		// 1
		0x1e11,		// 2
		0x1B11,		// 3
		0x0B50,		// 4
		0x1B41,		// 5
		0x1F41,		// 6
		0x0111,		// 7
		0x1F51,		// 8
		0x0B51		// 9
};

int writeChar(GUI *self, int pos, int bokstav){
	/* 
	 *self = object innehållandes freq och pos. pulseActive = pulse1/2.
	 */
	char mask;
	int karaktar = 0x0000;
	char nibbles = 0x00;
	int x;
	char lcddr = 0xec;
	//int bokstav;
	//int pos;

	//if (pulseActive == 0){
		//bokstav = (self->pulse1->frequency);		// blir 288 -> man skickar in &self och inte self i printAt!
		//pos = (self->pulse1->pos);					// blir 1247...
	//}else{
		//bokstav = (self->pulse2->frequency);
		//pos = (self->pulse2->pos);
	//}

	if(pos > 5){
		return;
	}
	if (pos & 0x01){
		mask = 0x0F;                /* Position 1, 3, 5 */
	}else{
		mask = 0xF0;                /* Position 0, 2, 4  */
	}
	if(bokstav<= 9 && bokstav >= 0){
		//karaktar = self->pulse1->ASCII_TABLE[(int)bokstav]; // -> samma som : (*g).ASCII_TABLE
		karaktar = ASCII_TABLE[(int)bokstav];
	}else{
		karaktar = 0x0000;
	}
	lcddr  += (pos >>1); /* (0,0,1,1,2,2) (LCDDR0, LCDDR0) (LCDDR1, LCDDR1) (LCDDR2, LCDDR2) */

	for(x = 0; x < 4; x++){
		nibbles = karaktar & 0x000f;
		karaktar = karaktar >> 4;
		if(pos & 0x01){					/* True om 1,3,5 */
			nibbles = nibbles << 4;
		}
		_SFR_MEM8(lcddr) = ((_SFR_MEM8(lcddr) & mask) | nibbles);
		lcddr += 5;
	}
}

int printAt(GUI *self, int pulseActive){
	int num;
	int pp;
	if(pulseActive == 0){
		num = self->pulse1->frequency;
		pp = 0;
		num = (((num % 100)/10));		//(num % 100) / 10 + '0', pp,	'0' = 48.
		writeChar(self, pp, num);									//&self -> address, self -> värde.
		pp = 1;
		num = ((self->pulse1->frequency % 10));				//num % 10 + '0', pp,
		writeChar(self, pp, num);
		
		//self->pulse1->frequency = num;
		//self->pulse1->pos = pp;
	}else{
		num = self->pulse2->frequency;
		pp = 3;
		num = (((num % 100)/10));		//(num % 100) / 10 + '0', pp,
		writeChar(self, pp, num);
		pp = 4;
		num = ((self->pulse2->frequency % 10));				//num % 10 + '0', pp,
		writeChar(self, pp, num);
		
		//self->pulse2->frequency = num;
		//self->pulse2->pos = pp;
	}
}

int update(GUI* self, int a){
	printAt(self, 0);
	printAt(self, 1);
}

void changegen(GUI *self, int a){
	if (self->pulseUsed == 0){
		//LCDDR16 ^= (1 << 1);	//0x1;		^ = xor -> 0 1 1 0
		//LCDDR17 ^= (4 << 0);	//0x0;
		LCDDR17 = 0x10 | LCDDR16;
		LCDDR16 = 0xFE & LCDDR17;
		self->pulseUsed = 1;
	}else if(self->pulseUsed == 1){
		//LCDDR17 ^= (4 << 1);	//0x10;
		//LCDDR16 ^= (0 << 1);	//0x0;
		LCDDR17 = 0xEF & LCDDR16;
		LCDDR16 = 0x01 | LCDDR17;
		self->pulseUsed = 0;
	}
	//update(self, a);
}

//int joystick(GUI* self, int a){
	//int b;
	//PULSEGEN* pulse;
	//if(self->pulseUsed == 0){
		//pulse = self->pulse1;
		//b = 0;
	//}else{
		//pulse = self->pulse2;
		//b = 1;
	//}
	//
	//if(((PINB >> 6) & 1) == 0 & self->buttonPrevious == 0){
		//self->buttonPrevious = 1;
		//}else if(((PINB >> 7) & 1) == 0 & self->buttonPrevious == 0){
		//self->buttonPrevious = 1;
		//}else if(((PINB >> 2) & 1) == 0 & self->buttonPrevious == 0){
		//self->buttonPrevious = 1;
		//}else if(((PINB >> 3) & 1) == 0 & self->buttonPrevious == 0){
		//self->buttonPrevious = 1;
		//}else if(((PINB >> 4) & 1) == 0 & self->buttonPrevious == 0){
		//self->buttonPrevious = 1;
	//}
	//
	//if (((PINB >> 6) & 1) == 0 & self->buttonPrevious == 1){ // Up
		//self->buttonPrevious = 0;
		//ASYNC(pulse, pulseInc, b);	
	//}
	//if ((PINB >> 7) == 0 & self->buttonPrevious == 1){
		//self->buttonPrevious = 0;
		//ASYNC(pulse, pulseDec, b);					// Down	
	//}
	//if (((PINB >> 2) & 1) == 0 & self->buttonPrevious == 1){
		//self->buttonPrevious = 0;
		//ASYNC(self, changegen, b);					// Left
		////changegen(self, b);	
	//}
	//if (((PINB >> 3) & 1) == 0 & self->buttonPrevious == 1){
		//self->buttonPrevious = 0;
		//ASYNC(self, changegen, b);					// Right
		////changegen(self, b);
	//}
	//if (((PINB >> 4) & 1) == 0 & self->buttonPrevious == 1){
		//self->buttonPrevious = 0;
		//ASYNC(pulse, SaveValue, b);					// Middle
	//}
	//update(self, a);
	//return 0;
//}

// Sätta interrupt hanteraren som ett eget objekt. InterruptHandler