class Mascot
{
public:
	explicit Mascot(int, int, int);
	
	void setSprite();			//Sets the image for the sprite to spawn next
	void nextSprite();			//Picks which set of images for the sprite to spawn from
	void updateState();			//updates hole[x] (global variable) with current value of currentState
	void updateHoleState();		//updates currentState to the value of hole[x] (global variable)
	void mascotController();	//Controls animations for mascot sprites
	

private:
	int currentState;	//set explicitly, then updates when picked by nextHole() in spawn.h or within mascotController()

	int holeNumber;		//ID set by constructor
	int xLoc;			//X-axis location of hole
	int yLoc;			//Y-axis location of hole

	int numMascots;		//Number of possible mascot images	
	int mascotSpriteID;	//Sprite ID of mascot to spawn
	int mascotImageID;	//Image ID of mascot to spawn	

	char* animationUp;
	char* animationStill;
	char* animationDown;
	char* animationDead;
	char* animationDeadInterrupted;


};