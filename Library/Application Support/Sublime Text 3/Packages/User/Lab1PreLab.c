#import <stdio.h>

void main(void)
{

    unsigned char currKey=0, dispSz = 3;
    unsigned char dispThree[3];

    // Useful code starts here
    initLeds();

    configDisplay();
    configKeypad();

  	// *** Intro Screen ***

    GrClearDisplay(&g_sContext); // Clear the display

    // Write some text to the display
  	GrStringDrawCentered(&g_sContext, "SIMON", AUTO_STRING_LENGTH, 48, 15, TRANSPARENT_TEXT);
  	GrStringDrawCentered(&g_sContext, "PRESS * TO PLAY", AUTO_STRING_LENGTH, 48, 25, TRANSPARENT_TEXT);

  	GrFlush(&g_sContext);


    dispThree[0] = ' ';
    dispThree[2] = ' ';

    while (1)    // Forever loop
  	{
  		// This code is for the 3 x 4 keypad
  		currKey = getKey();
  		if ((currKey >= '0') & (currKey <= '9'))
  		   setLeds(currKey - 0x30);
  		if (currKey == '*')
  			newCountdown();
  		

  		if (currentstate == 0){
  			welcomeScreen(); //display "SIMON" and "PRESS * TO START"
                         //if '*' is pressed, move to state 1
  		}
  		else if (currentstate == 1){
  			newCountdown();  //display countdown
                         //go straight into state 2
  		}
  		else if (currentstate == 2){
  			ledSequence(); //randomize sequence, play buzzer with lit
  						         // LEDs and save to memory
  		}
  		else if (currentstate == 3){
  			checkButton();	//check to see if player input matches
  							        //given sequence, 
                        //if correct and sequenceLength < 32, return to state 2
                        //if correct and sequenceLength = 32, move to state 5
                        //if incorrect, go to state 4
  		}
      else if (currentstate == 4){
        playerHumiliation(); //gives random jeers for wrong answer
                              //resets to state 0
      }
      else if (currentstate == 5){
        playerCongrats(); //displays "CONGRATS YOU WON!"
                          //Resets to state 0
      }
  			 
  		}

  	}  // end while (1)}
