#include <iostream>
using namespace std;

class Object
{
	mesh *obj;
	double *P;
	double R;
	double S;
public:
	Object(char file_name[], double R, double scale);
	~Object();
	void draw();
	double get_R();
	double & get_P(int i);
};