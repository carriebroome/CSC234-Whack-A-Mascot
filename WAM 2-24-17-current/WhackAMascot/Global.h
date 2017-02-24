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
extern bool first;
extern bool pressedPlayReset;

extern int difficultyLevel;		//Sets how long mascots stay up
extern int probabilitySetter;	//Used in Spawn to set probability of mascots spawning
extern int timeBetweenLevel;	//How much time between levels
extern int levelTime;
extern int level;
extern int score;				//to keep current score
extern int scoreIncrement;		//how much score goes up each time
extern int missed;				//counts how many mascots you have missed
extern int maxMissed;			//The maximum number of mascots you can miss
extern bool gameOver;			//Is the game over?



//Settings Menu
extern bool settingsActive;
extern int gameMode;			//1 = "Kill Them All" mode  2 = "Home VS Rivals" mode
extern bool justOpened;			//Did you just open the settings menu, or has it been open, default = 1 = justopened, 0 = been open




//HIGH SCORE VARIABLES
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

extern bool highScoreCheck;
extern bool highScoreSet;

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

//These will be used when settings menu is implemented to allow user to set which mascots should pop up.
extern int spriteSetting1;
extern int spriteSetting2;
extern int spriteSetting3;
extern int spriteSetting4;

extern int spriteSettingHome;