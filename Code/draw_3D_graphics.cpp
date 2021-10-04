
#include <cmath> 
#include <cstdio>  
#include <cstring>
#include <iostream> 
#include <fstream>   
#include <strstream> 
#include <iomanip> 

#include <windows.h> 

#include "timer.h" 
#include "rotation.h"
#include "3D_graphics.h" 
#include "functions.h"
#include "ran.h"
#include "Environment.h"
#include "helicopter.h"
#include "Object.h"
#include "Clock.h"

/*
This is the main file.
This program is a simulation for the equations of motion for a helicopter. See: https://nowere.net/b/arch/87793/src/1358823196340.pdf for equations of motion
Equations of motion are calculated by using Euler time stepping.
The program incorporates 2 players (helicopters). The first one is controlled using wasd and the second one is controlled using the arrow keys.
The goal of the game is to pick up the monkeys scattered around the map and bring them back into the helipad.
A summary of all the keys for the program are as follow:
Key	Function
1	Change the view to first person view
2	Change the view to second person view
3	Change the view to third person view
P	Change the view from helicopter 1 to helicopter 2
Q	Increases the force of the main rotor for helicopter 2.
W	Decreases the force of the main rotor for helicopter 2
A	Decreases the force of the tail rotor for helicopter 2
S	Increase the force of the tail rotor for helicopter 2
Up	Increases the force of the main rotor for helicopter 1.
Down 	Decreases the force of the main rotor for helicopter 1
Left	Decreases the force of the tail motor for helicopter 1
Right	Increases the force of the tail motor for helicopter 1
M	Zooms out to the helicopter diagonally when in 3rd person view.
N	Zooms in to the helicopter diagonally when in 3rd person view.
L	Moves the camera in the upward in the z direction when in 3rd person view.
K	Moves the camera down in the z redirection in 3rd person view.
J	Move the camera away from the helicopter in the y direction in 3rd person view.
H	Moves the camera towards the helicopter in the y direction in 3rd person view.
G	Moves the camera away in the x direction in 3rd person view.
F	Moves the camera towards the helicopter in the x direction in 3rd person view.
O	Changes the force input of the arrow keys controls both helicopter 1 and 2. Helicopter 2 will only follow 1 if it had the same yaw and velocities prior to pressing the key.
R	Pick up an object for helicopter 1 when it is within a certain distance.From it
T	Pick up an object for helicopter 2 when it is within a certain distance from it.
*/

// 3D graphics window size in pixels
int WIDTH_MIN = 0;
int HEIGHT_MIN = 0;
int WIDTH_MAX = 800; 
int HEIGHT_MAX = 600;

// background colour for the scene
float BACK_R = 0.0f; // red colour component (0 to 1)
float BACK_G = 0.0f; // green colour component (0 to 1)
float BACK_B = 0.0f; // blue colour component (0 to 1)

double VMIN = 0.25; 
double VMAX = 1000.0;

using namespace std;

const double PI = atan(1) / 4;

ofstream fout("debug.txt");
ofstream sout("simulation.csv");

//tried making a .cpp and .h file for the World class, but kept getting errors, so we put it in the 3d graphics function.

class World
{
	environment *map; //create an environment map
	helicopter *Helis[2]; //create a helicopter array of 2
	double points; //current number of points
	Object *objects[4]; //number of objects/monkeys to pickup
	mesh *goal; //mesh for the goal

public:

	int n; //number of helicopters
	World(int N); 
	~World();
	void draw_players(); //function to render the helicopters
	void draw_map(); //function to render the map
	void calculate(); //function that iterates the position of the helicopters
	void force(); //function to obtain the force input
	void set_view_game(); //set the perspective view
	void display(); //display the text
	void draw_goal(); //function to rnder the goal
	void draw_object(); //function to render the monkeys/objects
	int collision(); //function to detect the collision between players (helicoptres)
	int pickup1(); //function for the first player to pick up a monkey/object
	int pickup2(); //function for the second player to pick up a monkey/object
	int addpoints(); //function to add points when a monkey/object is brought to the goal
};

World::World(int N) //initialize the member variables of the game
{
	int i;

	if (N > 2)
	{
		fout << "\nError, too many players.";
		n=2; //can't have more than 2 helis.
	}
	else
	{
		n = N;
	}
	static long int s = -15;

	objects[0] = new Object("Monkey.x", 10.0, 1);
	objects[1] = new Object("Monkey2.x", 10.0, 1);
	objects[2] = new Object("Monkey.x", 10.0, 1);
	objects[3] = new Object("Monkey2.x", 10.0, 1);

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

	goal = new mesh("helipad.x");
	sout << "t,xc,yc,psi,u,v,r\n";

	map = new environment("track1.x");
	points = 0;
}

