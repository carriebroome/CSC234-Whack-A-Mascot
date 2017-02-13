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
	if (dbSpriteCollision(1, 3) == 1 && dbMouseClick() == 1)
	{
		phase = 2;
		startPauseTimer = 0;
		startTime = startTime + (pauseTime * 100);
		pauseTime = 0;
		pauseFirst = 0;
		pause = 0;
	}
}
