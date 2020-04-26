/*	Author: agonz250
 *  Partner(s) Name: 028 
 *	Lab Section:
 *	Assignment: Lab # 5  Exercise # 3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *	VIDEO LINK: https://drive.google.com/file/d/1zKksD4DJsYGar7nylRFTYZmx4q57SiDX/view?usp=sharing
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {Start, A, Await, B, Bwait, C, Cwait, D, Dwait} state; 

unsigned char tmpA; //global variables 
unsigned char tmpB;

void Tick() {
	switch(state) { //transitions
		case Start: 
			state = A;
			break;
		case A:
			if ((tmpA & 0x01) == 0x01) { //If PA0
				state = Await;
				//i = 0;
			}
			else {
				state = A;
			}
			break;

		case Await:
			if ((tmpA & 0x01) == 0x01) { //If PA0
				state = Await;
			}
			else {
				state = B;
			}
			break;

		case B: 
			if ((tmpA & 0x01) == 0x01) { //If PA0
				state = Bwait;
			}
			else {
				state = B;
			}
			break;

		case Bwait:
			if ((tmpA & 0x01) == 0x01) { //If PA0
				state = Bwait;
			}
			else {
				state = C;
			}
			break;

		case C: 
			if ((tmpA & 0x01) == 0x01) { //If PA0
				state = Cwait;
			}
			else {
				state = C;
			}
			break;


		case Cwait:
			if ((tmpA & 0x01) == 0x01) { //If PA0
				state = Cwait;
			}
			else {
				state = D;
			}
			break;


		case D: 
			if ((tmpA & 0x01) == 0x01) { //If PA0
				state = Dwait;
			}
			else {
				state = D;
			}
			
			break;


		case Dwait:
			if ((tmpA & 0x01) == 0x01) { //If PA0
				state = Dwait;
			}
			else {
				state = A;
			}
			break;
		default: 
			//shouldn't go here
			state = Start;
			break;					
	}

	switch(state) { 	
		case A: 
			tmpB = (tmpB & 0x00) | 0x30;
			break;

		case B:
			tmpB = (tmpB & 0x00) |  0x0C;
			break;
		case C: 
			tmpB = (tmpB & 0x00) | 0x03;
			break;

		case D: 
			tmpB = (tmpB & 0x00) | 0x0C;
			break;
		default:
			tmpB = 0x00;
			break;
	}
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; //Makes all As as input
	DDRB = 0xFF; PORTB = 0x00; //Makes all C pins as output	
	
	tmpB = 0x00;
	state = Start;  
	/* Insert your solution below */
    	while (1) {
		//read inputs
		tmpA = ~PINA; 

		Tick(); 
	
		//write output
		PORTB = tmpB;		
    	}
    	return 1;
}
