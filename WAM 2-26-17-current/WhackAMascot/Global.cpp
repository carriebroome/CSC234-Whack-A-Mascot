//INITIALIZATION

//TIMER VARIABLES
bool startPauseTimer = 0;
double startTime = 0;
int pauseTime = 0;
int timerTime = 0;
double currentTime = 0;
bool first = 0;
bool pauseFirst = 0;

//GAME STATE VARIABLES
int phase = 1;
int pause = 0;
bool gameOver = 0;
bool settingsActive = false;

//BUTTONS VARIABLES
bool pressedPlayReset = 0;

//LEVELING VARIABLES
int difficultyLevel = 3000;	
int timeBetweenLevel = 20;
int levelTime = 0;
int scoreIncrement = 100;	
int maxMissed = 10;

//COUNTERS
int score = 0;
int missed = 0;
int homeHits = 0;
int level = 1;
int numMascots = 2;

//SETTINGS MENU VARIABLES
int gameMode = 1;
bool justOpened = 1;

//HIGH SCORE VARIABLES FOR KILL THEM ALL MODE
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

//HIGH SCORE VARIABLES FOR HOME VS RIVALS MODE
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

//HIGH SCORE CHECKERS FOR BOTH MODES
bool highScoreCheck = false;
bool highScoreSet = false;

//MASCOT CLASS CURRENT STATE SETTINGS
int hole1 = 0;				
int hole2 = 0;		
int hole3 = 0;
int hole4 = 0;
int hole5 = 0;
int hole6 = 0;
int hole7 = 0;
int hole8 = 0;
int hole9 = 0;

//SPRITE SETTINGS
int spriteSetting1 = 1;
int spriteSetting2 = 0;
int spriteSetting3 = 0;
int spriteSetting4 = 0;
int spriteSettingHome = 2;