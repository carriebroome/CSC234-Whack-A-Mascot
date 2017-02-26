#include "DarkGDK.h"
#include "Settings.h"
#include "Global.h"

//===============================================================================================================================================
//	SCREEN SELECT
//===============================================================================================================================================
void Settings::screenSelect()
{
	switch (currentScreen)
	{
	//===============================================================================================================================================
	//	MODE SELECT
	//===============================================================================================================================================
	case 1:	//KTA Mode Select Screen
		dbDeleteSprite(200);
		dbSprite(200, 0, 0, 11);	//Background
		
		dbSprite(210, 225, 218, 74);	//Kill Them All Button collider
		dbSprite(211, 225, 254, 74);	//Home VS Rivals Button collider

		drawSideMenuMascots();	//Draws sprites for the side panel mascots that are selected.

		break;

	case 2: //HVR Mode Select Screen
		dbDeleteSprite(200);
		dbSprite(200, 0, 0, 21);

		dbSprite(210, 225, 218, 74);	//Kill Them All Button collider
		dbSprite(211, 225, 254, 74);	//Home VS Rivals Button collider

		drawSideMenuMascots();	//Draws sprites for the side panel mascots that are selected.

		break;

	//===============================================================================================================================================
	//	MASCOT SELECT - DIRECTIONS
	//===============================================================================================================================================
	case 11://KTA Mascot Directions Screen
		dbDeleteSprite(200);
		dbSprite(200, 0, 0, 12);
		
		drawSideMenuButtons();
		drawSideMenuMascots();

		break;

	case 12://HVR Mascot Directions Screen
		dbDeleteSprite(200);
		dbSprite(200, 0, 0, 22);

		drawSideMenuButtons();
		drawSideMenuMascots();

		break;

	//===============================================================================================================================================
	//	MASCOT SELECT - SELECTING
	//===============================================================================================================================================
	case 21://KTA Mascot Selection Screen
		dbDeleteSprite(200);
		dbSprite(200, 0, 0, 13);
		
		drawSideMenuButtons();
		drawSideMenuMascots();

		drawMascotSelectionPanel();

		//ALPHA overlay for selected slot
		switch (selectedSlot)
		{
		case 1:
			dbDeleteSprite(225);
			dbSprite(225, 10, 79, 33);
			break;
		case 2:
			dbDeleteSprite(225);
			dbSprite(225, 10, 149, 33);
			break;
		case 3:
			dbDeleteSprite(225);
			dbSprite(225, 10, 219, 33);
			break;
		case 4:
			dbDeleteSprite(225);
			dbSprite(225, 10, 289, 33);
			break;
		}

		dbSprite(220, 274, 371, 76);	//Set Mascot button
		dbSprite(221, 377, 371, 77);	//Clear Mascot button

		break;

	case 22://HVR Mascot Selection Screen
		dbDeleteSprite(200);
		dbSprite(200, 0, 0, 23);

		drawSideMenuButtons();
		drawSideMenuMascots();

		drawMascotSelectionPanel();

		//ALPHA overlay for selected slot.
		switch (selectedSlot)
		{
		case 1:
			dbDeleteSprite(225);
			dbSprite(225, 10, 79, 33);
			break;
		case 2:
			dbDeleteSprite(225);
			dbSprite(225, 10, 149, 33);
			break;
		case 3:
			dbDeleteSprite(225);
			dbSprite(225, 10, 219, 33);
			break;
		case 4:
			dbDeleteSprite(225);
			dbSprite(225, 10, 289, 33);
			break;
		case 5:
			dbDeleteSprite(225);
			dbSprite(225, 572, 81, 33);
			break;
		}

		dbSprite(220, 274, 371, 76);	//Set Mascot button
		dbSprite(221, 377, 371, 77);	//Clear Mascot button

		break;
	} //End Switch (currentScreen)

} //End Function Screen Select

