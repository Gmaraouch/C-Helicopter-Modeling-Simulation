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
#include "Environment.h"
#include "Object.h"
#include "world.h"
const double PI = atan(1) * 4;

extern ofstream fout;
extern ofstream sout;


World::World(int N)
{
	int i;

	if (N > 2)
	{
		fout << "\nError, too many players.";
		return; //can't have more than 2 helis.
	}
	n = N;

	static long int s = -15;
	
	objects[0] = new Object("tiger.x", 1.0, 0.5);
	objects[1] = new Object("plane.x", 1.0, 0.5);
	objects[2] = new Object("10cannon-3d.x", 1.0, 0.5);
	objects[3] = new Object("car.x", 1.0, 0.5);

	double P[7];
	for (i = 0; i < n; i++)
	{
		
		P[0] = 0;
		P[1] = 10.0*ran(s) - 5;
		P[2] = 10.0*ran(s) - 5;
		P[3] = 2 * PI*ran(s) - PI;
		P[4] = 0;
		P[5] = 0;
		P[6] = 0;
		Helis[i] = new helicopter(P, "heli.x");
	}

	sout << "t,xc,yc,psi,u,v,r\n";

	//map = new environment("track.x");
}

World::~World()
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (Helis[i] != NULL)
		{
			delete Helis[i];
			Helis[i] = NULL;
		}
		else cout << "\nError, attempted to delete a NULL Pointer.";
	}

	for (i = 0; i < 4; i++)
	{
		if (objects[i] != NULL)
		{
			delete objects[i];
			objects[i] = NULL;
		}
		else cout << "\nError, attempted to delete a NULL Pointer.";
	}

	/*if (map != NULL)
	{
		delete map;
		map = NULL;
	}
	else cout << "\nError, attempted to delete a NULL Pointer.";*/
	
}

int World::collision()
{
	int i, j;
	int ans;
	double X1, X2, Y1, Y2, R1, R2, d;
	ans = 0;
	if (n > 1)
	{
		

		
		for (i = 0; i < n; i++)
		{
			X1 = Helis[i]->get_X(1);
			Y1 = Helis[i]->get_X(2);
			R1 = Helis[i]->R;
	

			for (j = 0; j < n; j++)
			{
				if (i == j) continue;
				X2 = Helis[j]->get_X(1);
				Y2 = Helis[j]->get_X(2);
				R2 = Helis[i]->R;

				d = (X1 - X2)*(X1 - X2) + (Y1 - Y2)*(Y1 - Y2);
				d = sqrt(d);

				if (d < (R1 + R2))
				{
					text_xy("GAME OVER, COLLISION OCCURED!", 50, 300, 30);
					text_xy("PRESS ESC TO EXIT PROGRAM!", 50, 350, 30);
					//Sleep(10000);
					//exit(1);
					ans = 1;
					return ans;
				}

			}
		}
		return ans;
	}
	return ans;

}

void World::display()
{

	text_xy("Number of players: ", 10, 10);
	text_xy(n, 170, 10);

	text_xy("Number of Packages Remaining: ", 10, 40);
	
}

void World::draw_players()
{
	int i;

	for (i = 0; i < n; i++)
	{
		Helis[i]->draw_heli();
	}


}

void World::set_view_game()
{
	
	if (n > 1)
	{
		static int flag = -1;
		//default is helicopter -1

		if (KEY('P')) flag *= -1;

		if (flag < 0)
		{
			Helis[0]->set_view2();
		}
		else
		{
			Helis[1]->set_view2();
		}
	}
	else
	{
		Helis[0]->set_view2();
	}
}

void World::draw_map()
{
//	draw_XYZ(5.0);
//	map->draw_backgorund();
//
	heli_pad->Scale = 0.1;
	heli_pad->draw(0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
}

void World::calculate()
{
	int i;
	for (i = 0; i < n; i++)
	{
		Helis[i]->calculate();
	}
}

void World::force()
{
	if (n > 1)
	{
		Helis[0]->force_input();
		Helis[1]->force_input2();
	}
	else
	{
		Helis[0]->force_input();
	}

}

void World::draw_object()
{
	int i;
	for (i = 0; i < 4; i++)
	{
		objects[i]->draw();
	}
}
