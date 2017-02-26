#include "DarkGDK.h"
#include "HighScore.h"
#include "Global.h"

void HighScore::highScoreChecker()
{
	if (score >= highScore1 && gameMode == 1 || score >= hvrHighScore1 && gameMode == 2)		//Checks to see if you beat the first high score
	{
		dbSprite(32, 74, 101, 32);	//Enter initials overlay
		highScoreCheck = true;		//A high score has been achieved!
		if (gameMode == 1)
			setScore1();			//Move into the score setter
		else if (gameMode == 2)
			setScore1HVR();			//Score setter for HVR mode.
	}
	else if (score >= highScore2 && gameMode == 1 || score >= hvrHighScore2 && gameMode == 2)	//Checks if you beat second high score
	{
		dbSprite(32, 74, 101, 32);
		highScoreCheck = true;
		if (gameMode == 1)
			setScore2();
		else if (gameMode == 2)
			setScore2HVR();
	}
	else if (score >= highScore3 && gameMode == 1 || score >= hvrHighScore3 && gameMode == 2)	//Checks if you beat third high score
	{
		dbSprite(32, 74, 101, 32);
		highScoreCheck = true;
		if (gameMode == 1)
			setScore3();
		else if (gameMode == 2)
			setScore3HVR();
	}
	else if (score >= highScore4 && gameMode == 1 || score >= hvrHighScore4 && gameMode == 2)	//Checks if you beat fourth high score
	{
		dbSprite(32, 74, 101, 32);
		highScoreCheck = true;
		if (gameMode == 1)
			setScore4();
		else if (gameMode == 2)
			setScore4HVR();
	}
	else if (score >= highScore5 && gameMode == 1 || score >= hvrHighScore5 && gameMode == 2)	//Checks if you beat fifth high score
	{
		dbSprite(32, 74, 101, 32);
		highScoreCheck = true;
		if (gameMode == 1)
			setScore5();
		else if (gameMode == 2)
			setScore5HVR();
	}
	else
		highScoreCheck = false;
}

void HighScore::printScoresKTA()
{
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
}

void HighScore::printScoresHVR()
{
//High Score 5
	dbSetTextSize(21);
	dbText(238, 184, dbUpper(hvrInitials5));									//Print initials (convert to uppercase)
	dbText(435 - dbTextWidth(dbStr(hvrHighScore5)), 184, dbStr(hvrHighScore5));	//Print Score
//High Score 4
	dbSetTextSize(22);
	dbText(235, 207, dbUpper(hvrInitials4));
	dbText(439 - dbTextWidth(dbStr(hvrHighScore4)), 207, dbStr(hvrHighScore4));
//High Score 3
	dbSetTextSize(23);
	dbText(232, 230, dbUpper(hvrInitials3));
	dbText(443 - dbTextWidth(dbStr(hvrHighScore3)), 230, dbStr(hvrHighScore3));
//High Score 2
	dbSetTextSize(24);
	dbText(229, 253, dbUpper(hvrInitials2));
	dbText(446 - dbTextWidth(dbStr(hvrHighScore2)), 253, dbStr(hvrHighScore2));
//High Score 1
	dbSetTextSize(25);
	dbText(226, 276, dbUpper(hvrInitials1));
	dbText(450 - dbTextWidth(dbStr(hvrHighScore1)), 276, dbStr(hvrHighScore1));
}

void HighScore::writeScoresKTA()
{

}

void HighScore::writeScoresHVR()
{

}

void HighScore::readScoresKTA()
{

}

