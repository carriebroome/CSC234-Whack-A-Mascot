//These variables are accessible from anywhere in the program
//Do not need to create instance of this class in main.cpp - just include it

//TIMER VARIABLES - USED MAINLY IN TIMER CLASS
extern bool startPauseTimer;	//This lets the timer know whether the pause timer should be running
extern double startTime;		//Time when the timer was first started. -initializer
extern int pauseTime;			//Gets the time for which the game is paused
extern int timerTime;			//This is the output variable, after all math and conversions (to seconds) have been made
extern double currentTime;		//The raw current time - before conversions to seconds and math (pause timer) have been done
extern bool first;				//this checks to see if the main timer has been initialized
extern bool pauseFirst;			//Checks to see if initializer for pause timer has run already.

//GAME STATE VARIABLES
extern int phase;				//The phase in which the game is in (paused, playing, settings, etc)
extern int pause;				//0 = playing, 1 = paused
extern bool gameOver;			//Is the game over? 0 = no, 1 = yes
extern bool settingsActive;		//Checker variable set to make the settings menu appear

//BUTTONS VARIABLES
extern bool pressedPlayReset;	//If play was pressed in order to reset the game

//LEVELING VARIABLES
extern int difficultyLevel;		//Sets how long mascots stay up (ms) - this is then divided by 10 for the still animation delay time
extern int timeBetweenLevel;	//How much time between levels (default 20 seconds)
extern int levelTime;			//Time the next level up should happen
extern int scoreIncrement;		//how much score goes up each time
extern int maxMissed;			//The maximum number of mascots you can miss

//COUNTERS
extern int score;				//to keep current score - regardless of game mode
extern int missed;				//counts how many mascots you have missed in either game mode
extern int homeHits;			//Number of home mascots hit in HomeVsRivals mode
extern int level;				//Current level counter - increments every 20 seconds.
extern int numMascots;			//Counts the number of mascots in settings slots - used when spawning

//SETTINGS MENU VARIABLES
extern int gameMode;			//1 = "Kill Them All" mode  2 = "Home VS Rivals" mode
extern bool justOpened;			//Did you just open the settings menu, or has it been open, 1 = just opened, 0 = been open

//HIGH SCORE VARIABLES FOR KILL THEM ALL MODE
extern int highScore1;
extern int highScore2;
extern int highScore3;
extern int highScore4;
extern int highScore5;
extern char* initials1;
extern char* initials2;
extern char* initials3;
extern char* initials4;
extern char* initials5;

//HIGH SCORE VARIABLES FOR HOME VS RIVALS MODE
extern int hvrHighScore1;
extern int hvrHighScore2;
extern int hvrHighScore3;
extern int hvrHighScore4;
extern int hvrHighScore5;
extern char* hvrInitials1;
extern char* hvrInitials2;
extern char* hvrInitials3;
extern char* hvrInitials4;
extern char* hvrInitials5;

//HIGH SCORE CHECKERS FOR BOTH MODES
extern bool highScoreCheck;		//Checked 1 if high score was made, 0 if not.
extern bool highScoreSet;		//If a high score was made, has it been set yet?

//These variables are set from the currentState variable in Mascot.h
//They control what is happening at each hole at any given time
extern int hole1;				//NUMBER KEY - DETERMINES STATE
extern int hole2;				//0 = hole inactive
extern int hole3;				//1 = hole activated
extern int hole4;				//2 = mascot up animation playing
extern int hole5;				//3 = still animation playing - time determined by difficultylevel
extern int hole6;				//4 = mascot down animation playing
extern int hole7;				//5 = mascot kill animation playing
extern int hole8;				//6 = mascot interrupted kill animation playing
extern int hole9;				//7 = delete sprite, reset to inactive

//SPRITE SETTINGS - These variables hold the mascotID for each mascot set by the user.
extern int spriteSetting1;
extern int spriteSetting2;
extern int spriteSetting3;
extern int spriteSetting4;
extern int spriteSettingHome;