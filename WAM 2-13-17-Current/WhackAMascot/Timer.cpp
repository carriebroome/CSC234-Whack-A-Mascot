#include "DarkGDK.h"
#include "Timer.h"
#include "Global.h"

//===============================================================================================================================================
//	MAIN TIMER
//===============================================================================================================================================
bool first = 0;	//Decides whether or not initial needs to run. (is is the first time the timer has been called?)

//Initial makes the timer get time in seconds 
//and start at 0 instead of current time in milliseconds (crazy number)
int Timer::initial()
{	
	if (pause == 0 && first != 1)	//if game is not paused and inital has not run.
	{	
		startTime = dbTimer();	//Creates timer
		first = 1;				//Makes sure initial won't run again
	}
	return 0;
}

int Timer::run()	//This is actual timer.
{
	if (pause != 1)	//Is game paused?
	{	
		currentTime = (dbTimer() - startTime) / 100;
		timerTime = currentTime - pauseTime;
	}

//XXXXXXXXXXXXX
//For debugging
	dbText(0,0,"Time:");
	dbText(0,30,dbStr(timerTime));
//xxxxxxxxxxxxx

	return 0;
}
//===============================================================================================================================================
//	PAUSE TIMER
//===============================================================================================================================================
//Pause timer runs while game is paused so that the total time paused can be subtracted from the main timer.
//This is necessary for the timer to not be able to increment while the game is paused.
//Pause timer is reset to 0 every time it is called.

int Timer::pauseInitial()
{	
	if (pauseFirst != 1 && startPauseTimer == 1)
	{
		pauseStartTime = dbTimer();
		pauseFirst = 1;	
	}
	return 0;
}

int Timer::pauseRun()
{
	if (startPauseTimer == 1)
	{
		pauseCurrentTime = (dbTimer() - pauseStartTime) / 100;
		pauseTime = pauseCurrentTime;
	}
	return 0;
}