//===============================================================================================================================================
//	SETTINGS CONTROLLER
//===============================================================================================================================================
void Settings::settingsController()
{
	if (justOpened == true)
	{
		justOpened = false;	//Makes sure this segment won't run again until settings is closed and then opened again.

		if (gameMode == 1)
		{
			currentScreen = 1;	//KTA Mode Select Screen
			screenSelect();
			screenRedraw = false;
		}
		else if (gameMode == 2)
		{
			currentScreen = 2;	//HVR Mode Select Screen
			screenSelect();
			screenRedraw = false;
		}
		
	} //End if (justOpened = 1)

	switch (currentScreen)
	{
	//===============================================================================================================================================
	//	MODE SELECT
	//===============================================================================================================================================
	case 1:	//KTA Mode Select
		if (screenRedraw == true)
		{
			screenSelect();
			screenRedraw = false;
		}
		mainMenuController();

		//If HVT MODE button is pressed
		if (dbSpriteCollision(1, 211) == 1 && dbMouseClick() == 1 && gameMode == 1)
		{
			gameMode = 2;
			currentScreen = 2;
			screenRedraw = true;

			spriteSetting1 = 1;
			spriteSetting2 = 0;
			spriteSetting3 = 0;
			spriteSetting4 = 0;
			spriteSettingHome = 2;
			deleteAll();
		}

		break;

	case 2: //HVT Mode Select
		if (screenRedraw == true)
		{
			screenSelect();
			screenRedraw = false;
		}
		mainMenuController();

		//If KTA MODE button is pressed
		if (dbSpriteCollision(1, 210) == 1 && dbMouseClick() == 1 && gameMode == 2)
		{
			gameMode = 1;
			currentScreen = 1;
			screenRedraw = true;
			
			spriteSetting1 = 1;
			spriteSetting2 = 0;
			spriteSetting3 = 0;
			spriteSetting4 = 0;
			spriteSettingHome = 0;
			deleteAll();
		}
		break;

	//===============================================================================================================================================
	//	MASCOT DIRECTIONS
	//===============================================================================================================================================
	case 11: //KTA Mascot Directions
		if (screenRedraw == true)
		{
			screenSelect();
			screenRedraw = false;
		}
		mainMenuController();
		sideMenuController();
		break;

	case 12: //HVR Mascot Directions
		if (screenRedraw == true)
		{
			screenSelect();
			screenRedraw = false;
		}
		mainMenuController();
		sideMenuController();
		break;

	//===============================================================================================================================================
	//	MASCOT SELECTION
	//===============================================================================================================================================
	case 21: //KTA Mascot Selection
		if (screenRedraw == true)
		{
			screenSelect();
			screenRedraw = false;
		}
		mainMenuController();
		sideMenuController();

		mascotSelectionPanelController();

		//===============================================================================================================================================
		//	SET MASCOT BUTTON
		//===============================================================================================================================================
		if (dbSpriteCollision(1, 220) == 1 && dbMouseClick() == 1)
		{
			switch (selectedSlot)
			{
			case 1:
				spriteSetting1 = selectedMascot;
				currentScreen = 11;
				screenRedraw = true;
				deleteAll();
				break;
			case 2:
				spriteSetting2 = selectedMascot;
				currentScreen = 11;
				screenRedraw = true;
				deleteAll();
				break;
			case 3:
				spriteSetting3 = selectedMascot;
				currentScreen = 11;
				screenRedraw = true;
				deleteAll();
				break;
			case 4:
				spriteSetting4 = selectedMascot;
				currentScreen = 11;
				screenRedraw = true;
				deleteAll();
				break;
			} //End switch (slectedSlot)
		}

		//===============================================================================================================================================
		//	CLEAR MASCOT BUTTON
		//===============================================================================================================================================
		else if (dbSpriteCollision(1, 221) == 1 && dbMouseClick() == 1)
		{
			selectedMascot = 0;		//Make slot inactive
			dbDeleteSprite(240);	//ALPHA overlay
		}

		break;
		
	case 22: //HVR Mascot Selection
		if (screenRedraw == true)
		{
			screenSelect();
			screenRedraw = false;
		}
		mainMenuController();
		sideMenuController();

		mascotSelectionPanelController();

		//===============================================================================================================================================
		//	SET MASCOT BUTTON
		//===============================================================================================================================================

		if (dbSpriteCollision(1, 220) == 1 && dbMouseClick() == 1)
		{
			switch (selectedSlot)
			{
			case 1:
				if (spriteSettingHome != selectedMascot)
				{
					spriteSetting1 = selectedMascot;
					currentScreen = 12;
					screenRedraw = true;
					deleteAll();
				}
				break;
			case 2:
				if (spriteSettingHome != selectedMascot)
				{
					spriteSetting2 = selectedMascot;
					currentScreen = 12;
					screenRedraw = true;
					deleteAll();
				}
				break;
			case 3:
				if (spriteSettingHome != selectedMascot)
				{
					spriteSetting3 = selectedMascot;
					currentScreen = 12;
					screenRedraw = true;
					deleteAll();
				}
				break;
			case 4:
				if (spriteSettingHome != selectedMascot)
				{
					spriteSetting4 = selectedMascot;
					currentScreen = 12;
					screenRedraw = true;
					deleteAll();
				}
				break;
			case 5:
				if (spriteSetting1 != selectedMascot && spriteSetting2 != selectedMascot && spriteSetting3 != selectedMascot && spriteSetting4 != selectedMascot && selectedMascot != 0)
				{
					spriteSettingHome = selectedMascot;
					currentScreen = 12;
					screenRedraw = true;
					deleteAll();
				}
				else if (spriteSetting1 == selectedMascot || spriteSetting2 == selectedMascot || spriteSetting3 == selectedMascot || spriteSetting4 == selectedMascot)
				{
					//ERROR - You cannot choose a mascot for home that has already been selected as a rival
					dbText(0, 0, "ERROR");
				}
				else if (selectedMascot == 0)
				{
					//ERROR - You must select a mascot for the home mascot in the current game mode
					dbText(0, 0, "ERROR");
				}
			} //End switch (slectedSlot)
		}

		//===============================================================================================================================================
		//	CLEAR MASCOT BUTTON
		//===============================================================================================================================================
		else if (dbSpriteCollision(1, 221) == 1 && dbMouseClick() == 1)
		{
			selectedMascot = 0;		//Make slot inactive
			dbDeleteSprite(240);	//ALPHA overlay
		}
		break;
	} // End Switch (currentScreen)
} //End Function settingsController()

