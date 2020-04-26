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
		tmpA = ~PINA; //change this back to ~PINA after testing 
		
		//2.) perform computation
		//because A only has 4 bits, should clear them to zero in case
		if ( (tmpA & 0x0F)  > 0) { //If 1 or 2, PC5 lights up  
			tmpC = tmpC | 0x20; 
		}
	       	//tmpA = ~PINA;	
		if ( (tmpA & 0x0F) >= 3 ) { //if 3 or 4, PC5 and PC4 light up  
			tmpC = tmpC | 0x10;
		}
		//tmpA = ~PINA;
		if ( (tmpA & 0x0F)  >= 5 ) { //if 5 or 6, PC5-PC3 on 
			tmpC = tmpC | 0x08;
		}
		//tmpA = ~PINA;
		if ( (tmpA & 0x0F) >= 7 ) { //7-9, PC5-PC2
			tmpC = tmpC | 0x04;
		}
		//tmpA = ~PINA;
		if ( (tmpA & 0x0F)  >= 10 ) { //10-12, PC5-PC1
			tmpC = tmpC | 0x02;
		}
		//tmpA = ~PINA;
		if ( (tmpA & 0x0F) >= 13 ) { //13-15, PC5-PC0
			tmpC = tmpC |  0x01;
		}
		
		//If tmp < 5,, light up PC6
		//tmpA = ~PINA;			
		if( (tmpA & 0x0F) < 5 ) { 
			tmpC = tmpC | 0x40;
		}
		else {	//Else keep everything the same 
			tmpC = tmpC & 0xBF;
		} 
		
		//3.) Write Output 
		PORTC = tmpC;

		tmpC = 0x00; //reset the tmp variables
		tmpA = 0x00;
    	}
    	return 1;
}
