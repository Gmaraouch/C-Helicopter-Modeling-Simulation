
// rotation functions

#include <cmath>   // math functions
#include <cstdio>  // standard I/O functions
#include <cstring> // string manipulation functions

#include <iostream>  // console stream I/O
#include <fstream>   // file stream I/O
#include <strstream> // string stream I/0
#include <iomanip>   // I/O manipulators

using namespace std;

// rotation functions header
#include "rotation.h"

void multiply_Ax(double A[3+1][3+1], double x[3+1], double b[3+1])
// multiply a matrix times a vector, b = A*x
{
	int i,j;
	
	for(i=1;i<=3;i++) {
		b[i] = 0.0;
		for(j=1;j<=3;j++) {
			b[i] += A[i][j]*x[j];
		}
	}

}


void multiply_AB(double A[3+1][3+1], double B[3+1][3+1], double C[3+1][3+1])
// multiply two 3x3 matrices, C = A*B
{
	int i,j,k;
	double sum;

	for(i=1;i<=3;i++) {
		for(j=1;j<=3;j++) {
			sum = 0.0;
			for(k=1;k<=3;k++) {
				sum += A[i][k] * B[k][j];
			}
			C[i][j] = sum;
		}
	}

}


void x_rotation(double R[3+1][3+1], double u)
// R - 3x3 rotation matrix, P = R*p
// P - global co-ordinate
// p - local co-ordinate
// angle - rotation angle
{
	// column #1
	R[1][1] = 1.0;
	R[2][1] = 0.0;
	R[3][1] = 0.0;
	// column #2
	R[1][2] = 0.0;
	R[2][2] = cos(u);
	R[3][2] = sin(u);
	// column #3
	R[1][3] = 0.0;
	R[2][3] = -sin(u);
	R[3][3] = cos(u);
}


void y_rotation(double R[3+1][3+1], double u)
// R - 3x3 rotation matrix, P = R*p
// P - global co-ordinate
// p - local co-ordinate
// angle - rotation angle
{
	// column #1
	R[1][1] = cos(u);
	R[2][1] = 0.0;
	R[3][1] = -sin(u);
	// column #2
	R[1][2] = 0.0;
	R[2][2] = 1.0;
	R[3][2] = 0.0;
	// column #3
	R[1][3] = sin(u);
	R[2][3] = 0.0;
	R[3][3] = cos(u);
}


void z_rotation(double R[3+1][3+1], double u)
// R - 3x3 rotation matrix, P = R*p
// P - global co-ordinate
// p - local co-ordinate
// u - rotation angle
{
	// column #1
	R[1][1] = cos(u);
	R[2][1] = sin(u);
	R[3][1] = 0.0;
	// column #2
	R[1][2] = -sin(u);
	R[2][2] = cos(u);
	R[3][2] = 0.0;
	// column #3
	R[1][3] = 0.0;
	R[2][3] = 0.0;
	R[3][3] = 1.0;
}


void euler_to_rotation(double yaw, double pitch, double roll,
					   double R[3+1][3+1])
// R - 3x3 rotation matrix, P = R*p
// P - global co-ordinate
// p - local co-ordinate
// yaw (heading, psi)
// pitch (attitude, theta)
// roll (bank, phi)
{
	static double c_psi, c_th, c_phi; // cos of angles
	static double s_psi, s_th, s_phi; // sin of angles

	// calculate some trig functions
	c_psi = cos(yaw);
	c_th  = cos(pitch);
	c_phi = cos(roll);
	s_psi = sin(yaw);
	s_th  = sin(pitch);
	s_phi = sin(roll);

	// column #1
	R[1][1] = c_th*c_psi;
	R[2][1] = c_th*s_psi;
	R[3][1] = -s_th;

	// column #2
	R[1][2] = s_phi*s_th*c_psi - c_phi*s_psi;
	R[2][2] = s_phi*s_th*s_psi + c_phi*c_psi;
	R[3][2] = s_phi*c_th;

	// column #3
	R[1][3] = c_phi*s_th*c_psi + s_phi*s_psi;
	R[2][3] = c_phi*s_th*s_psi - s_phi*c_psi;
	R[3][3] = c_phi*c_th;
}


void rotation_to_euler(double R[3+1][3+1], 
					double &yaw, double &pitch, double &roll)
// calculate euler angles from a rotation matrix
// R - 3x3 rotation matrix, P = R*p
// P - global co-ordinate
// p - local co-ordinate
// yaw (heading, psi)
// pitch (attitude, theta)
// roll (bank, phi)
{
	yaw  = atan2(R[2][1],R[1][1]);

	pitch = atan2( -R[3][1],
		sqrt( R[3][2]*R[3][2] + R[3][3]*R[3][3] ) );

	roll   = atan2(R[3][2],R[3][3]);
}


void euler_to_quaternion(double yaw, double pitch, double roll,
	double &e0, double &e1, double &e2, double &e3)
