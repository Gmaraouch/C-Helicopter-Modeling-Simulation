
#include <cmath> 
#include <cstdio>  
#include <cstring>
#include <iostream> 
#include <fstream>   
#include <strstream> 
#include <iomanip> 

#include <windows.h> 
#include "functions.h"

extern ofstream sout;

//calculate the force input
void calculate_inputs(double X[], double t, int N, double U[], int M)
{
	//parameters
	const double m = 8.2;
	const double Izz = 0.28;
	const double l_tr = 0.91;
	const double rho_a = 1.0;
	const double S_fus_x = 0.1;
	const double S_fus_y = 0.22;
	const double k_mr_x = -0.3;
	static double Tmr=0, Ttr=0;

	U[1] = Tmr;
	U[2] = Ttr;
}

//calculate the derivatives
void calculate_Xd(double X[], double t, int N, double U[], int M, double Xd[])
{
	const double m = 8.2;
	const double Izz = 0.28;
	const double l_tr = 0.91;
	const double rho_a = 1.0;
	const double S_fus_x = 0.1;
	const double S_fus_y = 0.22;
	const double k_mr_x = -0.3;

	//copy the position of the helicopter
	double x = X[1];
	double y = X[2];
	double psi = X[3];
	double u = X[4];
	double v = X[5];
	double r = X[6];

	//copy the torque input of the helicopter
	double Tmr = U[1];
	double Ttr = U[2];

	double u_w = u/4;
	double v_w = u/4;

	//calculate the variables needed for the derivative computation
	double u_a = u - u_w;
	double v_a = v - v_w;
	double V_inf = sqrt(u_a*u_a + v_a*v_a);
	double Xfus = -0.5*rho_a*S_fus_x*u_a*V_inf;
	double Yfus = -0.5*rho_a*S_fus_y*v_a*V_inf;
	double Ymr = -k_mr_x*Tmr;
	double Xmr = -k_mr_x*Tmr;
	double Ytr = 0.0;
	double Ntr = -Ttr*l_tr;
	double Nfus = 0;
	double Yvf = 0;
	double Nvf = 0;
	double Qe = r;

	//calcualte the derivatives
	double xd = u*cos(psi) - v*sin(psi);
	double yd = u*sin(psi) + v*cos(psi);
	double psid = r;
	double ud = v*r + (Xmr + Xfus) / m;
	double vd = -u*r + (Ymr + Yfus + Ytr + Yvf) / m;
	double rd = (-Qe + Nvf + Ntr + Nfus) / Izz;

	//copy the derivatives into the array of double Xd
	Xd[1] = xd;
	Xd[2] = yd;
	Xd[3] = psid;
	Xd[4] = ud;
	Xd[5] = vd;
	Xd[6] = rd;

}

//perform a time step (Euler method)
void sim_step(double dt, double X[7], double Xd[7])
{
	int i;

	for (i = 1; i < 7; i++)
	{
		sout << X[i] << ",";
		X[i] += Xd[i] * dt;
	}
	sout << "\n";
}