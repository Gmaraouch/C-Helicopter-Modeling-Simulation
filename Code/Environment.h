#include <iostream>
using namespace std;

//Class for the environment of the simulation
class environment

{
	mesh *background;
public:

	environment(char file_name[]);
	~environment();
	void draw_backgorund();
};