//===============================================================================================================================================
//	MAIN MENU CONTROLLER
//===============================================================================================================================================
void Settings::mainMenuController()
{
	//Draw the colliders for the main menu
	dbSprite(201, 124, 36, 70);		//draw mode button
	dbSprite(202, 251, 35, 71);		//draw mascot select button
	dbSprite(203, 387, 35, 72);		//draw settings button
	dbSprite(204, 537, 308, 73);	//draw back to game button

	//===============================================================================================================================================
	//	MODE SELECT
	//===============================================================================================================================================
	if (dbSpriteCollision(1, 201) == 1 && dbMouseClick() == 1)
	{
		if (gameMode == 1)
		{
			currentScreen = 1;
		}
		else if (gameMode == 2)
		{
			currentScreen = 2;
		}
		screenRedraw = true;
		deleteAll();
	}

	//===============================================================================================================================================
	//	MASCOT SELECT - DIRECTIONS
	//===============================================================================================================================================
	else if (dbSpriteCollision(1, 202) == 1 && dbMouseClick() == 1)
	{
		if (gameMode == 1)
		{
			currentScreen = 11;
		}
		else if (gameMode == 2)
		{
			currentScreen = 12;
		}
		screenRedraw = true;
		deleteAll();
	}

	//===============================================================================================================================================
	//	SETTINGS
	//===============================================================================================================================================
	else if (dbSpriteCollision(1, 203) == 1 && dbMouseClick() == 1)
	{
		//if (gameMode == 1)
		//{
		//	//currentScreen = 31;
		//}
		//else if (gameMode == 2)
		//{
		//	//currentScreen = 32;
		//}
		//screenRedraw = true;
		//deleteAll();
	}

	//===============================================================================================================================================
	//	BACK TO GAME
	//===============================================================================================================================================
	else if (dbSpriteCollision(1, 204) == 1 && dbMouseClick() == 1)
	{
		//Error handling
		if (currentScreen == 21 && spriteSetting1 == 0 && spriteSetting2 == 0 && spriteSetting3 == 0 && spriteSetting4 == 0)
		{
			//ERROR - you must finish setting at least one mascot
			dbText(0, 0, "ERROR");
		}
		else if (currentScreen == 22 && spriteSetting1 == 0 && spriteSetting2 == 0 && spriteSetting3 == 0 && spriteSetting4 == 0)
		{
			//ERROR - you must set at least one rival mascot
			dbText(0, 0, "ERROR");
		}
		else if (currentScreen == 22 && spriteSettingHome == 0)
		{
			//ERROR - you must set the home mascot in this game mode.
			dbText(0, 0, "ERROR");
		}

		else
		{
			mascotSetter();
			screenRedraw = true;
			justOpened = true;
			deleteAll();
			settingsActive = false;
			phase = 1;
			dbDeleteSprite(200);
		}
	}

}
//===============================================================================================================================================
//	MASCOT SELECTION PANEL CONTROLLER
//===============================================================================================================================================
void Settings::sideMenuController()
{
//edit buttons
	if (dbSpriteCollision(1, 250) == 1 && dbMouseClick() == 1)
	{
		selectedSlot = 1;
		editMascot();
	}
	else if (dbSpriteCollision(1, 251) == 1 && dbMouseClick() == 1)
	{
		selectedSlot = 2;
		editMascot();
	}
	else if (dbSpriteCollision(1, 252) == 1 && dbMouseClick() == 1)
	{
		selectedSlot = 3;
		editMascot();
	}
	else if (dbSpriteCollision(1, 253) == 1 && dbMouseClick() == 1)
	{
		selectedSlot = 4;
		editMascot();
	}
	else if (dbSpriteCollision(1, 254) == 1 && dbMouseClick() == 1)
	{
		selectedSlot = 5;
		editMascot();
	}
//Random buttons
	else if (dbSpriteCollision(1, 255) == 1 && dbMouseClick() == 1)
	{
		selectedSlot = 1;
		randomMascot();
		spriteSetting1 = randomMascotID;
		screenRedraw = true;
		deleteAll();
	}
	else if (dbSpriteCollision(1, 256) == 1 && dbMouseClick() == 1)
	{
		selectedSlot = 2;
		randomMascot();
		spriteSetting2 = randomMascotID;
		screenRedraw = true;
		deleteAll();
	}
	else if (dbSpriteCollision(1, 257) == 1 && dbMouseClick() == 1)
	{
		selectedSlot = 3;
		randomMascot();
		spriteSetting3 = randomMascotID;
		screenRedraw = true;
		deleteAll();
	}
	else if (dbSpriteCollision(1, 258) == 1 && dbMouseClick() == 1)
	{
		selectedSlot = 4;
		randomMascot();
		spriteSetting4 = randomMascotID;
		screenRedraw = true;
		deleteAll();
	}
	else if (dbSpriteCollision(1, 259) == 1 && dbMouseClick() == 1)
	{
		selectedSlot = 5;
		randomMascot();
		spriteSettingHome = randomMascotID;
		screenRedraw = true;
		deleteAll();
	}
}