void HighScore::readScoresHVR()
{

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

void HighScore::setScore1HVR()
{
	hvrHighScore5 = hvrHighScore4;
	hvrHighScore4 = hvrHighScore3;
	hvrHighScore3 = hvrHighScore2;
	hvrHighScore2 = hvrHighScore1;
	hvrHighScore1 = score;

	hvrInitials5 = hvrInitials4;
	hvrInitials4 = hvrInitials3;
	hvrInitials3 = hvrInitials2;
	hvrInitials2 = hvrInitials1;
	dbSetCursor(304, 256);	//Moves insertion point to the correct place on the enter initials overlay
	hvrInitials1 = dbInput();	//Get input from player

	while (dbLen(hvrInitials1) == 0 || dbLen(hvrInitials1) > 3)	//Input validation
	{
		if (dbLen(hvrInitials1) == 0)
		{
			dbSprite(50, 147, 278, 50);
			dbSetCursor(304, 256);
			hvrInitials1 = dbInput();
			dbDeleteSprite(50);
		}
		else if (dbLen(hvrInitials1) > 3)
		{
			dbSprite(50, 147, 278, 51);
			dbSetCursor(304, 256);
			hvrInitials1 = dbInput();
			dbDeleteSprite(50);
		}
	}
}

void HighScore::setScore2HVR()
{
	hvrHighScore5 = hvrHighScore4;
	hvrHighScore4 = hvrHighScore3;
	hvrHighScore3 = hvrHighScore2;
	hvrHighScore2 = score;

	hvrInitials5 = hvrInitials4;
	hvrInitials4 = hvrInitials3;
	hvrInitials3 = hvrInitials2;
	dbSetCursor(304, 256);
	hvrInitials2 = dbInput();

	while (dbLen(hvrInitials2) == 0 || dbLen(hvrInitials2) > 3)	//Input validation
	{
		if (dbLen(hvrInitials2) == 0)
		{
			dbSprite(50, 147, 278, 50);
			dbSetCursor(304, 256);
			hvrInitials2 = dbInput();
			dbDeleteSprite(50);
		}
		else if (dbLen(hvrInitials2) > 3)
		{
			dbSprite(50, 147, 278, 51);
			dbSetCursor(304, 256);
			hvrInitials2 = dbInput();
			dbDeleteSprite(50);
		}
	}
}

void HighScore::setScore3HVR()
{
	hvrHighScore5 = hvrHighScore4;
	hvrHighScore4 = hvrHighScore3;
	hvrHighScore3 = score;

	hvrInitials5 = hvrInitials4;
	hvrInitials4 = hvrInitials3;
	dbSetCursor(304, 256);
	hvrInitials3 = dbInput();

	while (dbLen(hvrInitials3) == 0 || dbLen(hvrInitials3) > 3)	//Input validation
	{
		if (dbLen(hvrInitials3) == 0)
		{
			dbSprite(50, 147, 278, 50);
			dbSetCursor(304, 256);
			hvrInitials3 = dbInput();
			dbDeleteSprite(50);
		}
		else if (dbLen(hvrInitials3) > 3)
		{
			dbSprite(50, 147, 278, 51);
			dbSetCursor(304, 256);
			hvrInitials3 = dbInput();
			dbDeleteSprite(50);
		}
	}
}

void HighScore::setScore4HVR()
{
	hvrHighScore5 = hvrHighScore4;
	hvrHighScore4 = score;

	hvrInitials5 = hvrInitials4;
	dbSetCursor(304, 256);
	hvrInitials4 = dbInput();

	while (dbLen(hvrInitials4) == 0 || dbLen(hvrInitials4) > 3)	//Input validation
	{
		if (dbLen(hvrInitials4) == 0)
		{
			dbSprite(50, 147, 278, 50);
			dbSetCursor(304, 256);
			hvrInitials4 = dbInput();
			dbDeleteSprite(50);
		}
		else if (dbLen(hvrInitials4) > 3)
		{
			dbSprite(50, 147, 278, 51);
			dbSetCursor(304, 256);
			hvrInitials4 = dbInput();
			dbDeleteSprite(50);
		}
	}
}

void HighScore::setScore5HVR()
{
	hvrHighScore5 = score;

	dbSetCursor(304, 256);
	hvrInitials5 = dbInput();

	while (dbLen(hvrInitials5) == 0 || dbLen(hvrInitials5) > 3)	//Input validation
	{
		if (dbLen(hvrInitials5) == 0)
		{
			dbSprite(50, 147, 278, 50);
			dbSetCursor(304, 256);
			hvrInitials5 = dbInput();
			dbDeleteSprite(50);
		}
		else if (dbLen(hvrInitials5) > 3)
		{
			dbSprite(50, 147, 278, 51);
			dbSetCursor(304, 256);
			hvrInitials5 = dbInput();
			dbDeleteSprite(50);
		}
	}
}