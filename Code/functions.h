#include <iostream>
#include <conio.h>

using namespace std;

void calculate_inputs(double X[], double t, int N, double U[], int M);
void calculate_Xd(double X[], double t, int N, double U[], int M, double Xd[]);
void sim_step(double dt, double X[7], double Xd[7]);