// yaw (heading, psi)
// pitch (attitude, theta)
// roll (bank, phi)
// e0, e1, e2, e3 - quaternions (euler parameters)
{
	static double c_psi, c_th, c_phi; // cos of angles
	static double s_psi, s_th, s_phi; // sin of angles

	// calculate some trig functions
	c_psi = cos(yaw/2.0);
	c_th  = cos(pitch/2.0);
	c_phi = cos(roll/2.0);
	s_psi = sin(yaw/2.0);
	s_th  = sin(pitch/2.0);
	s_phi = sin(roll/2.0);

	// calculate quaternions
	// see Simulink aerospace block set for details
	e0 = c_phi*c_th*c_psi + s_phi*s_th*s_psi;
	e1 = s_phi*c_th*c_psi - c_phi*s_th*s_psi;
	e2 = c_phi*s_th*c_psi + s_phi*c_th*s_psi;
	e3 = c_phi*c_th*s_psi - s_phi*s_th*c_psi;
	// note there is a small typo in the aerospace 
	// block set page, the last term in e3 is c_psi
}


void rotation_to_quaternion(double R[3+1][3+1],
	double &e0, double &e1, double &e2, double &e3)
// R - 3x3 rotation matrix, P = R*p
// e0, e1, e2, e3 - quaternions (euler parameters)
{
	double yaw, pitch, roll; // euler angles

	// convert the rotation matrix to euler angles
	rotation_to_euler(R,yaw,pitch,roll);

	// convert the euler angles to quaternions
	euler_to_quaternion(yaw,pitch,roll,e0,e1,e2,e3);
}


void quaternion_to_rotation(double e0, double e1, double e2,
		double e3, double R[3+1][3+1])
{
	// column #1
	R[1][1] = e0*e0 + e1*e1 - e2*e2 - e3*e3;
	R[2][1] = 2*(e1*e2 + e0*e3);
	R[3][1] = 2*(e1*e3 - e0*e2);

	// column #2
	R[1][2] = 2*(e1*e2 - e0*e3);
	R[2][2] = e0*e0 - e1*e1 + e2*e2 - e3*e3;
	R[3][2] = 2*(e2*e3 + e0*e1);

	// column #3
	R[1][3] = 2*(e1*e3 + e0*e2);
	R[2][3] = 2*(e2*e3 - e0*e1);
	R[3][3] = e0*e0 - e1*e1 - e2*e2 + e3*e3;
}


void quaternion_to_euler(double e0, double e1, double e2,
		double e3, double &yaw, double &pitch, double &roll)
{
	double R[3+1][3+1]; // rotation matrix

	// convert quaternions to a rotation matrix
	quaternion_to_rotation(e0,e1,e2,e3,R);

	// convert the rotation matrix to euler angles
	rotation_to_euler(R,yaw,pitch,roll);
}


void update_RT(double R1[3+1][3+1], double T1[3+1], double Re[3+1][3+1], double Te[3+1])
// update R and T using the following recursive relationship
// Te = T1 + R1*Te
// Re = R1*Re
// inputs: R1, T1, Re, Te
// outputs: Re, Te
{
	int i,j;
	double R2[3+1][3+1], T2[3+1];

	// copy R2 = Re, T2 = Te
	// this allows in place processing of Re, Te
	// so that the outputs (Re,Te) can also be the inputs
	for(i=1;i<=3;i++) {
		T2[i] = Te[i];
		for(j=1;j<=3;j++) {
			R2[i][j] = Re[i][j];
		}
	}

	// Te = T1 + R1*T2
	for(i=1;i<=3;i++) {
		Te[i] = 0.0; // initialize summation
		for(j=1;j<=3;j++) {
			Te[i] += R1[i][j] * T2[j];
		}
		Te[i] += T1[i];
	}

	// Re = R1*R2
	multiply_AB(R1,R2,Re);

}

void rt_transform(double R[3+1][3+1], double T[3+1],
				  double *x, double *y, double *z,
				  double *X, double *Y, double *Z, int n)
// rotational/translational transformation
// for a list of vectors, P = T + R*p
// x[n],y[n],z[n] - input vectors, p = (x,y,z)
// X[n],Y[n],Z[n] - output vectors, P = (X,Y,Z)
// n number of vectors (0 to n-1)
{
	int i;
	double xi,yi,zi; 

	for(i=0;i<n;i++) {

	// temp variables in case inputs are also the outputs
	xi = x[i];
	yi = y[i];
	zi = z[i];

	X[i] = T[1] + R[1][1]*xi + R[1][2]*yi + R[1][3]*zi;
	Y[i] = T[2] + R[2][1]*xi + R[2][2]*yi + R[2][3]*zi;
	Z[i] = T[3] + R[3][1]*xi + R[3][2]*yi + R[3][3]*zi;

	}
}