void Settings::editMascot()
{
	if (gameMode == 1)
	{
		currentScreen = 21;
		screenRedraw = true;
		deleteAll();
	}
	else if (gameMode == 2)
	{
		currentScreen = 22;
		screenRedraw = true;
		deleteAll();
	}
}

void Settings::randomMascot()
{
	dbRandomize(dbTimer());
	randomMascotID = dbRND(7) + 1;
	if (gameMode == 1)
	{
		while (randomMascotID <= 7 && spriteSetting1 == randomMascotID || randomMascotID <= 7 && spriteSetting2 == randomMascotID || randomMascotID <= 7 && spriteSetting3 == randomMascotID || randomMascotID <= 7 && spriteSetting4 == randomMascotID)
			randomMascotID += 1;
		while (randomMascotID >= 2 && spriteSetting1 == randomMascotID || randomMascotID >= 2 && spriteSetting2 == randomMascotID || randomMascotID >= 2 && spriteSetting3 == randomMascotID || randomMascotID >= 2 && spriteSetting4 == randomMascotID)
			randomMascotID -= 1;
	}
	else if (gameMode == 2)
	{
		bool loopRepeater1 = true;
		while (randomMascotID <= 7 && loopRepeater1 == true)
		{
			if (spriteSetting1 == randomMascotID || spriteSetting2 == randomMascotID || spriteSetting3 == randomMascotID || spriteSetting4 == randomMascotID || spriteSettingHome == randomMascotID)
				randomMascotID += 1;
			else
				loopRepeater1 = false;
		}
		while (randomMascotID >= 2 && loopRepeater1 == true)
		{
			if (spriteSetting1 == randomMascotID || spriteSetting2 == randomMascotID || spriteSetting3 == randomMascotID || spriteSetting4 == randomMascotID || spriteSettingHome == randomMascotID)
				randomMascotID -= 1;
			else
				loopRepeater1 = false;
		}
	}
}

