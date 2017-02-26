class Spawn
{
public:
	void spawnMascot();	//This is the function that actually spawns the mascots. It should call nextHole() to know where to spawn a mascot

private:
	void nextHole();	//Generates random value that decides which hole will spawn a mascot (1-9)

	int holePicked;		//The hole that is currently picked by nextHole()
};