class Timer
{
public:
	void run();
	void initial();
	void pauseInitial();
	void pauseRun();

private:
	double pauseStartTime;
	double pauseCurrentTime;
};