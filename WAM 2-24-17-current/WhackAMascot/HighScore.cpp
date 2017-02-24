#include "DarkGDK.h"
#include "HighScore.h"
#include "Global.h"

void HighScore::highScoreChecker()
{
	if (score >= highScore1)		//Checks to see if you beat the first high score
	{
		dbSprite(32, 74, 101, 32);	//Enter initials overlay
		highScoreCheck = true;		//A high score has been achieved!
		setScore1();				//Move into the score setter
	}
	else if (score >= highScore2)	//Checks if you beat second high score
	{
		dbSprite(32, 74, 101, 32);
		highScoreCheck = true;
		setScore2();
	}
	else if (score >= highScore3)	//Checks if you beat third high score
	{
		dbSprite(32, 74, 101, 32);
		highScoreCheck = true;
		setScore3();
	}
	else if (score >= highScore4)	//Checks if you beat fourth high score
	{
		dbSprite(32, 74, 101, 32);
		highScoreCheck = true;
		setScore4();
	}
	else if (score >= highScore5)	//Checks if you beat fifth high score
	{
		dbSprite(32, 74, 101, 32);
		highScoreCheck = true;
		setScore5();
	}
	else
		highScoreCheck = false;
}

//Since one score will be kicked off, start from the bottom of the scores and work your way up to the score to be reset
void HighScore::setScore1()	//highScore1
{
	highScore5 = highScore4;
	highScore4 = highScore3;
	highScore3 = highScore2;
	highScore2 = highScore1;
	highScore1 = score;

	initials5 = initials4;
	initials4 = initials3;
	initials3 = initials2;
	initials2 = initials1;
	dbSetCursor(304, 256);	//Moves insertion point to the correct place on the enter initials overlay
	initials1 = dbInput();	//Get input from player

	while (dbLen(initials1) == 0 || dbLen(initials1) > 3)	//Input validation
	{
		if (dbLen(initials1) == 0)
		{
			dbSprite(50, 147, 278, 50);
			dbSetCursor(304, 256);
			initials1 = dbInput();
			dbDeleteSprite(50);
		}
		else if (dbLen(initials1) > 3)
		{
			dbSprite(50, 147, 278, 51);
			dbSetCursor(304, 256);
			initials1 = dbInput();
			dbDeleteSprite(50);
		}
	}
	

	//Here is where you need to update the .txt file with current high scores
	//Do this in every set function
}

void HighScore::setScore2()	//highScore2
{
	highScore5 = highScore4;
	highScore4 = highScore3;
	highScore3 = highScore2;
	highScore2 = score;

	initials5 = initials4;
	initials4 = initials3;
	initials3 = initials2;
	dbSetCursor(304, 256);
	initials2 = dbInput();

	while (dbLen(initials2) == 0 || dbLen(initials2) > 3)	//Input validation
	{
		if (dbLen(initials2) == 0)
		{
			dbSprite(50, 147, 278, 50);
			dbSetCursor(304, 256);
			initials2 = dbInput();
			dbDeleteSprite(50);
		}
		else if (dbLen(initials2) > 3)
		{
			dbSprite(50, 147, 278, 51);
			dbSetCursor(304, 256);
			initials2 = dbInput();
			dbDeleteSprite(50);
		}
	}
}

void HighScore::setScore3()	//highScore3
{
	highScore5 = highScore4;
	highScore4 = highScore3;
	highScore3 = score;

	initials5 = initials4;
	initials4 = initials3;
	dbSetCursor(304, 256);
	initials3 = dbInput();

	while (dbLen(initials3) == 0 || dbLen(initials3) > 3)	//Input validation
	{
		if (dbLen(initials3) == 0)
		{
			dbSprite(50, 147, 278, 50);
			dbSetCursor(304, 256);
			initials3 = dbInput();
			dbDeleteSprite(50);
		}
		else if (dbLen(initials3) > 3)
		{
			dbSprite(50, 147, 278, 51);
			dbSetCursor(304, 256);
			initials3 = dbInput();
			dbDeleteSprite(50);
		}
	}

}

void HighScore::setScore4()	//highScore4
{
	highScore5 = highScore4;
	highScore4 = score;

	initials5 = initials4;
	dbSetCursor(304, 256);
	initials4 = dbInput();

	while (dbLen(initials4) == 0 || dbLen(initials4) > 3)	//Input validation
	{
		if (dbLen(initials4) == 0)
		{
			dbSprite(50, 147, 278, 50);
			dbSetCursor(304, 256);
			initials4 = dbInput();
			dbDeleteSprite(50);
		}
		else if (dbLen(initials4) > 3)
		{
			dbSprite(50, 147, 278, 51);
			dbSetCursor(304, 256);
			initials4 = dbInput();
			dbDeleteSprite(50);
		}
	}

}

void HighScore::setScore5()	//highScore5
{
	highScore5 = score;

	dbSetCursor(304, 256);
	initials5 = dbInput();

	while (dbLen(initials5) == 0 || dbLen(initials5) > 3)	//Input validation
	{
		if (dbLen(initials5) == 0)
		{
			dbSprite(50, 147, 278, 50);
			dbSetCursor(304, 256);
			initials5 = dbInput();
			dbDeleteSprite(50);
		}
		else if (dbLen(initials5) > 3)
		{
			dbSprite(50, 147, 278, 51);
			dbSetCursor(304, 256);
			initials5 = dbInput();
			dbDeleteSprite(50);
		}
	}

}