World::~World() //destructor
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

	if (goal != NULL)
	{
		delete goal;
		goal = NULL;
	}
	else cout << "\nError, attempted to delete a NULL Pointer.";

	if (map != NULL)
	{
		delete map;
		map = NULL;
	}
	else cout << "\nError, attempted to delete a NULL Pointer.";

}

int World::collision() //collision equation between helicopter 1 and 2
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
					ans = 1;
					return ans;
				}

			}
		}
		return ans;
	}
	return ans;

}

void World::display() //dislay the text 
{
	int i, j;
	double X1, X2, Y1, Y2, R1, R2, d;
	text_xy("Number of players: ", 10, 10);
	text_xy(n, 175, 10);

	text_xy("Number of Packages Remaining: ", 10, 40);
	text_xy((4-points), 295, 40);
	/*
	text_xy("Velocity x of player 1: ", 10, 70);
	text_xy(Helis[0]->get_X(4), 200, 70);
	text_xy("Velocity y of player 1: ", 10, 100);
	text_xy(Helis[0]->get_X(5), 200, 100);
	text_xy("Radial velocity of player 1: ", 10, 130);
	text_xy(Helis[0]->get_X(6), 235,130);
	*/

	text_xy("Player 1", 10, 500);
	text_xy("Vx: ", 10, 520);
	text_xy(Helis[0]->get_X(4), 40, 520);
	text_xy("Vy: ", 150, 520);
	text_xy(Helis[0]->get_X(5), 180, 520);
	text_xy("Vr: ", 290, 520);
	text_xy(Helis[0]->get_X(6), 320, 520);

	if (n > 1)
	{/*
		text_xy("Velocity x of player 2: ", 10, 160);
		text_xy(Helis[1]->get_X(4), 200, 160);
		text_xy("Velocity y of player 2: ", 10, 190);
		text_xy(Helis[1]->get_X(5), 200, 190);
		text_xy("Radial velocity of player 2: ", 10, 220);
		text_xy(Helis[1]->get_X(6), 235, 220);
		*/

		text_xy("Player 2", 10, 550);
		text_xy("Vx: ", 10, 570);
		text_xy(Helis[1]->get_X(4), 40, 570);
		text_xy("Vy: ", 150, 570);
		text_xy(Helis[1]->get_X(5), 180, 570);
		text_xy("Vr: ", 290, 570);
		text_xy(Helis[1]->get_X(6), 320, 570);

		for (i = 0; i < n; i++) //just in case there's more than 3 helicopters for the future
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

				if ((R1+R2)< d && d < 3*(R1+R2))
				{
					text_xy("COLLISION ABOUT TO OCCUR", 50, 250, 30);
				}
			}
		}
	}
	//text_xy("Player 1", Helis[0]->get_X(1), Helis[0]->get_X(2));
}

void World::draw_players() //draw helicopter 1 and 2 if n>1
{
	int i;

	for (i = 0; i < n; i++)
	{
		Helis[i]->draw_heli();
	}
}


