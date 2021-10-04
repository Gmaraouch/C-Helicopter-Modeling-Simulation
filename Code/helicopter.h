#include <iostream>
using namespace std;

//class that defines the helicopter (Players)
class helicopter
{
	//X* is the array that saves the current state variables (x, y, yaw, u, v, r)
	//U* is the array that saves the input (torque)
	//Xd* is the array that saves the derivatives of the state variables
	//Z, pitch and roll are constant 
	double *X, *U, *Xd, Z, pitch, roll;
	int N, M; //N is the number of state variables and M is the number of inputs
	double t, dt; //t is the current time of the simulation and dt is the time step
	mesh *sim; //mesh that loads the helicopter

public:

	double R; //radius of the helicopter
	
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