#include <iostream>
using namespace std;

//class that defines the helicopter (Players)
class helicopter
{
	double *X, *U, *Xd, Z, pitch, roll;
	int N, M;
	double t, dt;
	mesh *sim;

public:

	double R;
	
	void calculate();
	helicopter(double *p, char file_name[]);
	helicopter();
	~helicopter();
	void draw_heli();
	void force_input();
	void force_input2();
	void position_input();
	void set_view2();
	int get_N();
	double & get_X(int i);
	void cheat();
};