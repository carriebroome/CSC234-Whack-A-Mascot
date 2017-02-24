class Timer
{
public:
	int run();
	int initial();
	int pauseInitial();
	int pauseRun();

private:
	double pauseStartTime;
	double pauseCurrentTime;
};