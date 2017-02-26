#include "DarkGDK.h"
#include "Buttons.h"
#include "Global.h"

//===============================================================================================================================================
//	PAUSE BUTTON
//===============================================================================================================================================
void Buttons::buttonPause()
{
	if (dbSpriteCollision(1, 2) == 1 && dbMouseClick() == 1)
	{
		pause = 1;
		startPauseTimer = 1;
	}
}

//===============================================================================================================================================
//	PLAY BUTTON
//===============================================================================================================================================
void Buttons::buttonPlay()
{
	//This is so that you can press play to reset the game when the game is over - instead of reset button
	if (dbSpriteCollision(1, 3) == 1 && dbMouseClick() == 1 && gameOver == 1)
	{
		//This kicks down to the reset button, then since the playreset checker is on, it will get reset in settings, 
		//then kicked back up to play button, but the regular play button will run this time.
		pressedPlayReset = 1;
		buttonReset(); 
	}
	//This is the normal play button which starts the game.
	else if (dbSpriteCollision(1, 3) == 1 && dbMouseClick() == 1)
	{
		phase = 2;
		startPauseTimer = 0;
		startTime = startTime + (pauseTime * 1000);
		pauseTime = 0;
		pauseFirst = 0;
		pause = 0;
	}
}

//===============================================================================================================================================
//	RESET BUTTON
//===============================================================================================================================================
void Buttons::buttonReset()
{
	if ((dbSpriteCollision(1, 4) == 1 && dbMouseClick() == 1) || pressedPlayReset == 1)
	{
//??????????????????????????????????????????????????
		//Delete all the mascots
		//This is the only thing I had originally, and for the most part it works fine
		//The only time it seems to not work is when you press reset in the instant a mascot spawns
		for (int x = 101; x < 110; x++)	//These sprite ID's are set in the explicit constructor of the mascot class. Should be (101 - 109)
		{
			dbDeleteSprite(x);
		}

		//added this here after success with hiding mascots in main.cpp. 
		//this does not work - problem persists
		for (int z = 101; z < 110; z++)
		{
			dbHideSprite(z);
		}
//??????????????????????????????????????????????????

		//delete game over overlay image
		dbDeleteSprite(30);
		
		//reset game state variables
		missed = 0;
		homeHits = 0;
		score = 0;
		gameOver = 0;
		levelTime = 0;
		level = 1;
		difficultyLevel = 3000;
		scoreIncrement = 100;

		//this makes it to where the next high score can be set
		highScoreSet = false;
		
		//reset timer variables
		phase = 1;	//INIT phase
		first = 0;
		timerTime = 0;
		currentTime = 0;
		pause = 0;

		//This is for if the play button is pressed to reset the game when the game is over.
		if (pressedPlayReset == 1)	//Send back to play function so that it starts playing automatically.
		{
			pressedPlayReset = 0;
			buttonPlay();
		}
	}
}

//===============================================================================================================================================
//	SETTINGS BUTTON
//===============================================================================================================================================
void Buttons::buttonSettings()
{
	if (dbSpriteCollision(1, 5) == 1 && dbMouseClick() == 1)
	{
		dbDeleteSprite(2);
		dbDeleteSprite(3);
		dbDeleteSprite(4);
		dbDeleteSprite(5);

		//RESET BUTTON STUFF. Could not call reset button from this correctly
		
		//Delete all the mascots
		for (int x = 101; x < 110; x++)
		{
			dbDeleteSprite(x);
		}

		//delete game over overlay image
		dbDeleteSprite(30);
		
		//reset game state variables
		missed = 0;
		homeHits = 0;
		score = 0;
		gameOver = 0;
		levelTime = 0;
		level = 1;
		difficultyLevel = 3000;
		scoreIncrement = 100;
		highScoreSet = false;
		
		//reset timer variables
		phase = 3;	//This is the phase for settings
		first = 0;
		timerTime = 0;
		currentTime = 0;
		pause = 0;
		
		//SETTINGS MENU VARIABLES
		justOpened = true;
		settingsActive = true;
	}
}