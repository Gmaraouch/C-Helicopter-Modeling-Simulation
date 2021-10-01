
// The following routines are from the book "Numerical Recipes in C" 
// -- this book has many other useful numerical functions along with
// c++ code for them in files.

#include "ran.h"

#define IA 16807
#define IM 2147483647
#define AM1 (1.0/IM)
#define IQ 127773
#define IR 2836
#define NTAB 32
#define NDIV (1+(IM-1)/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)

double ran(long int &id)
{
	int j;
	long k;
	static long iy=0;
	static long iv[NTAB];
	double temp;

	if (id <= 0 || !iy) {
		if (-id < 1) id=1;
		else id = -id;
		for (j=NTAB+7;j>=0;j--) {
			k=id/IQ;
			id=IA*(id-k*IQ)-IR*k;
			if (id < 0) id += IM;
			if (j < NTAB) iv[j] = id;
		}
		iy=iv[0];
	}
	k=id/IQ;
	id=IA*(id-k*IQ)-IR*k;
	if (id < 0) id += IM;
	j=iy/NDIV;
	iy=iv[j];
	iv[j] = id;
	if ((temp=AM1*iy) > RNMX) return RNMX;
	else return temp;
}

#undef IA
#undef IM
#undef AM1
#undef IQ
#undef IR
#undef NTAB
#undef NDIV
#undef EPS
#undef RNMX
