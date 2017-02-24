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
		dbSprite(200, 0, 0, 11);	//Background
		
		dbSprite(210, 225, 218, 74);	//Kill Them All Button collider
		dbSprite(211, 225, 254, 74);	//Home VS Rivals Button collider

		drawSideMenuMascots();	//Draws sprites for the side panel mascots that are selected.

		break;

	case 2: //HVR Mode Select Screen
		dbSprite(200, 0, 0, 21);

		dbSprite(210, 225, 218, 74);	//Kill Them All Button collider
		dbSprite(211, 225, 254, 74);	//Home VS Rivals Button collider

		drawSideMenuMascots();	//Draws sprites for the side panel mascots that are selected.

		break;

	//===============================================================================================================================================
	//	MASCOT SELECT - DIRECTIONS
	//===============================================================================================================================================
	case 11://KTA Mascot Directions Screen
		dbSprite(200, 0, 0, 12);
		
		drawSideMenuButtons();
		drawSideMenuMascots();

		break;

	case 12://HVR Mascot Directions Screen
		dbSprite(200, 0, 0, 22);

		drawSideMenuButtons();
		drawSideMenuMascots();

		break;

	//===============================================================================================================================================
	//	MASCOT SELECT - SELECTING
	//===============================================================================================================================================
	case 21://KTA Mascot Selection Screen
		dbSprite(200, 0, 0, 13);
		
		drawSideMenuButtons();
		drawSideMenuMascots();

		drawMascotSelectionPanel();

		dbSprite(220, 274, 371, 76);	//Set Mascot button
		dbSprite(221, 377, 371, 77);	//Clear Mascot button

		break;

	case 22://HVR Mascot Selection Screen
		dbSprite(200, 0, 0, 23);

		drawSideMenuButtons();
		drawSideMenuMascots();

		drawMascotSelectionPanel();

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

		if (dbSpriteCollision(1, );

		break;

	case 2: //HVT Mode Select
		if (screenRedraw == true)
		{
			screenSelect();
			screenRedraw = false;
		}
		mainMenuController();
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
		break;

	case 12: //HVR Mascot Directions
		if (screenRedraw == true)
		{
			screenSelect();
			screenRedraw = false;
		}
		mainMenuController();
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

		mascotSelectionPanelController();

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
		mainMenuContoller();

		mascotSelectionPanelController();

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
				}
				else if (selectedSprite == 0)
				{
					//ERROR - You must select a mascot for the home mascot in the current game mode
				}
			} //End switch (slectedSlot)
		}
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
	if (redrawMenu == true)
	{
		dbSprite(201, 124, 36, 70);		//draw mode button
		dbSprite(202, 251, 35, 71);		//draw mascot select button
		dbSprite(203, 387, 35, 72);		//draw settings button
		dbSprite(204, 537, 308, 73);	//draw back to game button
		redrawMenu = false;
	}

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
		redrawMenu = true;
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
		redrawMenu = true;
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
		//redrawMenu = true;
		//screenRedraw = true;
		//deleteAll();
	}

	//===============================================================================================================================================
	//	BACK TO GAME
	//===============================================================================================================================================
	else if (dbSpriteCollision(1, 204) == 1 && dbMouseClick() == 1)
	{
		
		redrawMenu = true;
		screenRedraw = true;
		deleteAll();
		settingsActive = false;
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
		dbDeleteSprite(240);
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
		dbSprite(260, 60 - (dbSpriteWidth(260) / 2), 109 - (dbSpriteHeight(260) / 2), spriteSetting1 + 200);
		dbSprite(261, 60 - (dbSpriteWidth(261) / 2), 179 - (dbSpriteHeight(261) / 2), spriteSetting2 + 200);
		dbSprite(262, 60 - (dbSpriteWidth(262) / 2), 249 - (dbSpriteHeight(262) / 2), spriteSetting3 + 200);
		dbSprite(263, 60 - (dbSpriteWidth(263) / 2), 319 - (dbSpriteHeight(263) / 2), spriteSetting4 + 200);
		if (gameMode == 2)	//HRV MODE
			dbSprite(264, 579 - (dbSpriteWidth(264) / 2), 111 - (dbSpriteHeight(264) / 2), spriteSettingHome + 200);
	}
	else
	{
		//Draw mascot tiles next to buttons
		dbSprite(260, 38 - (dbSpriteWidth(260) / 2), 109 - (dbSpriteHeight(260) / 2), spriteSetting1 + 200);
		dbSprite(261, 38 - (dbSpriteWidth(261) / 2), 179 - (dbSpriteHeight(261) / 2), spriteSetting2 + 200);
		dbSprite(262, 38 - (dbSpriteWidth(262) / 2), 249 - (dbSpriteHeight(262) / 2), spriteSetting3 + 200);
		dbSprite(263, 38 - (dbSpriteWidth(263) / 2), 319 - (dbSpriteHeight(263) / 2), spriteSetting4 + 200);
		if (gameMode == 2)	//HVR MODE
			dbSprite(264, 600 - (dbSpriteWidth(264) / 2), 111 - (dbSpriteHeight(264) / 2), spriteSettingHome + 200);
	}
}

void Settings::drawMascotSelectionPanel()
{
	//Draw the mascot pictures first - so they're below the collider
	dbSprite(231, 229 - (dbSpriteWidth(231) / 2), 267 - (dbSpriteHeight(231) / 2), 201);	//Dolphin
	dbSprite(232, 289 - (dbSpriteWidth(232) / 2), 267 - (dbSpriteHeight(232) / 2), 202);	//Wildcat
	dbSprite(233, 350 - (dbSpriteWidth(233) / 2), 267 - (dbSpriteHeight(233) / 2), 203);	//Banana Slug
	dbSprite(234, 410 - (dbSpriteWidth(234) / 2), 267 - (dbSpriteHeight(234) / 2), 204);	//Mantaray
	dbSprite(235, 229 - (dbSpriteWidth(235) / 2), 329 - (dbSpriteHeight(235) / 2), 205);
	dbSprite(236, 289 - (dbSpriteWidth(236) / 2), 329 - (dbSpriteHeight(236) / 2), 206);
	dbSprite(237, 350 - (dbSpriteWidth(237) / 2), 329 - (dbSpriteHeight(237) / 2), 207);
	dbSprite(238, 410 - (dbSpriteWidth(238) / 2), 329 - (dbSpriteHeight(238) / 2), 208);

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
//	DELETION
//===============================================================================================================================================
void Settings::deleteAll()
{
	//Background
	dbDeleteSprite(200);

	//Main menu
	for (int menuItem = 201; menuItem <= 204; menuItem++)
		dbDeleteSprite(menuItem);

	//Mode Buttons
	dbDeleteSprite(210);
	dbDeleteSprite(211);

	//Mascot buttons
	dbDeleteSprite(220);
	dbDeleteSprite(221);

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
}