//Initialization of Global.h variables
//===============================================================================================================================================
//	TABLE OF WHERE VARIABLES ARE USED IN GAME
//===============================================================================================================================================
//Variable						Main   Buttons	Timer   Spawn	Mascot
//-----------------------------------------------------------------------
int pause = 0;				//	  		  X		  X		  X
bool startPauseTimer = 0;	//			  X		  X
double startTime = 0;		//			  X		  X
int pauseTime = 0;			//			  X		  X
bool pauseFirst = 0;		//			  X		  X
int timerTime = 0;			//					  X
double currentTime = 0;		//					  X
int phase = 1;				//			  X	
bool first = 0;
bool pressedPlayReset = 0;

int difficultyLevel = 3000;	//									  X
int probabilitySetter = 100;//    X						  X
int timeBetweenLevel = 20;
int levelTime = 0;
int level = 1;
int score = 0;				//	  X								  X
int scoreIncrement = 100;	//									  X
int missed = 0;				//	  X								  X
int maxMissed = 10;
bool gameOver = 0;



//Settings Menu
bool settingsActive = false;
int gameMode = 1;
bool justOpened = 1;



int hole1 = 0;				//							  X		  X
int hole2 = 0;				//							  X		  X
int hole3 = 0;				//							  X		  X
int hole4 = 0;				//							  X		  X
int hole5 = 0;				//							  X		  X
int hole6 = 0;				//							  X		  X
int hole7 = 0;				//							  X		  X
int hole8 = 0;				//							  X		  X
int hole9 = 0;				//							  X		  X

//High score variables for "Kill Them All" mode.
int highScore1 = 100;
int highScore2 = 100;
int highScore3 = 100;
int highScore4 = 100;
int highScore5 = 100;
char* initials1 = "AAA";
char* initials2 = "AAA";
char* initials3 = "AAA";
char* initials4 = "AAA";
char* initials5 = "AAA";

//Hich score variables for "Home VS. Rivals" mode.
int hvrHighScore1 = 100;
int hvrHighScore2 = 100;
int hvrHighScore3 = 100;
int hvrHighScore4 = 100;
int hvrHighScore5 = 100;
char* hvrInitials1 = "AAA";
char* hvrInitials2 = "AAA";
char* hvrInitials3 = "AAA";
char* hvrInitials4 = "AAA";
char* hvrInitials5 = "AAA";

bool highScoreCheck = false;
bool highScoreSet = false;

//Sprite settings - set by user
int spriteSetting1 = 0;
int spriteSetting2 = 0;
int spriteSetting3 = 0;
int spriteSetting4 = 0;

int spriteSettingHome = 1;