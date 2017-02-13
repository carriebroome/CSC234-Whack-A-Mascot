#include "DarkGDK.h"
#include "Spawn.h"
#include "Global.h"

void Spawn::spawnMascot()
{
	int spawner = 0;	//This will hold random value

	//Make sure game isn't paused
	if (pause == 0)
	{
		dbRandomize(dbTimer());
		spawner = dbRND(1000);

		//Determines whether a mascot should spawn
		if (spawner % 30 == 0)
		{
			//if a mascot should spawn, figure out which hole it should spawn at.
			nextHole();
		}
	}
}

void Spawn::nextHole()
{
	dbRandomize(dbTimer());
	holePicked = dbRND(8);

	switch (holePicked)
	{
	case 0:
		if (hole1 == 0)
			hole1 = 1;
		break;
	case 1:
		if (hole2 == 0)
			hole2 = 1;
		break;
	case 2:
		if (hole3 == 0)
			hole3 = 1;
		break;
	case 3:
		if (hole4 == 0)
			hole4 = 1;
		break;
	case 4:
		if (hole5 == 0)
			hole5 = 1;
		break;
	case 5:
		if (hole6 == 0)
			hole6 = 1;
		break;
	case 6:
		if (hole7 == 0)
			hole7 = 1;
		break;
	case 7:
		if (hole8 == 0)
			hole8 = 1;
		break;
	case 8:
		if (hole9 == 0)
			hole9 = 1;
		break;
	}
}