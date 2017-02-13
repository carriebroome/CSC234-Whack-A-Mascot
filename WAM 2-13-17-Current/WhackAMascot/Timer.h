class Timer
{
public:
	int run();
	int initial();
	int pauseInitial();
	int pauseRun();

private:
	bool first;
	double pauseStartTime;
	double pauseCurrentTime;
};