//These variables are accessible from anywhere in the program
//Do not need to create instance of this class in main.cpp

extern int pause;				//0 = playing, 1 = paused
extern bool startPauseTimer;	//This lets the timer know whether the pause timer should be running
extern double startTime;		//This determines whether the main timer should be running
extern int pauseTime;			//
extern bool pauseFirst;			//Checks to see if initializer for pause timer has run already.
extern int timerTime;			//
extern double currentTime;		//
extern int phase;				//The phase in which the game is in (paused, playing, settings, etc)
extern int difficultyLevel;		//Sets how long mascots stay up
extern int score;				//to keep current score
extern int scoreIncrement;

//These variables are set from the currentState variable in Mascot.h
//They control what is happening at each hole at any given time

								//NUMBER KEY
extern int hole1;				//0 = hole inactive
extern int hole2;				//1 = hole activated - set start time
extern int hole3;				//2 = mascot up animation playing
extern int hole4;				//3 = still image of mascot for set amount of time
extern int hole5;				//4 = mascot down animation playing
extern int hole6;				//5 = mascot kill animation playing
extern int hole7;				//6 = mascot interrupted kill animation playing
extern int hole8;				//7 = delete sprite, reset to inactive
extern int hole9;