//===============================================================================================================================================
//	MASCOT SELECTION PANEL CONTROLLER
//===============================================================================================================================================
void Settings::mascotSelectionPanelController()
{
	if (dbSpriteCollision(1, 241) == 1 && dbMouseClick() == 1)
	{
		selectedMascot = 1;
		dbDeleteSprite(240);	//alpha overlay
		dbSprite(240, 201, 237, 33);
	}
	else if (dbSpriteCollision(1, 242) == 1 && dbMouseClick() == 1)
	{
		selectedMascot = 2;
		dbDeleteSprite(240);
		dbSprite(240, 261, 237, 33);
	}
	else if (dbSpriteCollision(1, 243) == 1 && dbMouseClick() == 1)
	{
		selectedMascot = 3;
		dbDeleteSprite(240);
		dbSprite(240, 322, 237, 33);
	}
	else if (dbSpriteCollision(1, 244) == 1 && dbMouseClick() == 1)
	{
		selectedMascot = 4;
		dbDeleteSprite(240);
		dbSprite(240, 382, 237, 33);
	}
	else if (dbSpriteCollision(1, 245) == 1 && dbMouseClick() == 1)
	{
		selectedMascot = 5;
		dbDeleteSprite(240);
		dbSprite(240, 201, 299, 33);
	}
	else if (dbSpriteCollision(1, 246) == 1 && dbMouseClick() == 1)
	{
		selectedMascot = 6;
		dbDeleteSprite(240);
		dbSprite(240, 261, 299, 33);
	}
	else if (dbSpriteCollision(1, 247) == 1 && dbMouseClick() == 1)
	{
		selectedMascot = 7;
		dbDeleteSprite(240);
		dbSprite(240, 322, 299, 33);
	}
	else if (dbSpriteCollision(1, 248) == 1 && dbMouseClick() == 1)
	{
		selectedMascot = 8;
		dbDeleteSprite(240);
		dbSprite(240, 382, 299, 33);
	}
}

