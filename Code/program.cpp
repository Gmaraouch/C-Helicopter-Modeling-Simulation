#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

#include "functions.h"


int main()
{
	const int N =6, M = 10;
	double X[N + 1], U[10 + 1], Xd[N + 1];
	double t, dt, tf=10;
	int i;

	ofstream fout;

	fout.open("assignment5.csv");

	if (!fout)
	{
		cout << "\nError opening the file.";
		_getch();
	}


	dt = 0.001;

	//initialize all the variables
	for (i = 1; i <= N; i++)
	{
		X[i] = 0.0;
		Xd[i] = 0.0;
	}
	X[1] = 1;
	X[2] = 1;
	X[3] = 0;
	for (i = 1; i <= M; i++)
	{
		U[i] = 0.0;
	}
	
	t = 0;
	fout << "t,xc,yc,psi,u,v,r\n";
	//cout << "t,xc,yc,psi,u,v,r\n";
	while (t < tf)
	{
		fout << t << ",";
		//cout << t;
		calculate_inputs(X, t, N, U, M);

		calculate_Xd(X, t, N, U, M, Xd);

		for (i = 1; i <= N; i++)
		{
			X[i] = X[i] + Xd[i]*dt;
			fout << X[i] << ",";
			//cout << X[i] << ",";
		}
		t += dt;
		if (t < tf)
		{
			fout << "\n";
			//cout << "\n";
		}
	}
	
	_getch();
	return 0;
}

