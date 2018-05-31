#include "geometrfactor.h"

Geometrfactor::Geometrfactor(double x,double y,double z,double b, double l)
{
	X = x;
	Y = y;
	Z = z;
	Bz = b;
	Lz = l;
	GeocGeodez();
	calculateAE();
}

void Geometrfactor::GeocGeodez()
{
	double Lk,r,c,p,b,s1,s2;
	double D = sqrt(pow(X, 2) + pow(Y, 2));
	if (Y != 0)
	{
		L = 2 * atan(Y / (X + D)) + M_PI * (1 - Y / abs(Y));
	}
	else
	{
		if (X >= 0 && Y == 0)
		{
			L = 0;
		}
		else if (X < 0 && Y == 0)
		{
			L = M_PI;
		}

	}
	if (Z == 0)
	{
		B = 0;
	}
	else
	{
		r = sqrt(pow(X, 2) + pow(Y, 2) + pow(Z, 2));
		c = asin(Z / r);
		p = 0;
		s1 = 0;
		s2 = 0;
		b = c + s1;
		B = b;
	}

}

void Geometrfactor::calculateAE()
{
	H = sqrt(pow(X, 2) + pow(Y, 2) + pow(Z, 2));
	azimuth = atan(tan(Lz - L) / sin(Bz)) +  M_PI;
	altitude = atan(cos(Bz)*cos(Lz - L) - (R0 / (R0 + H)) / sqrt(1 - pow((cos(Bz)*cos(Lz - L)), 2)));
}