//===============================================================================================================================================
//	SPRITE DRAWING FUNCTIONS
//===============================================================================================================================================
void Settings::drawSideMenuButtons()
{
	//Edit Buttons
	dbSprite(250, 70, 90, 75);
	dbSprite(251, 70, 159, 75);
	dbSprite(252, 70, 230, 75);
	dbSprite(253, 70, 299, 75);

	//Random Buttons
	dbSprite(255, 70, 112, 75);
	dbSprite(256, 70, 180, 75);
	dbSprite(257, 70, 250, 75);
	dbSprite(258, 70, 321, 75);

	if (gameMode == 2) //HVR Mode
	{
		dbSprite(254, 528, 92, 75); //Home Edit button
		dbSprite(259, 528, 114, 75);//Home Random button
	}
}

void Settings::drawSideMenuMascots()
{
	if (currentScreen == 1 || currentScreen == 2)
	{
		//Draw mascot tiles centered
		dbSprite(260, 60, 109, spriteSetting1 + 200);
		dbSprite(261, 60, 179, spriteSetting2 + 200);
		dbSprite(262, 60, 249, spriteSetting3 + 200);
		dbSprite(263, 60, 319, spriteSetting4 + 200);
		if (gameMode == 2)	//HRV MODE
			dbSprite(264, 579, 111, spriteSettingHome + 200);
	}
	else
	{
		//Draw mascot tiles next to buttons
		dbSprite(260, 38, 109, spriteSetting1 + 200);
		dbSprite(261, 38, 179, spriteSetting2 + 200);
		dbSprite(262, 38, 249, spriteSetting3 + 200);
		dbSprite(263, 38, 319, spriteSetting4 + 200);
		if (gameMode == 2)	//HVR MODE
			dbSprite(264, 600, 111, spriteSettingHome + 200);
	}
	//Center the mascots in the box.
	dbOffsetSprite(260, dbSpriteWidth(260) / 2, dbSpriteHeight(260) / 2);
	dbOffsetSprite(261, dbSpriteWidth(261) / 2, dbSpriteHeight(261) / 2);
	dbOffsetSprite(262, dbSpriteWidth(262) / 2, dbSpriteHeight(262) / 2);
	dbOffsetSprite(263, dbSpriteWidth(263) / 2, dbSpriteHeight(263) / 2);
	dbOffsetSprite(264, dbSpriteWidth(264) / 2, dbSpriteHeight(264) / 2);

}

