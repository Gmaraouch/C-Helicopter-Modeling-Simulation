#include <iostream>
using namespace std;
#include <fstream>
#include <windows.h> 

#include "rotation.h"
#include "3D_graphics.h" 
#include "functions.h"
#include "ran.h"
#include "Object.h"
#include "timer.h"
const double PI = atan(1) * 4;

Object::Object(char file_name[], double R, double scale)
{
	static long int seed = int(high_resolution_time());
	
	P = new double[7];
	P[0]= 0;
	P[1]= 100.0*ran(seed) - 50;
	P[2]= 100.0*ran(seed) - 50;
	//P[1]= 0;
	//P[2] = 0;
	P[3]= -2;
	P[4]= 0;
	P[5]= 0;
	P[6]= 0;

	this->R = R;
	obj = new mesh(file_name); 
	S = scale;
}

Object::~Object()
{

	if (obj != NULL)
	{
		delete obj;
		obj = NULL;
	}
	else cout << "\nError, attempted to delete a NULL Pointer.";

	if (P != NULL)
	{
		delete P;
		P = NULL;
	}
	else cout << "\nError, attempted to delete a NULL Pointer.";

}

void Object::draw()
{
	obj->Scale = S;
	obj->draw(P[1], P[2], P[3], 0.0, 0.0, 0.0);
}

double Object::get_R()
{
	return R;
}

double & Object::get_P(int i)
{
	static double ans = 0;
	if (i < 1 || i>6)
	{
		return ans;
	}
	else return P[i];

}