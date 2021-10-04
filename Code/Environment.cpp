#include <iostream>
#include <windows.h> 
#include "3D_graphics.h" 
#include "functions.h"
#include "ran.h"
#include "Environment.h"

using namespace std;

//function to draw the environment
//the environment is set at z=-2 so that the spacing of the objects can be placed at z=0
void environment::draw_backgorund()
{
	background->draw(0.0, 0.0, -2, 0.0, 0.0, 0.0);
}

//constructor that creates a mesh pointer object for the background with a given file name
environment::environment(char file_name[])
{
	background = new mesh(file_name); 
}

//destructor that removes the background pointer
environment::~environment()
{
	if (!background)
	{
		delete background;
		background = NULL;
	}
	else 
	{
		cout << "\nError trying to delete background mesh pointer.";
	}
}

