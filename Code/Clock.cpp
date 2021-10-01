#include <iostream>
#include <fstream>

using namespace std;

#include "clock.h"
#include "3D_graphics.h"

extern ofstream fout;

Timer::Timer(int h, int m, int s, int st)
{
	hour = h;
	min= m;
	sec = s;
	stall = st;

}

Timer::~Timer()
{
	fout << "\nDestructing timer.";
}
void Timer::update_timer()
{
	if (sec == 0 && min == 0 && hour == 0)
	{
		fout << "\nTimer has already ended.";
		return;
	}

	stall--;
	if (stall < 0)
	{
		stall = 125;
		sec--;
	}

	if (sec < 0)
	{
		sec = 59;
		min--;
	}
	if (min < 0)
	{
		min = 59;
		hour--;
	}
	if (sec == 0 && min == 0 && hour == 0)
	{
		fout << "\nThis is the end my friend.";
	}

}

void Timer::print_time()
{/*
	text_xy(hour, 10, 10, 39);
	text_xy(":", 10, 10);
	text_xy(min, 10, 10);
	text_xy(":", 10, 10);
	text_xy(sec, 10, 10);
*/
	text_xy("Time Remaining: ", 550, 10);
	text_xy(hour, 700, 10);
	text_xy(":", 725, 10);
	text_xy(min, 735, 10);
	text_xy(":", 760, 10);
	text_xy(sec, 770, 10);
}

int Timer::current_time()
{
	int ans;
	ans = 3600 * hour + 60 * min + sec;
	return ans;
}
