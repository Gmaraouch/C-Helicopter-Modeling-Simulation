#include <iostream>
using namespace std;
#include <fstream>
#include <windows.h> 

#include "timer.h" 
#include "rotation.h"
#include "3D_graphics.h" 
#include "functions.h"
#include "ran.h"
#include "helicopter.h"

const double PI = atan(1) / 4;

//initialize a helicopter with defined initial position and file
helicopter::helicopter(double *p, char *file_name)
{
	int i;
	N = 6;
	M = 2;
	X = new double[N + 1];
	Xd = new double[N + 1];
	U = new double[M + 2];
	Z = 0;
	pitch = PI;
	roll = PI;

	for (i = 1; i <= N; i++)
	{
		X[i] = p[i];
		Xd[i] = 0;
	}

	for (i = 1; i <= M; i++)
	{
		U[i] = 0;
	}

	t = 0;
	dt = 0.01;
	R = 0.5;
	sim = new mesh(file_name);
	sim->Roll_0 = 3.1415/2+3.1415/15;
	//sim->Pitch_0 = 3.1415 / 2;
	sim->Yaw_0 = 3*3.1415 / 2+3.1415/4;
	
}

helicopter::helicopter()
{
	int i;
	static long int seed = -13;
	N = 6;
	M = 2;
	X = new double[N + 1];
	Xd = new double[N + 1];
	U = new double[M + 1];
	Z = 0;
	pitch = PI / 2;
	roll = PI / 2;

	for (i = 1; i <=3; i++)
	{
		X[i] = 10 * ran(seed) - 5; //between -5 and 5 for variables
		Xd[i] = 0;  
	}

	for (i = 4; i <= N; i++)
	{
		X[i] = 0; 
		Xd[i] = 0; 
	}

	for (i = 1; i <= M; i++)
	{
		U[i] = 0;
	}

	t = 0;
	dt = 0.01;
	R = 0.5;

	sim = new mesh("heli.x");
	sim->Roll_0 = PI / 2;
	sim->Yaw_0 = PI / 2;
	sim->Pitch_0 = 3.1415 / 2;
}

helicopter::~helicopter()

{
	if (sim != NULL)
	{
		delete sim;
		sim = NULL;
	}
	else cout << "\nError, attempted to delete a NULL Pointer.";
	
	if (X != NULL)
	{
		delete X;
		X = NULL;
	}
	else cout << "\nError, attempted to delete a NULL Pointer.";

	if (Xd != NULL)
	{
		delete Xd;
		Xd = NULL;
	}
	else cout << "\nError, attempted to delete a NULL Pointer.";

	if (U != NULL)
	{
		delete U;
		 U= NULL;
	}
	else cout << "\nError, attempted to delete a NULL Pointer.";


}

//the & is return by reference
double & helicopter::get_X(int i)
{
	static double dans = 0;

	if (i<1 || i>N)
	{
		cout << "\nError, out of bounds.";
		return dans;
	}
	else return X[i];
}

void helicopter::calculate()
{
	//calculate_inputs(X, t, N, U, M);
	calculate_Xd(X, t, N, U, M, Xd);

	/*
	int i;
	for (i = 0; i < 100; i++)
	{
	sim_step(dt, X, Xd);
	}
	*/
	sim_step(dt, X, Xd);
	t += dt;

}

void helicopter::draw_heli()
{
	sim->Scale = 0.1;
	sim->draw(X[1], X[2], Z, X[3], pitch, roll);
}

