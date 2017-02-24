#include "DarkGDK.h"
#include "Global.h"
#include "Timer.h"
#include "Buttons.h"
#include "Spawn.h"
#include "Mascot.h"
#include "HighScore.h"
#include "Settings.h"

//===============================================================================================================================================
//	CLASSES
//===============================================================================================================================================
Timer timer;
Buttons buttons;
Spawn spawn;
HighScore highScore;
Settings settings;

//===============================================================================================================================================
//	MASCOTS
//===============================================================================================================================================
Mascot mascot1(1, 202, 128);
Mascot mascot2(2, 296, 149);
Mascot mascot3(3, 407, 128);
Mascot mascot4(4, 215, 201);
Mascot mascot5(5, 358, 216);
Mascot mascot6(6, 457, 194);
Mascot mascot7(7, 159, 296);
Mascot mascot8(8, 302, 287);
Mascot mascot9(9, 452, 303);

//###############################################################################################################################################

void DarkGDK(void)
{
//===============================================================================================================================================
//	SETTINGS
//===============================================================================================================================================
//Game Settings
	dbSyncOn();
	dbSyncRate(60);			//set max frame rate
	dbDisableEscapeKey();	//disables all other functions of the escape key so you can use it in your game as exit button

//Image Settings
	//For image formats without alpha channel built in. This sets the selected color to be alpha channel.
	//dbSetImageColorKey(255, 0, 255);	//Hot pink color

//Text Settings
	dbDrawSpritesFirst();	//This allows text to be drawn on top of sprites instead of behind them
	dbSetTextFont("Courier New");
	dbInk(dbRGB(0, 0, 0), dbRGB(255, 255, 255));	//Sets text color to black

//===============================================================================================================================================
//	TEXTURES AND STATIC ASSETS
//===============================================================================================================================================
	//Background images start at 10
	dbLoadImage("TEX_Background_Field.png", 10);		//Background

	dbLoadImage("SETT_KTA_ModeSelect.png", 11);
	dbLoadImage("SETT_KTA_MascotSelect_Directions.png", 12);
	dbLoadImage("SETT_KTA_MascotSelect_Selecting.png", 13);

	dbLoadImage("SETT_HVR_ModeSelect.png", 21);
	dbLoadImage("SETT_HVR_MascotSelect_Directions.png", 22);
	dbLoadImage("SETT_HVR_MascotSelect_Selecting.png", 23);
	
	//Alpha overlays start at 30
	dbLoadImage("ALPHA_GameOverOverlay.png", 30);		//Game over overlay
	dbLoadImage("ALPHA_HighScoreOverlay.png", 31);		//High score overlay
	dbLoadImage("ALPHA_EnterInitialsOverlay.png", 32);	//High score initials overlay
	dbLoadImage("ALPHA_SelectedMascotOverlay.png", 33);	//Box that appears over selected mascot, so that player can see which is selected.

	//Mascot Tiles for Settings Menu
	dbLoadImage("TEX_DolphinTile.png", 201);
	dbLoadImage("TEX_WildcatTile.png", 202);
	dbLoadImage("TEX_BananaSlugTile.png", 203);
	dbLoadImage("TEX_MantarayTile.png", 204);
	
	//Error images start at 50
	dbLoadImage("ERR_InputValidation1.png", 50);
	dbLoadImage("ERR_InputValidation2.png", 51);

	dbSprite(10, 0, 0, 10);	//Background

//===============================================================================================================================================
//	INVISIBLE ASSETS / COLLIDERS
//===============================================================================================================================================	
	//Main invisible assets start at 1
	dbLoadImage("Cursor.bmp", 1);			//Cursor collider
	dbLoadImage("BTN_MainControls.bmp", 2);	//Collider that spawns on top of button in background

	dbLoadImage("BTN_MenuMode.png", 70);
	dbLoadImage("BTN_MenuMascotSelect.png", 71);
	dbLoadImage("BTN_MenuSettings.png", 72);
	dbLoadImage("BTN_BackToGame.png", 73);

	dbLoadImage("BTN_ModeSelection.png", 74);
	dbLoadImage("BTN_SideMenu.png", 75);
	dbLoadImage("BTN_SetMascot.png", 76);
	dbLoadImage("BTN_ClearMascot.png", 77);
	dbLoadImage("BTN_MascotSelector.png", 78);

//===============================================================================================================================================
//	MASCOT TILE IMAGES
//===============================================================================================================================================	
	dbLoadImage("TILE_Dolphin.png", 201);
	dbLoadImage("TILE_Wildcat.png", 202);
	dbLoadImage("TILE_BananaSlug.png", 203);
	dbLoadImage("TILE_Mantaray.png", 204);

//===============================================================================================================================================
//	HIGH SCORE INITIALIZATION
//===============================================================================================================================================	
	
	//Here is where you need to initials high score variables with correct info from .TXT file.



//###############################################################################################################################################

	while(LoopGDK())
	{
		dbSetTextSize(20);

		//*********Debugging stuff**********
		dbText(0, 0, dbStr(probabilitySetter));
		dbText(0, 30, dbStr(levelTime));
		dbText(0, 60, dbStr(scoreIncrement));
		dbText(0, 90, dbStr(difficultyLevel));

		//Printed information
		dbCenterText(322, 345, dbStr(score));	//Prints Score
		dbCenterText(450, 346, dbStr(missed));	//Prints Missed counter 
		dbText(460, 346, "/10");				//Prints Upper limit of missed counter
		dbCenterText(341, 18, dbStr(level));	//Prints Level
		//timerTime is printed in timer.cpp

		dbSprite(1, dbMouseX(), dbMouseY(), 1); //Puts cursor collider on mouse

		switch(phase)
		{
	//===============================================================================================================================================
	//	INITIALIZATION
	//===============================================================================================================================================	
		case 1:		//initial
			dbSprite(3, 256, 385, 2);	//Play collider
			dbSprite(5, 484, 385, 2);	//Settings collider

			startTime = dbTimer();	//Reset timer to 0

			//Change mascot states back to inactive
			hole1 = 0;
			hole2 = 0;
			hole3 = 0;
			hole4 = 0;
			hole5 = 0;
			hole6 = 0;
			hole7 = 0;
			hole8 = 0;
			hole9 = 0;

			//Make sure mascot state is updated within each class.
			mascot1.updateHoleState();
			mascot2.updateHoleState();
			mascot3.updateHoleState();
			mascot4.updateHoleState();
			mascot5.updateHoleState();
			mascot6.updateHoleState();
			mascot7.updateHoleState();
			mascot8.updateHoleState();
			mascot9.updateHoleState();

			buttons.buttonPlay();
			buttons.buttonSettings();

			//Delete button colliders
			dbDeleteSprite(2);	//pause 
			dbDeleteSprite(3);	//play
			dbDeleteSprite(4);	//reset
			dbDeleteSprite(5);	//settings
			break;

	//===============================================================================================================================================
	//	PLAYING
	//===============================================================================================================================================	
		case 2:		//game has started
			//Draw button colliders
			dbSprite(2, 176, 385, 2);	//Pause collider
			dbSprite(3, 256, 385, 2);	//Play collider
			dbSprite(4, 336, 385, 2);	//Reset collider
			dbSprite(5, 484, 385, 2);	//Settings collider

			//Timer should always be running once the game is started
			timer.initial();
			timer.run();
			timer.pauseInitial();
			timer.pauseRun();

			if (pause == 0)	//Game is playing
			{	
				//Active buttons
				buttons.buttonPause();
				buttons.buttonReset();

				//Call spawner to decide if a mascot should spawn, and if so, at what hole?
				spawn.spawnMascot();
				
				//This updates the currentState value that is used by mascotController to the current hole state value that is set by spawnMascot().
				mascot1.updateHoleState();
				mascot2.updateHoleState();
				mascot3.updateHoleState();
				mascot4.updateHoleState();
				mascot5.updateHoleState();
				mascot6.updateHoleState();
				mascot7.updateHoleState();
				mascot8.updateHoleState();
				mascot9.updateHoleState();

				//This controls the sprite creation and animations of the spawned mascots.
				mascot1.mascotController();
				mascot2.mascotController();
				mascot3.mascotController();
				mascot4.mascotController();
				mascot5.mascotController();
				mascot6.mascotController();
				mascot7.mascotController();
				mascot8.mascotController();
				mascot9.mascotController();

				//Delete button colliders
				dbDeleteSprite(2);	//pause
				dbDeleteSprite(3);	//play
				dbDeleteSprite(4);	//reset
				dbDeleteSprite(5);	//settings
			} //end if (pause = 0)

		//===============================================================================================================================================
		//	GAME OVER
		//===============================================================================================================================================	
			else if (gameOver == 1)
			{
				//Draw button colliders
				dbSprite(3, 256, 385, 2);	//Play collider
				dbSprite(4, 336, 385, 2);	//Reset collider
				dbSprite(5, 484, 385, 2);	//Settings collider

				//Delete two uppermost mascots, because otherwise they will show above the overlay
				dbDeleteSprite(101);
				dbDeleteSprite(103);
				
				if (highScoreSet == false)	//Check to see if the high score has been set yet
				{
					highScore.highScoreChecker();	//See if high score was achieved, if it was, set the correct high score.
					dbDeleteSprite(32);				//Delete the "Enter Initials" 
				}
				highScoreSet = true;

				if (highScoreCheck == true)
					dbSprite(30, 74, 100, 31);	//high score screen
				else if (highScoreCheck == false)
					dbSprite(30, 73, 99, 30);	//game over screen

		//*****************************************************HIGH SCORE TABLE***********************************************************
			//High Score 5
				dbSetTextSize(21);
				dbText(238, 184, dbUpper(initials5));									//Print initials (convert to uppercase)
				dbText(435 - dbTextWidth(dbStr(highScore5)), 184, dbStr(highScore5));	//Print Score
			//High Score 4
				dbSetTextSize(22);
				dbText(235, 207, dbUpper(initials4));
				dbText(439 - dbTextWidth(dbStr(highScore4)), 207, dbStr(highScore4));
			//High Score 3
				dbSetTextSize(23);
				dbText(232, 230, dbUpper(initials3));
				dbText(443 - dbTextWidth(dbStr(highScore3)), 230, dbStr(highScore3));
			//High Score 2
				dbSetTextSize(24);
				dbText(229, 253, dbUpper(initials2));
				dbText(446 - dbTextWidth(dbStr(highScore2)), 253, dbStr(highScore2));
			//High Score 1
				dbSetTextSize(25);
				dbText(226, 276, dbUpper(initials1));
				dbText(450 - dbTextWidth(dbStr(highScore1)), 276, dbStr(highScore1));
		//********************************************************************************************************************************

				//Active buttons
				buttons.buttonPlay();
				buttons.buttonReset();
				buttons.buttonSettings();

				//Delete button colliders
				dbDeleteSprite(2);	//pause 
				dbDeleteSprite(3);	//play
				dbDeleteSprite(4);	//reset
				dbDeleteSprite(5);	//settings

			} //end if (gameover)

		//===============================================================================================================================================
		//	PAUSED
		//===============================================================================================================================================	
			else if (pause == 1) //Game is paused
			{
				//draw button colliders
				dbSprite(3, 256, 385, 2);	//Play collider
				dbSprite(4, 336, 385, 2);	//Reset collider
				dbSprite(5, 484, 385, 2);	//Settings collider

				//active buttons
				buttons.buttonPlay();
				buttons.buttonReset();
				buttons.buttonSettings();

				//Delete button colliders
				dbDeleteSprite(2);	//pause 
				dbDeleteSprite(3);	//play
				dbDeleteSprite(4);	//reset
				dbDeleteSprite(5);	//settings
			}

		//===============================================================================================================================================
		//	SETTINGS
		//===============================================================================================================================================	
			else if (pause == 1 && settingsActive == true || phase == 1 && settingsActive == true)
			{
				settings.settingsController();			
			}
			break;

		} //End switch (phase)

//###############################################################################################################################################
		
	//===============================================================================================================================================
	//	GAME OVER CHECKER
	//===============================================================================================================================================	
		if (missed >= maxMissed)
		{
			gameOver = 1;
			pause = 1;
		}

	//===============================================================================================================================================
	//	DIFFICULTY SETTINGS / LEVELING SYSTEM
	//===============================================================================================================================================	
		//This sets the difficulty and level
		if (timerTime == levelTime + timeBetweenLevel)
		{
			if (difficultyLevel >= 1000)
				difficultyLevel -= 500;
			else if (difficultyLevel <= 500)
				difficultyLevel /= 2;

			//dbSprite(16, 0, 0, 16);	//Display Level up overlay
			scoreIncrement += 100;
			level += 1;
			/*if (probabilitySetter > 10)
				probabilitySetter -= 10;
			else if (probabilitySetter <= 10 && probabilitySetter > 1)
				probabilitySetter -= 1;
			else if (probabilitySetter <= 1)
				probabilitySetter /= 2;*/

			levelTime += timeBetweenLevel;
		} //End if

		//if (timerTime == levelTime + 2)
			//dbDeleteSprite(16);

	//===============================================================================================================================================
	//	EXIT CHECKER
	//===============================================================================================================================================	
		//Checks to see if escape key has been pressed, then breaks game loop
		if (dbEscapeKey() == 1)
			break;

		dbSync();
	} //End while loop

	//Delete all your shit here so you don't cause a memory leak...
	//You really need to do this at some point.

} //End void DarkGDK(void)