#include "DarkGDK.h"
#include "Timer.h"
#include "Global.h"

//===============================================================================================================================================
//	MAIN TIMER
//===============================================================================================================================================
//Initial makes the timer get time in seconds 
//and start at 0 instead of current time in milliseconds (crazy number)

void Timer::initial()
{	
	if (pause == 0 && first != 1)	//if game is not paused and inital has not run.
	{	
		startTime = dbTimer();		//sets the starting time
		first = 1;					//Makes sure initial won't run again
	}
}

void Timer::run()	//This is actual timer.
{
	if (pause != 1)	//Is game paused?
	{	
		currentTime = (dbTimer() - startTime) / 1000;	//subtract start time, so that it starts at 0 - then convert to seconds
		timerTime = currentTime - pauseTime;			//subtract pause time, so that timer effectively isn't going while game is paused
	}

	//Print timer in Time box
	dbCenterText(170, 346, dbStr(timerTime));
}
//===============================================================================================================================================
//	PAUSE TIMER
//===============================================================================================================================================
//Pause timer runs while game is paused so that the total time paused can be subtracted from the main timer.
//This is necessary for the timer to not be able to increment while the game is paused.
//Pause timer is reset to 0 every time it is called.

void Timer::pauseInitial()
{	
	if (pauseFirst != 1 && startPauseTimer == 1)
	{
		pauseStartTime = dbTimer();		//get starting time for timer
		pauseFirst = 1;					//don't run this again until you need to reinitialize
	}
}

void Timer::pauseRun()
{
	if (startPauseTimer == 1)
	{
		pauseCurrentTime = (dbTimer() - pauseStartTime) / 1000;		//start at 0, convert to seconds
		pauseTime = pauseCurrentTime;								//convert from double to int
	}
}