#include <msp430.h>

//Function prototypes
void arrowsConfig();
char arrowsIO();

void main(){
	void arrowsConfig();

	while(1){
		arrowsIO();
	}
}

void arrowsConfig(){
	P4SEL &= ~(BIT4|BIT5);
	P1SEL &= ~BIT3;
	P2SEL &= BIT6;
	P4DIR &= ~(BIT4|BIT5);
	P1DIR &= ~BIT3;
	P2DIR &= ~(BIT4|BIT5);
	P4REN |= (BIT4|BIT5);
	P2REN |= BIT6;
	P1REN |= BIT3;
}

char arrowsIO(){
	int state;

	if(state = 1){
		return "U";
	}
	if (state = 2){
		return "L";
	if (state = 3){
		return "R";
	}
	if (state = 4){
		return "D";
	}
}