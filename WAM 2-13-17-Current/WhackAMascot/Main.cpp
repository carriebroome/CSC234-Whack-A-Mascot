#include "DarkGDK.h"
#include "Global.h"
#include "Timer.h"
#include "Buttons.h"
#include "Spawn.h"
#include "Mascot.h"

Timer timer;
Buttons buttons;
Spawn spawn;

//An instance of the mascot class for each spawn point.
Mascot mascot1(1, 203, 116);
Mascot mascot2(2, 292, 135);
Mascot mascot3(3, 408, 115);
Mascot mascot4(4, 229, 194);
Mascot mascot5(5, 366, 208);
Mascot mascot6(6, 462, 181);
Mascot mascot7(7, 151, 279);
Mascot mascot8(8, 289, 273);
Mascot mascot9(9, 446, 287);

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
	dbSetImageColorKey(255, 0, 255);

//Text Settings
	dbDrawSpritesFirst();	//This allows text to be drawn on top of sprites instead of behind them
	dbSetTextSize(20);
	dbSetTextFont("Courier");
	dbInk(dbRGB(0, 0, 0), dbRGB(255, 255, 255));

//===============================================================================================================================================
//	TEXTURES AND STATIC ASSETS
//===============================================================================================================================================
	dbLoadImage("Background.png", 10); //Background
	dbSprite(10, 0, 0, 10);	//Background

//===============================================================================================================================================
//	INVISIBLE ASSETS
//===============================================================================================================================================	
	dbLoadImage("Cursor.bmp", 1);	//Cursor collider
	dbLoadImage("Button1.bmp", 2);	//Collider that spawns on top of button in background

	//These are colliders for the buttons at the bottom of background image
	dbSprite(2, 176, 372, 2);	//Pause collider
	dbSprite(3, 255, 372, 2);	//Play collider
	dbSprite(4, 486, 375, 2);	//Settings collider

//###############################################################################################################################################

	while(LoopGDK())
	{
		dbText(281, 332, dbStr(score));

		dbSprite(1, dbMouseX(), dbMouseY(), 1); //Puts cursor collider on mouse

		switch(phase) //global variable
		{
		case 1:		//initial
			buttons.buttonPause();
			buttons.buttonPlay();
			break;

		case 2:		//game has started
			
			//Timer should always be running once the game is started
			timer.initial();
			timer.run();
			timer.pauseInitial();
			timer.pauseRun();

			if (pause == 0)	//Game is playing
			{
				buttons.buttonPause();
				buttons.buttonPlay();

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

			}
			else if (pause == 1) //Game is paused
			{
				buttons.buttonPause();
				buttons.buttonPlay();
			}
			//else if (pause == 1 && settings == 1)

			break;
		}

		if (dbEscapeKey() == 1)
			break;
		
		dbSync();
	}	
}