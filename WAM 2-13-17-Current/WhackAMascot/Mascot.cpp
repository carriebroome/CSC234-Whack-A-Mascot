#include "DarkGDK.h"
#include "Mascot.h"
#include "Global.h"

Mascot::Mascot (int hNum, int x, int y) : holeNumber(hNum), xLoc(x), yLoc(y)
{
	currentState = 0;
	numMascots = 1;
	mascotSpriteID = holeNumber + 100;	//Assigns each instance of the class a unique sprite ID number.
}

//###############################################################################################################################################

void Mascot::mascotController()
{
	switch (currentState)	//If currentState == 0, the hole is inactive, and able to be picked by the spawner.
	{
//===============================================================================================================================================
//	INITIALIZATION
//===============================================================================================================================================
	case 1:	//Sprite is picked, initial sprite is created, then switch to first animation
		setSprite();
		dbCreateAnimatedSprite(mascotSpriteID, "SPRITE_DolphinUp.png", 7, 1, mascotSpriteID);
		dbSprite(mascotSpriteID, xLoc - 20, yLoc - 44, mascotSpriteID);
		currentState = 2;
		updateState();
		break;

//===============================================================================================================================================
//	UP ANIMATION
//===============================================================================================================================================
	case 2:	
		if (dbSpriteFrame(mascotSpriteID) < 7)
			dbPlaySprite(mascotSpriteID, 1, 7, 50);
			
		else if (dbSpriteFrame(mascotSpriteID) == 7)
		{
			dbDeleteSprite(mascotSpriteID);
			dbCreateAnimatedSprite(mascotSpriteID, "SPRITE_DolphinStill.png", 2, 1, mascotSpriteID);
			dbSprite(mascotSpriteID, xLoc - 20, yLoc - 44, mascotSpriteID);

			currentState = 3;	//Moves to still animation stage.
			updateState();
		}

		if (dbSpriteCollision(1, mascotSpriteID) == 1 && dbMouseClick() == 1)
		{
			dbDeleteSprite(mascotSpriteID);
			dbCreateAnimatedSprite(mascotSpriteID, "SPRITE_DolphinDeadInterrupted.png", 4, 1, mascotSpriteID);
			dbSprite(mascotSpriteID, xLoc - 20, yLoc - 44, mascotSpriteID);

			score += scoreIncrement;

			currentState = 6;	//Moves to the interrupted kill animation stage.
			updateState();
		}
		break;

//===============================================================================================================================================
//	STILL ANIMATION
//===============================================================================================================================================
	case 3:
		if (dbSpriteFrame(mascotSpriteID) < 2)
			dbPlaySprite(mascotSpriteID, 1, 2, difficultyLevel);
		else if (dbSpriteFrame(mascotSpriteID) == 2)
		{
			dbDeleteSprite(mascotSpriteID);
			dbCreateAnimatedSprite(mascotSpriteID, "SPRITE_DolphinDown.png", 7, 1, mascotSpriteID);
			dbSprite(mascotSpriteID, xLoc - 20, yLoc - 44, mascotSpriteID);

			currentState = 4;	//Moves to Down animation stage.
			updateState();
		}

		if (dbSpriteCollision(1, mascotSpriteID) == 1 && dbMouseClick() == 1)
		{
			dbDeleteSprite(mascotSpriteID);
			dbCreateAnimatedSprite(mascotSpriteID, "SPRITE_DolphinDead.png", 5, 1, mascotSpriteID);
			dbSprite(mascotSpriteID, xLoc - 20, yLoc - 44, mascotSpriteID);

			score += scoreIncrement;

			currentState = 5;	//Moves to normal kill animation stage.
			updateState();
		}
		break;

//===============================================================================================================================================
//	DOWN ANIMATION
//===============================================================================================================================================
	case 4:
		if (dbSpriteFrame(mascotSpriteID) < 7)
			dbPlaySprite(mascotSpriteID, 1, 7, 30);
		else if (dbSpriteFrame(mascotSpriteID) == 7)
		{
			//Increment missed counter here.
			currentState = 7;	//Moves to reset stage.
			updateState();
		}

		if (dbSpriteCollision(2, mascotSpriteID) == 1 && dbMouseClick() == 1)
		{
			dbDeleteSprite(mascotSpriteID);
			dbCreateAnimatedSprite(mascotSpriteID, "SPRITE_DolphinDeadInterrupted.png", 4, 1, mascotSpriteID);
			dbSprite(mascotSpriteID, xLoc - 20, yLoc - 44, mascotSpriteID);

			score += (scoreIncrement / 2);	//Only get half points if you kill the mascot while it's going away.

			currentState = 6;	//Moves to interrupted kill animation stage.
			updateState();
		}
		break;

//===============================================================================================================================================
//	DEAD ANIMATION
//===============================================================================================================================================
	case 5:	
		if (dbSpriteFrame(mascotSpriteID) < 5)
			dbPlaySprite(mascotSpriteID, 1, 5, 50);
		else if (dbSpriteFrame(mascotSpriteID) == 5)
		{
			currentState = 7;	//Move into reset stage.
			updateState();
		}
		break;

//===============================================================================================================================================
//	INTERRUPTED DEAD ANIMATION
//===============================================================================================================================================
	case 6:	
		if (dbSpriteFrame(mascotSpriteID) < 4)
			dbPlaySprite(mascotSpriteID, 1, 4, 50);
		else if (dbSpriteFrame(mascotSpriteID) == 4)
		{
			currentState = 7;	//Move into reset stage.
			updateState();
		}
		break;

//===============================================================================================================================================
//	RESET
//===============================================================================================================================================
	case 7:
		dbDeleteSprite(mascotSpriteID);	//Delete sprite
		currentState = 0;				//Reset hole to inactive
		updateState();
		break;
	}
}

//###############################################################################################################################################

void Mascot::setSprite()
{
	//Haven't implemented this yet.


	//if (numMascots <= 1)
	//{
	//	mascotImageID = 20;
	//}
	//else
	//{
		//dbRandomize(dbTimer())
	//}
}

//###############################################################################################################################################

void Mascot::updateState()
{
	//This function should be called anytime the global value needs to be set from within the class (since there will be 9 separate instances)
	//Anywhere outside of the class, global can be set directly.

	switch (holeNumber)
	{
	case 1:
		hole1 = currentState;
		break;
	case 2:
		hole2 = currentState;
		break;
	case 3:
		hole3 = currentState;
		break;
	case 4:
		hole4 = currentState;
		break;
	case 5:
		hole5 = currentState;
		break;
	case 6:
		hole6 = currentState;
		break;
	case 7:
		hole7 = currentState;
		break;
	case 8:
		hole8 = currentState;
		break;
	case 9:
		hole9 = currentState;
		break;
	}
}

//###############################################################################################################################################

void Mascot::updateHoleState()
{
	//This function updates the currentState value to be the value of the global value.
	//This is important so that if the global value was changed outside the class, currentState is still updated.
	//Should be called within main.cpp before the mascot controller to ensure that the correct value is set for currentState.

	switch (holeNumber)
	{
	case 1:
		currentState = hole1;
		break;
	case 2:
		currentState = hole2;
		break;
	case 3:
		currentState = hole3;
		break;
	case 4:
		currentState = hole4;
		break;
	case 5:
		currentState = hole5;
		break;
	case 6:
		currentState = hole6;
		break;
	case 7:
		currentState = hole7;
		break;
	case 8:
		currentState = hole8;
		break;
	case 9:
		currentState = hole9;
		break;
	}
}