void Settings::drawMascotSelectionPanel()
{
	//Draw the mascot pictures first - so they're below the collider
	dbSprite(231, 229, 267, 201);	//Dolphin
	dbSprite(232, 289, 267, 202);	//Wildcat
	dbSprite(233, 350, 267, 203);	//Banana Slug
	dbSprite(234, 410, 267, 204);	//Mantaray
	dbSprite(235, 229, 329, 205);
	dbSprite(236, 289, 329, 206);
	dbSprite(237, 350, 329, 207);
	dbSprite(238, 410, 329, 208);

	//Center the mascot tiles
	dbOffsetSprite(231, dbSpriteWidth(231) / 2, dbSpriteHeight(231) / 2);
	dbOffsetSprite(232, dbSpriteWidth(232) / 2, dbSpriteHeight(232) / 2);
	dbOffsetSprite(233, dbSpriteWidth(233) / 2, dbSpriteHeight(233) / 2);
	dbOffsetSprite(234, dbSpriteWidth(234) / 2, dbSpriteHeight(234) / 2);
	dbOffsetSprite(235, dbSpriteWidth(235) / 2, dbSpriteHeight(235) / 2);
	dbOffsetSprite(236, dbSpriteWidth(236) / 2, dbSpriteHeight(236) / 2);
	dbOffsetSprite(237, dbSpriteWidth(237) / 2, dbSpriteHeight(237) / 2);
	dbOffsetSprite(238, dbSpriteWidth(238) / 2, dbSpriteHeight(238) / 2);

	//Draw the mascot colliders
	dbSprite(241, 201, 237, 78);
	dbSprite(242, 261, 237, 78);
	dbSprite(243, 322, 237, 78);
	dbSprite(244, 384, 237, 78);
	dbSprite(245, 201, 299, 78);
	dbSprite(246, 261, 299, 78);
	dbSprite(247, 322, 299, 78);
	dbSprite(248, 384, 299, 78);
}
//===============================================================================================================================================
//	MASCOT SETTER
//===============================================================================================================================================
void Settings::mascotSetter()
{
	//initialize numMascots (from global) so that it doesn't count up from a previous count
	numMascots = 0;
	
	//This is just to cover my ass. - In case something happens with my error handling, and the user is able to get around it.
	//This makes sure there is always a mascot selected for at least one normal mascot slot, and if gameMode is 2, then the home mascot must be
	//selected, and it cannot be the same as one of the rival mascots...
	//Hopefully, this won't have to run though.
	if (spriteSetting1 == 0 && spriteSetting2 == 0 && spriteSetting3 == 0 && spriteSetting4 == 0)
	{
		spriteSetting1 = 1;
		if (gameMode == 2)
		{
			if (spriteSetting1 == spriteSettingHome)
				spriteSetting1 += 1;
		}
	}
	if (gameMode == 2 && spriteSettingHome == 0)
	{
		spriteSettingHome = 1;
		while (spriteSettingHome == spriteSetting1 || spriteSettingHome == spriteSetting2 || spriteSettingHome == spriteSetting3 || spriteSettingHome == spriteSetting4)
			spriteSettingHome += 1;
	}

	//This runs through and reorganizes the selected mascots, so that if the player was mean, and only selected a mascot in the bottom slot,
	//my spawning will still work correctly.
	//Works like high score table, but with loops instead..
	while (spriteSetting1 == 0)
	{
		spriteSetting1 = spriteSetting2;	
		spriteSetting2 = spriteSetting3;
		spriteSetting3 = spriteSetting4;
		spriteSetting4 = 0;
	}
	while (spriteSetting2 == 0 && spriteSetting3 != 0 || spriteSetting2 == 0 && spriteSetting4 != 0)
	{
		spriteSetting2 = spriteSetting3;
		spriteSetting3 = spriteSetting4;
		spriteSetting4 = 0;
	}
	while (spriteSetting3 == 0 && spriteSetting4 != 0)
	{
		spriteSetting3 = spriteSetting4;
		spriteSetting4 = 0;
	}
	

	//count the number of mascots and set numMascots;
	if (spriteSetting1 != 0)
		numMascots += 1;
	if (spriteSetting2 != 0)
		numMascots += 1;
	if (spriteSetting3 != 0)
		numMascots += 1;
	if (spriteSetting4 != 0)
		numMascots += 1;
	if (gameMode == 2)	//This counts the home mascot
		numMascots += 1;
}

//===============================================================================================================================================
//	DELETION
//===============================================================================================================================================
void Settings::deleteAll()
{
	//Main menu
	for (int menuItem = 201; menuItem <= 204; menuItem++)
		dbDeleteSprite(menuItem);

	//Mode Buttons
	dbDeleteSprite(210);
	dbDeleteSprite(211);

	//Mascot buttons
	dbDeleteSprite(220);
	dbDeleteSprite(221);

	//Side panel Alpha overlay - selectedslot
	dbDeleteSprite(225);

	//Mascot panel mascots
	for (int pnlMascot = 231; pnlMascot <= 238; pnlMascot++)
		dbDeleteSprite(pnlMascot);

	//Mascot panel Buttons
	for (int pnlBtns = 240; pnlBtns <= 248; pnlBtns++)
		dbDeleteSprite(pnlBtns);

	//Side menu
	for (int sideMenu = 250; sideMenu <= 259; sideMenu++)
		dbDeleteSprite(sideMenu);

	//Side Mascots
	for (int sideTiles = 260; sideTiles <= 264; sideTiles++)
		dbDeleteSprite(sideTiles);

	//Background
	//dbDeleteSprite(200);
}