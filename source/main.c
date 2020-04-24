/*	Author: Alfredo Gonzalez
 *  Partner(s) Name: 
 *	Lab Section: 028
 *	Assignment: Lab # 5  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	LINK: 
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
/* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;	
	//Makes all port A's input pins as inputs; initalized to 1s
	DDRC = 0xFF; PORTC = 0x00;	
	//Makes all port B's input pins as outputs; initalized to 0s

	unsigned char tmpA = 0x00; 
	unsigned char tmpC = 0x00;

	/* Insert your solution below */
    	while (1) {
		//1.)read inputi
		tmpA = ~PINA; 
		
		//2.) perform computation
		if ( (tmpA <= 2) && (tmpA > 0)) { //If 1 or 2, PC5 lights up 0010 0000 
			tmpC = (tmpC & 0x20) | 0x20; 
		}
	       	//	tmpA = ~PINA;	
		else if ( tmpA <= 4 ) { //if 3 or 4, PC5 and PC4 light up  0011 0000
			tmpC = (tmpC & 0x30) | 0x30;
		}
		//tmpA = ~PINA;
		else if ( tmpA <= 6 ) { //if 5 or 6, PC5-PC3 on 0011 1000 
			tmpC = (tmpC & 0x38) | 0x38;
		}
		//tmpA = ~PINA;
		else if ( tmpA <= 9 ) { //7-9, PC5-PC2 0011 1100
			tmpC = (tmpC & 0x3C) | 0x3C;
		}
		//tmpA = ~PINA;
		else if ( tmpA <= 12 ) { //10-12, PC5-PC1 0011 1110
			tmpC = (tmpC & 0x3E) | 0x3E;
		}
		//tmpA = ~PINA;
		else if ( tmpA <= 15) { //13-15, PC5-PC0 0011 1111
			tmpC = (tmpC & 0x3F) | 0x3F;
		}
		else {	//else just set it to 0
			tmpC = tmpC & 0x00;
		}

		
		//If tmp < 5,, light up PC6
		//tmpA = ~PINA;			
		if( tmpA < 5 ) { 
			tmpC = tmpC | 0x40;
		}
		else {	//Else keep everything the same 
			tmpC = tmpC & 0xBF;
		} 
		
		//3.) Write Output 
		PORTC = tmpC;
    	}
    	return 1;
}
