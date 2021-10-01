#include <iostream>
using namespace std;


// A mesh object can draw a 3D rigid body object stored in an x-file.
// you can translate and rotate this rigid body.
// this type of graphics is useful for anamimating machines
// or multiple machines.
class mesh {

	// for internal use
	int Mesh_number;

public:

	// initial transformation (default = 0.0).
	// this allows the object to be given some
	// initial position and orientation.
	double Roll_0, Pitch_0, Yaw_0;
	double X_0, Y_0, Z_0;

	// scaling/size of mesh (default = 1.0).
	// this allows the size of the mesh to be changed.
	// note: scaling occurs around the origin
	// after the initial transformation.
	double Scale;

	// a constructor that loads an x-file
	mesh(char file_name[]);

	// draw the mesh in the 3D view port
	// with a global translation of (Tx,Ty,Tz) - in a global frame of ref.
	// a rotation of (yaw,pitch,roll)
	// - yaw is rotation along the compass direction (NSEW)
	// - pitch is the nose rotation up or down
	// - roll is a barell roll
	void draw(double Tx, double Ty, double Tz, double yaw, double pitch, double roll);

};


// global variable to store keyboard input
extern unsigned char Key_input[256];

// check if key c is currently pressed
// note that multiple keys can be pressed at once
#define KEY(c) ( GetAsyncKeyState((int)(c)) & (SHORT)0x8000 )

//////////////// related graphics functions /////////////////

// draw one frame of animation
void draw_3D_graphics();

// change the eye_point using the keyboard
void set_view();

void draw_XYZ(double len);
// draw the XYZ Axes 
// len - length of the axes

void set_2D_view(double width, double height, int flag = 1);
// set the view and projection transform matrices to a 2D View (X-Y coordinates)
// width - width of the window in global coordinates
// height - height of the window in global coordinates
// flag 
// 1 - X-Y coordinates
// 2 - X-Z coordinates
// 3 - Y-Z coordinates

void set_view(double *eye_point, double *lookat_point, double *up_dir, double fov=3.14159/4);
// sets the view and perspective matrices
// eye_point[1] - x component of eye location
// eye_point[2] - y component of eye location
// eye_point[3] - z component of eye location
// lookat_point[1] - x component of look at point
// lookat_point[2] - y component of look at point
// lookat_point[3] - z component of look at point
// up_dir[1] - x component of up direction
// up_dir[2] - y component of up direction
// up_dir[3] - z component of up direction
// fov - field of view (45 deg default)

void set_light(int light_number, double dir_x, double dir_y, double dir_z,
               double R, double G, double B, int light_switch);
// Sets a directional light for the scene
// Note that many lights may be active at a time 
// (but each one slows down the rendering of our scene)
// light_number - number of the light, calling this function with the same number will
// overwrite the current setting
// dir_x - x component of the light direction
// dir_y - y component of the light direction
// dir_z - z component of the light direction
// R - Red colour components (0<=R<=1) of the light
// G - Green colour components (0<=G<=1) of the light
// B - Blue colour components (0<=B<=1) of the light
// light_switch - set equal to zero to turn off the light, non-zero to turn it on

void text_xy(char *str, double x, double y, int size = 14);
// place 2D text at pixel location (x,y)
// str - text string
// x - x pixel location of text
// y - y pixel location of text
// size = font size of the text (default = 14)

void text_xy(double value, double x, double y, int size = 14);
// place 2D text at pixel location (x,y)
// value - number to print to the screen
// x - x pixel location of text
// y - y pixel location of text
// size = font size of the text (default = 14)