// Sierra Palmer
// 3/28/2017

//Lab 2 Pre-lab

//Compiler directives (includes and defines)
#include "msp430.h"
#include <stdio.h>

//Function prototypes
void setupButtons();
char buttonPush();
void initLEDs()
void configUserLED(char inbits);

//global variables
char inbits;
char S1 = 0x00;	//S1 = P7.0
char S2 = 0x00;	//S2 = P3.6
char S3 = 0x00;	//S3 = P2.2
char S4 = 0x00;	//S4 = P7.4

void main(){

	void setupButtons();

	char buttonPush();

	while(1){
		configUserLED(char inbits);
	}
}

void setupButtons(){
	P7SEL &= ~(BIT4|BIT0); //Port 7, Pins 4 and 0 set to digital IO
	P3SEL &= ~BIT6;		// Port 3, Pin 6 set to digital IO	
	P2SEL &= ~BIT2;		//Port 2, Pin 2 set to digital IO
	P7DIR &= ~(BIT4|BIT0);	//set to input
	P3DIR &= ~BIT6;
	P2DIR &= ~BIT2;
	P7OUT |= (BIT4|BIT0);	//needed to use initialize pullup resistor
	P3OUT |= BIT6;
	P2OUT |= BIT2;
	P7REN |= (BIT4|BIT0);	//initialize pullup resistor
	P3REN |= BIT6;
	P2REN |= BIT2;
}

char buttonPush(){
  
  	while(1){
		if (P7IN |= BIT0){	//if S1 if pressed, return the value 
			S1 = 0x01;
		}
		if (P3IN |= BIT6){
			S2 = 0x02;
		}
		if (P2IN |= BIT2){
			S3 = 0x04;
		}
		if (P7IN |= BIT4){
			S4 = 0x08;
		}
		inbits = S1+S2+S3+S4
		return inbits;
	}
}

void initLEDs(){
	P4SEL &= ~BIT7;
	P1SEL &= ~BIT0;
	P4DIR |= BIT7;
	P1DIR |= BIT0;
	P4OUT &= ~BIT7;
	P1OUT &= ~BIT0;
}

void configUserLED(char inbits){
	// Turn on the onboard LEDs on the Launchpad located at P4.7 and 
	// P1.0

	// Input: inbits = hex values to display

	// Turn off all LEDs to start
	P4OUT &= ~BIT7;
	P1OUT &= ~BIT0;

		unsigned char mask = 0;

		if(inbits & BIT0){
			mask |= BIT7;
		}
		if(inbits & BIT1){
			mask |= BIT0;
		}
		P4OUT |= mask;
		P1OUT |= mask;
}
