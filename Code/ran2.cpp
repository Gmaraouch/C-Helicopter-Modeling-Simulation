
// The following routines are from the book "Numerical Recipes in C" 
// -- this book has many other useful numerical functions along with
// c++ code for them in files.

#include "ran.h"

#define IM1 2147483563
#define IM2 2147483399
#define AM2 (1.0/IM1)
#define IMM1 (IM1-1)
#define IA1 40014
#define IA2 40692
#define IQ1 53668
#define IQ2 52774
#define IR1 12211
#define IR2 3791
#define NTAB 32
#define NDIV (1+IMM1/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)

double ran2(long int &id)
{
	int j;
	long k;
	static long idum2=123456789;
	static long iy=0;
	static long iv[NTAB];
	double temp;

	if (id <= 0) {
		if (-id < 1) id=1;
		else id = -id;
		idum2=id;
		for (j=NTAB+7;j>=0;j--) {
			k=id/IQ1;
			id=IA1*(id-k*IQ1)-k*IR1;
			if (id < 0) id += IM1;
			if (j < NTAB) iv[j] = id;
		}
		iy=iv[0];
	}
	k=id/IQ1;
	id=IA1*(id-k*IQ1)-k*IR1;
	if (id < 0) id += IM1;
	k=idum2/IQ2;
	idum2=IA2*(idum2-k*IQ2)-k*IR2;
	if (idum2 < 0) idum2 += IM2;
	j=iy/NDIV;
	iy=iv[j]-idum2;
	iv[j] = id;
	if (iy < 1) iy += IMM1;
	if ((temp=AM2*iy) > RNMX) return RNMX;
	else return temp;
}

#undef IM1
#undef IM2
#undef AM2
#undef IMM1
#undef IA1
#undef IA2
#undef IQ1
#undef IQ2
#undef IR1
#undef IR2
#undef NTAB
#undef NDIV
#undef EPS
#undef RNMX
