//Header file for the Timer class

class Timer
{
	int hour;
	int min;
	int sec;
	int stall;

public:

	Timer(int h, int m, int s, int st);
	~Timer();
	void update_timer();
	void save(char file_name[]);
	void print_time();
	int current_time();

};