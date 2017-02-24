#include "DarkGDK.h"
#include "Buttons.h"
#include "Global.h"

//===============================================================================================================================================
//	PAUSE BUTTON
//===============================================================================================================================================
void Buttons::buttonPause()
{
	if (dbSpriteCollision(1, 2) == 1 && dbMouseClick() == 1) //pause collider and cursor collision
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
	if (dbSpriteCollision(1, 3) == 1 && dbMouseClick() == 1 && gameOver == 1)
	{
		pressedPlayReset = 1;
		buttonReset();
	}
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
		//Delete all the mascots
		for (int x = 101; x < 110; x++)
		{
			dbDeleteSprite(x);
		}

		//delete game over overlay image
		dbDeleteSprite(30);
		
		//reset game state variables
		missed = 0;
		score = 0;
		gameOver = 0;
		levelTime = 0;
		level = 1;
		difficultyLevel = 3000;
		scoreIncrement = 100;

		highScoreSet = false;
		
		//reset timer variables
		phase = 1;
		first = 0;
		timerTime = 0;
		currentTime = 0;
		pause = 0;

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
		buttonReset();
		
		justOpened = true;
		settingsActive = true;

	}
}