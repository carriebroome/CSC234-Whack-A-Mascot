class Spawn
{
public:
	void spawnMascot();	//This is the function that actually spawns the mascots. It should call nextHole() and nextMascot() to know how to spawn				
	void nextHole();	//Generates random value that decides which hole will spawn a mascot (1-9)

private:
	int mascotImage;	//Sprite ID of mascot image selected
	int holePicked;		//The hole that is currently picked by nextHole()
};