void World::set_view_game() //set the view for the games. Can alternate between heli 1 or 2 by pressing p
{
	static double t, dt, tp;
	if (n > 1)
	{
		static int flag = -1;
		//default is helicopter -1

		if (KEY('P'))
		{
			t = high_resolution_time();
			dt = t - tp;

			// guard against too frequent toggle
			if (dt > 1)
			{
				tp = t;
				flag *= -1;
			}

		}
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

void World::draw_goal() //draw the goal where the objets have to be brought to
{
	goal->Scale = 1.0;
	goal->draw(0.0, 0.0, -2, 0.0, 0.0, 0.0);
}

void World::draw_map() //draw the mesh background of the program
{
	map->draw_backgorund();
}
void World::calculate() //calculate the updated position with Euler equation
{
	int i;
	for (i = 0; i < n; i++)
	{
		Helis[i]->calculate();
	}
}

void World::force() //force inputs for helicopter 1 and 2
{
	static int flag = -1;
	static double dt;
	static double t, tp;
	if (n > 1)
	{
		if (KEY('O'))
		{
			t = high_resolution_time();
			dt = t - tp;

			// guard against too frequent toggle
			if (dt > 1)
			{
				tp = t;
				flag *= -1;
			}

		} //pressing O will control the two helicopters with the arrow keys (good to prevent collision)
		
		if (flag < 0)
		{
			Helis[0]->force_input();
			Helis[1]->force_input2();
		}
		else
		{
			Helis[0]->force_input();
			Helis[1]->force_input();
		}
	}
	else
	{
		Helis[0]->force_input();
	}

}

void World::draw_object() //draw all the objects that have to be collected
{
	int i;
	for (i = 0; i < 4; i++)
	{
		objects[i]->draw();
	}
}

int World::pickup1() //pickup function for helicopter 1
{
	int i, j;
	int ans;
	double X1, X2, Y1, Y2, R1, R2, d;
	ans = 0;
	static int flag = -1;
	static double t, tp, dt;

	X1 = Helis[0]->get_X(1);
	Y1 = Helis[0]->get_X(2);
	R1 = Helis[0]->R;

	for (j = 0; j < 4; j++)
	{
		X2 = objects[j]->get_P(1);
		Y2 = objects[j]->get_P(2);
		R2 = objects[i]->get_R();

		d = (X1 - X2)*(X1 - X2) + (Y1 - Y2)*(Y1 - Y2);
		d = sqrt(d);

		if (d < (R1 + R2))
		{
			if (KEY('R'))
			{
				t = high_resolution_time();
				dt = t - tp;

				if (dt > 0.5)
				{
					tp = t;
					flag *= -1;
				}
			
			}
			if (flag > 0)
			{
				text_xy("Object picked up by helicopter 1, bring it to the helipad.", 150, 100);
				objects[j]->get_P(1) = Helis[0]->get_X(1);
				objects[j]->get_P(2) = Helis[0]->get_X(2);
			}
			ans = 1;
			return ans;
		}
	}
	ans = 0;
	return ans;
}

int World::pickup2() //pickup function for helicopter 2
{
	if (n < 2) return 0; //only works if there's 2 helicopters

	int i, j;
	int ans;
	double X1, X2, Y1, Y2, R1, R2, d;
	ans = 0;
	static int flag = -1;
	static double t, tp, dt;

	X1 = Helis[1]->get_X(1);
	Y1 = Helis[1]->get_X(2);
	R1 = Helis[1]->R;


	for (j = 0; j < 4; j++)
	{
		X2 = objects[j]->get_P(1);
		Y2 = objects[j]->get_P(2);
		R2 = objects[i]->get_R();

		d = (X1 - X2)*(X1 - X2) + (Y1 - Y2)*(Y1 - Y2);
		d = sqrt(d);

		if (d < (R1 + R2))
		{
			if (KEY('T'))
			{
				t = high_resolution_time();
				dt = t - tp;

				if (dt > 0.5)
				{
					tp = t;
					flag *= -1;
				}
			}
			if (flag > 0)
			{
				text_xy("Object picked up by helicopter 2, bring it to the helipad.", 150, 150);
				objects[j]->get_P(1) = Helis[1]->get_X(1);
				objects[j]->get_P(2) = Helis[1]->get_X(2);
			}
			ans = 1;
			return ans;
		}

	}


}

int World::addpoints()
{
	int j;

	if (points == 4)
	{
		return 1;
	}

	for (j = 0; j < 4; j++)
	{
		if (fabs(objects[j]->get_P(1)) < 5.0 && fabs(objects[j]->get_P(2)) < 5.0)
		{
			points++;
			objects[j]->get_P(1) = 1000; //move the object away from the goal
			objects[j]->get_P(2) = 1000;

			if (points == 4)
			{
				return 1;
			}

		}

	}

	return 0;
}

void draw_3D_graphics()
{	
	static World W(2);
	static Timer timer(0, 4, 20, 125);
	static int init;
	static int player;
	static int start = 0;

	
	W.set_view_game();

	W.force();
	W.draw_map();
	W.calculate();
	draw_XYZ(5.0);
	W.display();
	W.draw_players();
	W.draw_goal();
	W.draw_object();
	W.pickup1();
	W.pickup2();

	
	timer.print_time();
	timer.update_timer();

	if (W.collision())
	{
		text_xy("GAME OVER, COLLISION OCCURED!", 50, 250, 30);
		text_xy("PRESS ESC TO EXIT PROGRAM!", 50, 300, 30);
		Sleep(5000);
	}

	if (W.addpoints())
	{
		text_xy("GAME COMPLETE,YOU WIN!", 50, 250, 30);
		text_xy("PRESS ESC TO EXIT PROGRAM!", 50, 300, 30);
		Sleep(5000);
	}

	if (timer.current_time() == 0)
	{
		text_xy("GAME OVER, TIME IS UP!", 140, 250, 30);
		text_xy("PRESS ESC TO EXIT PROGRAM!", 80, 300, 30);
		Sleep(2000);
	}


// formula sheet functions:
//
//  high_resolution_time();
//	static mesh m1("tiger.x");
//	set_view();	
//	set_2D_view(5.0,5.0); // comment out if using set_view function
//	draw_XYZ(5.0);
//	t = high_resolution_time() - t0; 
//	m1.draw(Px,Py,Pz,yaw,pitch,roll);
//	if( KEY(VK_UP) ) z += dz;

}

