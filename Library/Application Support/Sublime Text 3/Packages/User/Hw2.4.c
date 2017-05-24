
/*Compiler directives (includes and defines) */
#include "msp430.h"

//Function prototypes
void setupP2_P3();
void in2_out3();

void setupP2_P3(){
	int input = 0; //gives state of the switch

	P3SEL &= ~(BIT3|BIT2|BIT1|BIT0);
	P3DIR |= (BIT3|BIT2|BIT1|BIT0);
	P2SEL &= ~(BIT7|BIT6|BIT5|BIT4);
	P2DIR |= (BIT7|BIT6|BIT5|BIT4);
	P2REN |= (BIT7|BIT6|BIT5|BIT4);
	P2OUT &= ~(BIT7|BIT6|BIT5|BIT4);
	
	if (input == 0){
		P2IN &= ~(BIT7|BIT6|BIT5|BIT4);
	} else {
		P2IN |= (BIT7|BIT6|BIT5|BIT4);
	}

}

void in2_out3(){
	if (P2IN &= ~(BIT7|BIT6|BIT5|BIT4))
	{
		P3OUT |= (BIT3|BIT2|BIT1|BIT0);
	} else {
		P3OUT &= ~(BIT3|BIT2|BIT1|BIT0);
	}
}

void main(){
	setupP2_P3();
	while(1){
		in2_out3();
	}
}