//set the perspective view of the helicopter (1st, 2nd and 3rd person views)
void helicopter::set_view2()
{
	static double R[4][4];
	static double u[4];
	static double eye_point_l[4], lookat_point_l[4], up_direction_l[4];
	static double eye_point[4], lookat_point[4], up_direction[4];

	static int flag = 3;
	static double x=10.0, y=10.0, z=10.0;

	//press 1, 2 or 3 to change between first person, second person or third person view
	if (KEY('1'))
	{
		flag = 1;
	}
	else if (KEY('2'))
	{
		flag = 2;
	}

	else if (KEY('3'))
	{
		flag = 3;
	}

	if (flag == 3) //3rd person
	{
		if (KEY('M'))
		{
			x += 0.1;
			y += 0.1;
			z+=0.1; 
		}
		else if (KEY('N'))
		{
			x -= 0.1;
			y -= 0.1;
			z-=0.1; 
		}

		if (KEY('L'))
		{
			z += 0.1; 
		}
		else if (KEY('K'))
		{
			z -= 0.1; 
		}

		if (KEY('G'))
		{
			x += 0.1; 
		}
		else if (KEY('F'))
		{
			x -= 0.1; 
		}

		if (KEY('J'))
		{
			y += 0.1; 
		}
		else if (KEY('H'))
		{
			y -= 0.1; 
		}

		//set the eye point
		eye_point[1] = x + X[1];
		eye_point[2] = y + X[2];
		eye_point[3] = z;

		//set the look at point 
		lookat_point[1] = X[1];
		lookat_point[2] = X[2];
		lookat_point[3] = 0;

		//define the up direction
		up_direction[1] = 0;
		up_direction[2] = 0;
		up_direction[3] = 1;
	}

	else if (flag == 1) //first person
	{
		eye_point_l[1] = 0;
		eye_point_l[2] = 0;
		eye_point_l[3] = 2;

		lookat_point_l[1] = 10;
		lookat_point_l[2] = 0;
		lookat_point_l[3] = 2;

		up_direction_l[1] = 0;
		up_direction_l[2] = 0;
		up_direction_l[3] = 1;

		euler_to_rotation(X[3], pitch, roll, R);

		multiply_Ax(R, eye_point_l, u);
		eye_point[1] = X[1] + u[1];
		eye_point[2] = X[2] + u[2];
		eye_point[3] = 0 + u[3];

		multiply_Ax(R, lookat_point_l, u);
		lookat_point[1] = X[1] + u[1];
		lookat_point[2] = X[2] + u[2];
		lookat_point[3] = 0 + u[3];

		multiply_Ax(R, up_direction_l, u);
		up_direction[1] = u[1];
		up_direction[2] = u[2];
		up_direction[3] = u[3];
	}

	else if (flag == 2) //2nd person view
	{
		eye_point_l[1] = -2;
		eye_point_l[2] = -2;
		eye_point_l[3] = 1;

		lookat_point_l[1] = 1;
		lookat_point_l[2] = 1;
		lookat_point_l[3] = 0;

		up_direction_l[1] = 0;
		up_direction_l[2] = 0;
		up_direction_l[3] = 1;

		euler_to_rotation(X[3], pitch, roll, R);

		multiply_Ax(R, eye_point_l, u);
		eye_point[1] = X[1] + u[1];
		eye_point[2] = X[2] + u[2];
		eye_point[3] = 0 + u[3];

		multiply_Ax(R, lookat_point_l, u);
		lookat_point[1] = X[1] + u[1];
		lookat_point[2] = X[2] + u[2];
		lookat_point[3] = 0 + u[3];

		multiply_Ax(R, up_direction_l, u);
		up_direction[1] = u[1];
		up_direction[2] = u[2];
		up_direction[3] = u[3];
	}
	set_view(eye_point, lookat_point, up_direction);
}

//obtain the force input (U) for the first player
void helicopter::force_input()
{
	
	if (KEY(VK_RIGHT))
	{
	U[2] = 1;
	}
	else if (KEY(VK_LEFT))
	{
	U[2] = -1;
	}
	else U[2] = 0;


	if (KEY(VK_UP))
	{
	U[1] += 2;
	if (U[1] > 20)
	{
		U[1] = 20;
	}
	}
	else if (KEY(VK_DOWN))
	{
	U[1] -= 2;
	if (U[1] < -20)
	{
		U[1] = -20;
	}
	}
	else U[1] = 0;
	
}

//obtain the force input (U) for the second player
void helicopter::force_input2()
{

	if (KEY('D'))
	{
		U[2] = 1;
	}
	else if (KEY('A'))
	{
		U[2] = -1;
	}
	else U[2] = 0;


	if (KEY('W'))
	{
		U[1] += 2;
		if (U[1] > 20)
		{
			U[1] = 20;
		}
	}
	else if (KEY('S'))
	{
		U[1] -= 2;
		if (U[1] < 20)
		{
			U[1] = -20;
		}
	}
	else U[1] = 0;

}

int helicopter::get_N()
{
	return N;
}

void helicopter::cheat()
{

		if (KEY('D'))
		{
			X[1] += 0.01;
		}
		else if (KEY('A'))
		{
			X[1] += -0.01;
		}
		else U[1] = 0;


		if (KEY('W'))
		{
			X[2] += 0.01;

		}
		else if (KEY('S'))
		{
			X[2] += -0.01;
		}
		else U[2] = 0;

}