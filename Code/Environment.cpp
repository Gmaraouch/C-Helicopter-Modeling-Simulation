#include <iostream>
using namespace std;

#include <windows.h> 

#include "3D_graphics.h" 
#include "functions.h"
#include "ran.h"
#include "Environment.h"


void environment::draw_backgorund()
{
	background->draw(0.0, 0.0, -2, 0.0, 0.0, 0.0);
}

environment::environment(char file_name[])
{
	background = new mesh(file_name); 
}

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

